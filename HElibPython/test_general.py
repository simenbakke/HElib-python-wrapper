from PythonWrapper import *

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
    a = pyvector()
    b = pyvector()

    m = FindM(k, L, c, p, d, s, 0)

    #initialize context
    context = FHEcontext(m, p, r, a, b)
    #modify the context
    buildModChain(context, L, c)

    secretKey = FHESecKey(context)
    publicKey = secretKey


    if(d == 0):
        G = context.alMod.getFactorsOverZZ()[0]
    else:
        G = makeIrredPoly(p, d)

    #print("G = ", G)
    #print ("context =", context)
    secretKey.GenSecKey(w)

    addSome1DMatrices(secretKey, 100, 0)
    #print("keyExists = ", publicKey.keyExists(0))

    #print ("Key generated")

    ea = EncryptedArray(context, G)
    #print ("EncryptedArray generated")
    #print (pyvector(G))

    nslots = ea.size()
    #print("nslots = ", nslots)
    p0 = NewPlaintextArray(ea)
    p1 = NewPlaintextArray(ea)
    p2 = NewPlaintextArray(ea)
    p3 = NewPlaintextArray(ea)

    random(ea, p0)
    random(ea, p1)
    random(ea, p2)
    random(ea, p3)

    c0 = Ctxt(publicKey)
    c1 = Ctxt(publicKey)
    c2 = Ctxt(publicKey)
    c3 = Ctxt(publicKey)

    ea.encrypt_plaintext(c0, publicKey, p0)
    ea.encrypt_plaintext(c1, publicKey, p1)
    ea.encrypt_plaintext(c2, publicKey, p2)
    ea.encrypt_plaintext(c3, publicKey, p3)

    #for i in range (0, r):

    shamt = RandomBnd((int((2*(nslots/2) + 1) - (nslots/2))))
    rotamt = RandomBnd((2*(nslots-2) - 1 - (nslots-2)))

    const1 = NewPlaintextArray(ea)
    const2 = NewPlaintextArray(ea)

    random(ea, const1)
    random(ea, const2)

    const1_poly = ZZX()
    const2_poly = ZZX()

    ea.encodeZZXPtxt(const1_poly, const1)
    ea.encodeZZXPtxt(const2_poly, const2)


    #Multiply c1 by c0
    mul(ea, p1, p0)
    c1.multiplyBy(c0)
    CheckCtxt(c1, "c1*=c0")
    debugCompare(ea, secretKey, p1, c1)

    #c0 += random constant
    add(ea, p0, const1)
    c0.addConstantZZX(const1_poly)
    CheckCtxt(c0, "c0+=k1")
    debugCompare(ea, secretKey, p0, c0)

    #c2 *= random constant
    mul(ea, p2, const2)
    c2.multByConstantZZX(const2_poly)
    CheckCtxt(c2, "c2*=k2")
    debugCompare(ea, secretKey, p2, c2)

    tmp_p = NewPlaintextArray(p1)
    tmp = Ctxt(c1)
    strbuffer = "c2>>="
    strbuffer += str(shamt)
    shift(ea, tmp_p, shamt)
    ea.eashift(tmp, shamt)
    CheckCtxt(tmp, strbuffer)
    debugCompare(ea, secretKey, tmp_p, tmp)
    #print(strbuffer)

    #c2 += tmp
    add(ea, p2, tmp_p)
    add_ctxt(c2, tmp)
    CheckCtxt(c2, "c2+=tmp")
    debugCompare(ea, secretKey, tmp_p, tmp)

    strbuffer = "c2>>>="
    strbuffer += str(rotamt)
    rotate(ea, p2, rotamt)
    ea.earotate(c2, rotamt)
    CheckCtxt(c2, strbuffer)
    debugCompare(ea, secretKey, p2, c2)

    #c3.multiplyBy(c2)
    mul(ea, p3, p2)
    c3.multiplyBy(c2)
    CheckCtxt(c3, "c3*=c2")
    debugCompare(ea, secretKey, p3, c3)

    #c0 -= c3
    sub(ea, p0, p3)
    sub_ctxt(c0, c3)
    CheckCtxt(c0, "c0=-c3")
    debugCompare(ea, secretKey, p0, c0)

    c0.cleanUp()
    c1.cleanUp()
    c2.cleanUp()
    c3.cleanUp()

    pp0 = NewPlaintextArray(ea)
    pp1 = NewPlaintextArray(ea)
    pp2 = NewPlaintextArray(ea)
    pp3 = NewPlaintextArray(ea)

    ea.decrypt_plaintext(c0, secretKey, pp0)
    ea.decrypt_plaintext(c1, secretKey, pp1)
    ea.decrypt_plaintext(c2, secretKey, pp2)
    ea.decrypt_plaintext(c3, secretKey, pp3)

    if (equals(ea, pp0, p0) and equals(ea, pp1, p1) and \
     equals(ea, pp2, p2) and equals(ea, pp3, p3)):
        print("GOOD ")
    else:
        print("BAD")



if __name__ == "__main__":
    test()
