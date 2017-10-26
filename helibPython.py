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

    #try:
    context = pw.FHEcontext(m, p, r, a, b)
    #except Exception as e: print (e)
    pw.buildModChain(context, L, c, 0)
    #pw.writeContext(context)
    context.zMStar.printout()

    #Pa = PAlgebra()

    #G = pw.FHEcontext.PAlgebraMod.getFactorsOverZZ(0)


if __name__ == "__main__":
    test()
