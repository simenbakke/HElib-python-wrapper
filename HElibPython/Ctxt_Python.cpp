#include "Ctxt_Python.hpp"


using namespace boost::python;
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(addCtxt_overloads, addCtxt, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(addConstantZZX_overloads, addConstant, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(addConstantCRT_overloads, addConstant, 1, 2)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(multByConstantZZX_overloads, multByConstant, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(multByConstantCRT_overloads, multByConstant, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(multByConstantzzX_overloads, multByConstant, 1, 2)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(xorConstantCRT_overloads, xorConstant, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(xorConstantZZX_overloads, xorConstant, 1, 2)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(nxorConstantCRT_overloads, nxorConstant, 1, 2)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(nxorConstantZZX_overloads, nxorConstant, 1, 2)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(multByP_overloads, multByP, 0, 1)

void export_Ctxt(){

  //! print to cerr some info about ciphertext
  def("CheckCtxt", CheckCtxt);

  // set out=prod_{i=0}^{n-1} v[j], takes depth log n and n-1 products
  // out could point to v[0], but having it pointing to any other v[i]
  // will make the result unpredictable.
  def("totalProduct", totalProduct);

  //! For i=n-1...0, set v[i]=prod_{j<=i} v[j]
  //! This implementation uses depth log n and (nlog n)/2 products
  def("incrementalProduct", incrementalProduct);

  //Overloaded function
  void (*ip1)(Ctxt&, const vector<Ctxt>&, const vector<Ctxt>&)  = innerProduct;
  void (*ip2)(Ctxt&, const vector<Ctxt>&, const vector<DoubleCRT>&)  = innerProduct;
  void (*ip3)(Ctxt&, const vector<Ctxt>&, const vector<ZZX>&)  = innerProduct;

  //! Compute the inner product of two vectors of ciphertexts
  def("innerProductCtxt", ip1);

  //! Compute the inner product of a vectors of ciphertexts and a constant vector
  def("innerProductCRT", ip2);


  def("innerProductZZX", ip3);

  //Overladed functions in Ctxt class
  void (Ctxt::*addc1)(const ZZX&, double)  = &Ctxt::addConstant;
  void (Ctxt::*addc2)(const DoubleCRT&, double)  = &Ctxt::addConstant;
  void (Ctxt::*addc3)(const ZZ&)  = &Ctxt::addConstant;

  void (Ctxt::*mbc1)(const ZZX&, double)  = &Ctxt::multByConstant;
  void (Ctxt::*mbc2)(const zzX&, double)  = &Ctxt::multByConstant;
  void (Ctxt::*mbc3)(const DoubleCRT&, double)  = &Ctxt::multByConstant;
  void (Ctxt::*mbc4)(const ZZ&)  = &Ctxt::multByConstant;

  void (Ctxt::*xorc1)(const DoubleCRT&, double)  = &Ctxt::xorConstant;
  void (Ctxt::*xorc2)(const ZZX&, double)  = &Ctxt::xorConstant;

  void (Ctxt::*nxorc1)(const ZZX&, double)  = &Ctxt::nxorConstant;
  void (Ctxt::*nxorc2)(const DoubleCRT&, double)  = &Ctxt::nxorConstant;


  class_<Ctxt>("Ctxt", no_init)
    //class constructor
    .def(init<const FHEPubKey&, optional<long>>())
    .def(init<const Ctxt&>())


    // Add/subtract aonther ciphertext
    .def("addCtxt", &Ctxt::addCtxt, addCtxt_overloads())

    // a procedural variant with an additional parameter
    .def("equalsTo", &Ctxt::equalsTo)


    //! Add a constant polynomial. If the size is not given, we use
    //! phi(m)*ptxtSpace^2 as the default value.
    .def("addConstantZZX", addc1, addConstantZZX_overloads())
    .def("addConstantCRT", addc2, addConstantCRT_overloads())
    .def("addConstantZZ", addc3)

    //! Multiply-by-constant. If the size is not given, we use
    //! phi(m)*ptxtSpace^2 as the default value.
    .def("multByConstantZZX", mbc1, multByConstantZZX_overloads())
    .def("multByConstantCRT", mbc3, multByConstantCRT_overloads())
    .def("multByConstantzzX", mbc2, multByConstantzzX_overloads())
    .def("multByConstantZZ", mbc4)

    //! Convenience method: XOR and nXOR with arbitrary plaintext space:
    //! a xor b = a+b-2ab = a + (1-2a)*b,
    //! a nxor b = 1-a-b+2ab = (b-1)(2a-1)+a
    .def("xorConstantCRT", xorc1, xorConstantCRT_overloads())
    .def("xorConstantZZX", xorc2, xorConstantZZX_overloads())

    .def("nxorConstantCRT", nxorc1, nxorConstantCRT_overloads())
    .def("nxorConstantZZX", nxorc2, nxorConstantZZX_overloads())

    //! Divide a cipehrtext by p, for plaintext space p^r, r>1. It is assumed
    //! that the ciphertext encrypts a polynomial which is zero mod p. If this
    //! is not the case then the result will not be a valid ciphertext anymore.
    //! As a side-effect, the plaintext space is reduced from p^r to p^{r-1}.
    .def("divideByP", &Ctxt::divideByP)

    //! Mulitply ciphretext by p^e, for plaintext space p^r. This also has
    //! the side-effect of increasing the plaintext space to p^{r+e}.
    .def("multByP", &Ctxt::multByP, multByP_overloads())

    // Higher-level multiply routines
    .def("multiplyBy", &Ctxt::multiplyBy)
    .def("multiplyBy2", &Ctxt::multiplyBy2)
    .def("square", &Ctxt::square)
    .def("cube", &Ctxt::cube)

    //! @brief raise ciphertext to some power
    .def("power", &Ctxt::power)

    //! Reduce plaintext space to a divisor of the original plaintext space
    .def("reducePtxtSpace", &Ctxt::reducePtxtSpace)

    // This method can be used to increase the plaintext space, but the
    // high-order digits that you get this way are noise. Do not use it
    // unless you know what you are doing.
    .def("hackPtxtSpace", &Ctxt::hackPtxtSpace)
    .def("bumpNoiseEstimate", &Ctxt::bumpNoiseEstimate)
    .def("reLinearize", &Ctxt::reLinearize)

    .def("cleanUp", &Ctxt::cleanUp)

    // relinearize, then reduce, then drop special primes
    .def("reduce", &Ctxt::reduce)

    //! @brief Add a high-noise encryption of the given constant
    .def("blindCtxt", &Ctxt::blindCtxt)

    //! @brief Estimate the added noise variance
    .def("modSwitchAddedNoiseVar", &Ctxt::modSwitchAddedNoiseVar)

    //! @brief Find the "natural level" of a cipehrtext.
    // Find the level such that modDown to that level makes the
    // additive term due to rounding into the dominant noise term
    .def("findBaseLevel", &Ctxt::findBaseLevel)

    //! @brief Modulus-switching up (to a larger modulus).
    //! Must have primeSet <= s, and s must contain
    //! either all the special primes or none of them.
    .def("modUpToSet", &Ctxt::modUpToSet)

    //! @brief Modulus-switching down (to a smaller modulus).
    //! mod-switch down to primeSet \intersect s, after this call we have
    //! primeSet<=s. s must contain either all special primes or none of them
    .def("modDownToSet", &Ctxt::modDownToSet)

    //! @brief Modulus-switching down.
    .def("modDownToLevel", &Ctxt::modDownToLevel)


    //! @brief Special-purpose modulus-switching for bootstrapping.
    //!
    //! Mod-switch to an externally-supplied modulus. The modulus need not be in
    //! the moduli-chain in the context, and does not even need to be a prime.
    //! The ciphertext *this is not affected, instead the result is returned in
    //! the zzParts vector, as a vector of ZZX'es.
    //! Returns an extimate for the noise variance after mod-switching.
    .def("rawModSwitch", &Ctxt::rawModSwitch)

    //! @brief Find the "natural prime-set" of a cipehrtext.
    //! Find the highest IndexSet so that mod-switching down to that set results
    //! in the dominant noise term being the additive term due to rounding
    .def("findBaseSet", &Ctxt::findBaseSet)

    // //! @brief Evaluate the cleartext poly on the encrypted ciphertext
    // .def("evalPoly", &Ctxt::evalPoly)

    // set as an empty ciphertext
    .def("clear", &Ctxt::clear)
    //
    // //! @brief Is this an empty cipehrtext without any parts
    // .def("isEmpty", &Ctxt::isEmpty)
    //
    // //! @brief A canonical ciphertext has (at most) handles pointing to (1,s)
    // .def("inCanonicalForm", &Ctxt::inCanonicalForm)
    //
    // //! @brief Would this ciphertext be decrypted without errors?
    // .def("isCorrect", &Ctxt::isCorrect)
    //
    // // Return r such that p^r = ptxtSpace
    // .def("effectiveR", &Ctxt::effectiveR)
    //
    // //! @brief Returns log(noise-variance)/2 - log(q)
    // .def("log_of_ratio", &Ctxt::log_of_ratio)
    //
    //
    // .def("negate", &Ctxt::negate)
    //
    // // Apply automorphism F(X) -> F(X^k) (gcd(k,m)=1)
    // .def("automorph", &Ctxt::automorph)
    //
    // //! @brief automorphism with re-lienarization
    // .def("smartAutomorph", &Ctxt::smartAutomorph)
    //
    // //! @brief applies the automorphsim p^j using smartAutomorphism
    // .def("frobeniusAutomorph", &Ctxt::frobeniusAutomorph)

    ;

}
