import PythonWrapper as pw
import sys

def test():
    m = 7781
    p = 2
    r = 1
    L = 6
    c = 2
    w = 64
    d = 1
    k = 80
    s = 0
    a = pw.pyvector()
    b = pw.pyvector()

    m = pw.FindM(k,L,c,p,d,s,0, False)

    #initialize context
    context = pw.FHEcontext(m, p, r, a, b)
    #modify the context
    pw.buildModChain(context, L, c, 0)

    secretKey = pw.FHESecKey(context)
    publicKey = secretKey


    if(d == 0):
        G = context.alMod.getFactorsOverZZ()[0]
    else:
        G = pw.makeIrredPoly(p, d)

    #print("G = ", G)
    #print ("context =", context)
    secretKey.GenSecKey(w, 0, 3)

    pw.addSome1DMatrices(secretKey, 100, 0)
    #print("keyExists = ", publicKey.keyExists(0))

    print ("Key generated")

    ea = pw.EncryptedArray(context, G)
    print ("EncryptedArray generated")
    #print (pw.pyvector(G))

    nslots = ea.size()
    print("nslots = ", nslots)
    p0 = pw.NewPlaintextArray(ea)
    p1 = pw.NewPlaintextArray(ea)
    p2 = pw.NewPlaintextArray(ea)
    p3 = pw.NewPlaintextArray(ea)

    pw.random(ea, p0)
    pw.random(ea, p1)
    pw.random(ea, p2)
    pw.random(ea, p3)

    c0 = pw.Ctxt(publicKey,0)
    c1 = pw.Ctxt(publicKey,0)
    c2 = pw.Ctxt(publicKey,0)
    c3 = pw.Ctxt(publicKey,0)

    ea.encrypt_plaintext(c0, publicKey, p0)
    ea.encrypt_plaintext(c1, publicKey, p1)
    ea.encrypt_plaintext(c2, publicKey, p2)
    ea.encrypt_plaintext(c3, publicKey, p3)

    #for i in range (0, r):

    shamt = pw.RandomBnd((int((2*(nslots/2) + 1) - (nslots/2))))
    rotamt = pw.RandomBnd((2*(nslots-2) - 1 - (nslots-2)))

    const1 = pw.NewPlaintextArray(ea)
    const2 = pw.NewPlaintextArray(ea)

    pw.random(ea, const1)
    pw.random(ea, const2)

    const1_poly = pw.ZZX()
    const2_poly = pw.ZZX()

    ea.encode(const1_poly, const1)
    ea.encode(const2_poly, const2)


    #Multiply c1 by c0
    pw.mul(ea, p1, p0)
    c1.multiplyBy(c0)
    pw.CheckCtxt(c1, "c1*=c0")
    pw.debugCompare(ea,secretKey,p1,c1)

    #c0 += random constant
    pw.add(ea, p0, const1)
    c0.addConstant(const1_poly, -1)
    pw.CheckCtxt(c0, "c0+=k1")
    pw.debugCompare(ea,secretKey,p0,c0)

    #c2 *= random constant
    pw.mul(ea, p2, const2)
    c2.multByConstant(const2_poly, -1)
    pw.CheckCtxt(c2, "c2*=k2")
    pw.debugCompare(ea, secretKey, p2,c2)

    c0.cleanUp()
    c1.cleanUp()
    c2.cleanUp()

    pp0 = pw.NewPlaintextArray(ea)
    pp1 = pw.NewPlaintextArray(ea)
    pp2 = pw.NewPlaintextArray(ea)
    pp3 = pw.NewPlaintextArray(ea)

    ea.decrypt_plaintext(c0, secretKey, pp0)
    ea.decrypt_plaintext(c1, secretKey, pp1)
    ea.decrypt_plaintext(c2, secretKey, pp2)
    ea.decrypt_plaintext(c3, secretKey, pp3)

    if (pw.equals(ea, pp0, p0) and pw.equals(ea, pp1, p1) and pw.equals(ea, pp2, p2) and pw.equals(ea, pp3, p3)):
        print("GOOD ")
    else:
        print("BAD")



if __name__ == "__main__":
    test()
