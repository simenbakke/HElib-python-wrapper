import PythonWrapper as pw

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

    m = pw.FindM(k,L,c,p,d,s,0, False)

    #initialize context
    context = pw.FHEcontext(m, p, r, a, b)
    #modify the context
    pw.buildModChain(context, L, c, 0)

    secretKey = pw.FHESecKey(context)
    publicKey = pw.FHESecKey(context)

    print("Secretkey", secretKey)

    G = context.alMod.getFactorsOverZZ()[0]

    print("G = ", G)
    print ("context =", context)
    secretKey.GenSecKey(w, 0, 3)

    pw.addSome1DMatrices(secretKey, 100, 0)
    print ("Key generated")

    ea = pw.EncryptedArray(context, G)
    print ("EncryptedArray generated")

    v1 = pw.pyvector()
    for i in range (0, 288):
        v1.append(i*2)
    #print (v1[100])

    ctxt1 = pw.Ctxt(publicKey, 0)
    print("Encryptes parameters = ", ctxt1, publicKey, v1)
    ea.encrypt(ctxt1, publicKey, v1)



    ctxt2 = pw.Ctxt(publicKey, 0)

if __name__ == "__main__":
    test()
