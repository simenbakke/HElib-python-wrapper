from PythonWrapper import *
import math
import os
import time

def test(R, p, r, d, c, k, w, L, m, gens, ords):
    # m = 7781
    # p = 2
    # r = 1
    # L = 6
    # c = 2
    # w = 64
    # d = 1
    # k = 80
    # s = 0
    # a = pyvector()
    # b = pyvector()
    #
    # m = FindM(k, L, c, p, d, s, 0)

    start = time.clock()

    #gens1, ords1 = pyvector()

    #initialize context
    context = FHEcontext(m, p, r, gens, ords)
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

    randomEAPtxt(ea, p0)
    randomEAPtxt(ea, p1)
    randomEAPtxt(ea, p2)
    randomEAPtxt(ea, p3)

    c0 = Ctxt(publicKey)
    c1 = Ctxt(publicKey)
    c2 = Ctxt(publicKey)
    c3 = Ctxt(publicKey)

    ea.encryptPtxt(c0, publicKey, p0)
    ea.encryptPtxt(c1, publicKey, p1)
    ea.encryptPtxt(c2, publicKey, p2)
    ea.encryptPtxt(c3, publicKey, p3)

    resetAllTimers()

    Curcuit_FHE = FHEtimer("Circuit", os.path.basename(__file__))
    Curcuit_auto = auto_timer(Curcuit_FHE)

    for i in range(R):

        print("**** ROUND", i, "****")
        shamt = RandomBnd((int((2*(nslots/2) + 1) - (nslots/2))))
        rotamt = RandomBnd((2*(nslots-2) - 1 - (nslots-2)))

        const1 = NewPlaintextArray(ea)
        const2 = NewPlaintextArray(ea)

        randomEAPtxt(ea, const1)
        randomEAPtxt(ea, const2)

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

        negate(ea, p1)
        c1.negate()
        CheckCtxt(c1, "c1=-c1")
        debugCompare(ea, secretKey, p1, c1)

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

    Curcuit_auto.stop()
    print("\n")
    printAllTimers()

    resetAllTimers()

    Check_FHE = FHEtimer("Check", os.path.basename(__file__))
    Check_auto = auto_timer(Check_FHE)

    pp0 = NewPlaintextArray(ea)
    pp1 = NewPlaintextArray(ea)
    pp2 = NewPlaintextArray(ea)
    pp3 = NewPlaintextArray(ea)

    ea.decryptPtxt(c0, secretKey, pp0)
    ea.decryptPtxt(c1, secretKey, pp1)
    ea.decryptPtxt(c2, secretKey, pp2)
    ea.decryptPtxt(c3, secretKey, pp3)

    if (equals(ea, pp0, p0) and equals(ea, pp1, p1) and
            equals(ea, pp2, p2) and equals(ea, pp3, p3)):
        print("GOOD ")
    else:
        print("BAD")

    Check_auto.stop()
    print("\n")
    printAllTimers()

if __name__ == "__main__":

    setTimersOn()

    # number of rounds
    R = 1000

    # plaintext base
    p = 2

    # lifting
    r = 1

    # degree of the field extension
    d = 1

    # number of columns in the key-switching matrices
    c = 2

    # security parameter
    k = 80

    # number of levels in the modulus chain
    L = 0

    # minimum number of slots
    s = 0

    # number of times to repeat the test
    repeat = 1

    # use specified value as modulus
    chosen_m = 0

    # use product of the integers as modulus
    mvec = pyvector()

    # use specified vector of generators
    gens = pyvector()

    # use specified vbector of orders
    ords = pyvector()

    # PRG specified
    seed = 0

    if L == 0:
        L = 3*R+3
        if p > 2 or r > 1:
            addPerRound = 2 * math.ceil(math.log(p)*r*3)/(math.log(2.0)*44) + 1
            L += R *addPerRound

    # hamming weight of secret key
    w = 64

    if len(mvec) > 0:
        chosen_m = computeProd(mvec)
    m = FindM(k, L, c, p, d, s, chosen_m)

    for i in range(repeat):
        test(R, p, r, d, c, k, w, L, m, gens, ords)
