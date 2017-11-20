import PythonWrapper as pw
import timeit, sys, os, glob, csv, math

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
    '#Open the random generated data file'
    path = os.getcwd() + '/script'

    '#Open file 1'
    fileOne = glob.glob(os.path.join(path, (sys.argv[1] + '.csv')))

    #with open(fileOne[0], 'r') as f:
        #print(f.read())
    vectorList = []
    with open(fileOne[0], 'r') as f:
        reader = list(csv.reader(f))
        items_to_list = len(reader)
        num_vectors = math.ceil(len(reader) / nslots)
        for i in range(num_vectors):
            vectorList.append(pw.pyvector())

            if items_to_list > nslots:
                for row in reader[i*nslots:(i+1)*nslots]:
                    vectorList[i].append(int("".join(row)))
                items_to_list -= nslots
            else:
                for row in reader[i*nslots:]:
                    vectorList[i].append(int("".join(row)))

    vectorListTwo = []
    with open(fileTwo[0], 'r') as f:
        reader = list(csv.reader(f))
        items_to_list = len(reader)
        num_vectors = math.ceil(len(reader) / nslots)
        for i in range(num_vectors):
            vectorListTwo.append(pw.pyvector())

            if items_to_list > nslots:
                for row in reader[i*nslots:(i+1)*nslots]:
                    vectorListTwo[i].append(int("".join(row)))
                items_to_list -= nslots
            else:
                for row in reader[i*nslots:]:
                    vectorListTwo[i].append(int("".join(row)))




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
