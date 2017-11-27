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
    fileTwo = glob.glob(os.path.join(path, (sys.argv[2] + '.csv')))

    #with open(fileOne[0], 'r') as f:
        #print(f.read())
    ptxtListOne = []
    ctxtListOne = []
    with open(fileOne[0], 'r') as f:
        reader = list(csv.reader(f))
        items_to_list = len(reader)
        num_vectors = math.ceil(len(reader) / nslots)
        for i in range(num_vectors):
            vector = pw.pyvector()

            if items_to_list > nslots:
                for row in reader[i*nslots:(i+1)*nslots]:
                    vector.append(int("".join(row)))
                items_to_list -= nslots
            else:
                for row in reader[i*nslots:]:
                    vector.append(int("".join(row)))
                if len(vector) < nslots:
                    filler = nslots - len(vector)
                    for i in range(filler):
                        vector.append(0)

            plainText = pw.NewPlaintextArray(ea)
            cipherText = pw.Ctxt(publicKey, 0)
            pw.encodePtxtVec(ea, plainText, vector)
            ea.encryptPtxt(cipherText, publicKey, plainText)
            ptxtListOne.append(plainText)
            ctxtListOne.append(cipherText)

    ptxtListTwo = []
    ctxtListTwo = []
    with open(fileTwo[0], 'r') as f:
        reader = list(csv.reader(f))
        items_to_list = len(reader)
        num_vectors = math.ceil(len(reader) / nslots)
        for i in range(num_vectors):
            vector = pw.pyvector()

            if items_to_list > nslots:
                for row in reader[i*nslots:(i+1)*nslots]:
                    vector.append(int("".join(row)))
                items_to_list -= nslots
            else:
                for row in reader[i*nslots:]:
                    vector.append(int("".join(row)))
                if len(vector) < nslots:
                    filler = nslots - len(vector)
                    for i in range(filler):
                        vector.append(0)

            plainText = pw.NewPlaintextArray(ea)
            cipherText = pw.Ctxt(publicKey, 0)
            pw.encodePtxtVec(ea, plainText, vector)
            ea.encryptPtxt(cipherText, publicKey, plainText)
            ptxtListTwo.append(plainText)
            ctxtListTwo.append(cipherText)

    """Multiply the plaintext and ciphertext, then debugCompare decrypts to
    see if the result is correct"""
    for i in range(len(ptxtListOne)):
        pw.mul(ea, ptxtListOne[i], ptxtListTwo[i])
        ctxtListOne[i].multiplyBy(ctxtListTwo[i])
        pw.CheckCtxt(ctxtListOne[i], "ci*=c0")
        pw.debugCompare(ea, secretKey, ptxtListOne[i], ctxtListOne[i])




if __name__ == "__main__":
    start = timeit.default_timer()
    test()
    stop = timeit.default_timer()
    print ("Runtime = ", stop - start)
