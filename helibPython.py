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

    publicKey = pw.FHEPubKey()
    secretKey = pw.FHESecKey()

    G = context.alMod.getFactorsOverZZ()[0]



if __name__ == "__main__":
    test()
