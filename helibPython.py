import PythonWrapper as pw
import timeit

def test():
    m = 0
    p = 1021
    r = 1
    L = 16
    c = 3
    w = 64
    d = 0
    k = 128
    s = 0
    a = pw.pyvector()
    b = pw.pyvector()

    m = pw.FindM(k, L, c, p, d, s, 0, False)

    '#initialize context'
    context = pw.FHEcontext(m, p, r, a, b)
    '#modify the context'
    pw.buildModChain(context, L, c, 0)

    '#Construct a secret key'
    '#pubkey is a subclass of seckey'
    secretKey = pw.FHESecKey(context)
    publicKey = secretKey

    if(d == 0):
        G = context.alMod.getFactorsOverZZ()[0]
    else:
        G = pw.makeIrredPoly(p, d)

    '#Generate the secreykey'
    secretKey.GenSecKey(w, 0, 3)

    pw.addSome1DMatrices(secretKey, 100, 0)

    '#contrust an encrypted array object ea that is'
    '#associated with the given context and the polynomial G'
    ea = pw.EncryptedArray(context, G)

    nslots = ea.size()
    v1 = pw.pyvector()
    for i in range(0, nslots):
        v1.append(i*2)
    #print (v1[100])
    print(len(v1))
    ctxt1 = pw.Ctxt(publicKey, 0)

    #print(pw.Ctxt.isCorrect(ctxt1))
    #print("Encryptes parameters = ", ctxt1, publicKey, v1)
    ea.encrypt(ctxt1, publicKey, v1)

    v2 = pw.pyvector()
    ctxt2 = pw.Ctxt(publicKey, 0)

    for i in range(0, nslots):
        v2.append(i*3)
    ea.encrypt(ctxt2, publicKey, v2)

    ctSum = pw.Ctxt_sum(ctxt1, ctxt2)
    ctProd = pw.Ctxt_prod(ctxt1, ctxt2)

    res = pw.pyvector()
    ea.decrypt(ctSum, secretKey, res);

    #for i in range (0, len(res)):
        #print (v1[i], "+", v2[i], "=", res[i])
    #print ("eaBaseTag = ", ea.getTag())
    ea.decrypt(ctProd, secretKey, res)
    #for i in range (0, len(res)):
        #print (v1[i], "*", v2[i], "=", res[i])


    #ctxt2 = pw.Ctxt(publicKey, 0)

if __name__ == "__main__":
    start = timeit.default_timer()
    test()
    stop = timeit.default_timer()
    print ("Runtime = ", stop - start)
