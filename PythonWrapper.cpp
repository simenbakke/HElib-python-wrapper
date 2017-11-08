#include "FHEContext.h"
#include "FHE.h"
#include <NTL/ZZ.h>
#include <NTL/lzz_pXFactoring.h>
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "EncryptedArray.h"
#include <cassert>
#include <cstdio>
#include <NTL/BasicThreadPool.h>
//#include <boost/python/long.hpp>
//#include <boost/python/docstring_options.hpp>
#include <Python.h>
#include <vector>
#include <iostream>
#include <sstream>


using namespace boost::python;



Ctxt Ctxt_sum(Ctxt& ct1, Ctxt& ct2){

  Ctxt ctSum = ct1;
  ctSum += ct2;

  return ctSum;
}

Ctxt Ctxt_prod(Ctxt& ct1, Ctxt& ct2){

  Ctxt ctSum = ct1;
  ctSum *= ct2;

  return ctSum;
}

void debugCompare(EncryptedArray& ea, FHESecKey& sk, NewPlaintextArray& p, Ctxt& c){
  NewPlaintextArray pp(ea);\
  ea.decrypt(c, sk, pp);\
  if (!equals(ea, pp, p)) { \
    std::cout << "oops:\n"; std::cout << p << "\n\n"; \
    std::cout << pp << "\n"; \
    exit(0); \
  }

}

void add_ctxt(Ctxt& a, Ctxt& b){
      a += b;
}

void sub_ctxt(Ctxt& a, Ctxt& b){
      a -= b;
}

BOOST_PYTHON_MODULE(PythonWrapper)
{

  //to_python_converter<ZZX, ZZX_to_python>();

  def("FindM", FindM);
  def("buildModChain", buildModChain);
  def("Ctxt_sum", Ctxt_sum);
  def("Ctxt_prod", Ctxt_prod);
  def("addSome1DMatrices", addSome1DMatrices);
  def("CheckCtxt", CheckCtxt);
  def("debugCompare", debugCompare);
  def("makeIrredPoly", makeIrredPoly);
  def("add_ctxt", add_ctxt);
  def("sub_ctxt", sub_ctxt);



  void (*r1)(const EncryptedArray&, NewPlaintextArray&) = &random;
  def("random", r1);

  void (*m1)(const EncryptedArray&, NewPlaintextArray&, const NewPlaintextArray&) = &mul;
  def("mul", m1);

  void (*a1)(const EncryptedArray&, NewPlaintextArray&, const NewPlaintextArray&) = &add;
  def("add", a1);

  void (*s1)(const EncryptedArray&, NewPlaintextArray&, const NewPlaintextArray&) = &sub;
  def("sub", s1);

  bool (*eq1)(const EncryptedArray&, const NewPlaintextArray&, const NewPlaintextArray&) = &equals;
  def("equals", eq1);

  void (*sh1)(const EncryptedArray&, NewPlaintextArray&, long) = &shift;
  def("shift", sh1);

  void (*rt1)(const EncryptedArray&, NewPlaintextArray&, long) = &rotate;
  def("rotate", rt1);

  //NTL functions
  long (*rb)(long) = &NTL::RandomBnd;
  def("RandomBnd", rb);


  //Vector converter for python
  typedef std::vector<long>  pyvector;
  class_<std::vector<long>> ("pyvector")
  .def(vector_indexing_suite< std::vector<long> >());

  //NTL vector converter
  class_<std::vector<NTL::ZZX, std::allocator<NTL::ZZX>> >("ntlVector")
    .def(vector_indexing_suite<std::vector<NTL::ZZX, std::allocator<NTL::ZZX> >>());

  {
  scope in_context = class_<FHEcontext>("FHEcontext", no_init)
    .def(init<unsigned long,unsigned long,unsigned long, pyvector, pyvector>())
    .add_property("zMStar", &FHEcontext::zMStar)
    .add_property("alMod", &FHEcontext::alMod)
  ;

    class_<PAlgebra>("PAlgebra", no_init)
      //.def(init<unsigned long,unsigned long, pyvector, pyvector>())
      .def("printout", &PAlgebra::printout)
    ;

    class_<PAlgebraMod>("PAlgebraMod", no_init)
      .def("getFactorsOverZZ",&PAlgebraMod::getFactorsOverZZ, return_value_policy<reference_existing_object>())
    ;
  }

  //NTL vector class
  class_<NTL::ZZX>("ZZX")
  ;

  class_<FHEPubKey>("FHEPubKey")
    .def(init<const FHEcontext&>())
    .def("keyExists", &FHEPubKey::keyExists)
  ;

  class_<FHESecKey, bases<FHEPubKey> >("FHESecKey", no_init)
    .def(init<const FHEcontext&>())
    .def("GenSecKey", &FHESecKey::GenSecKey)
  ;


  void (Ctxt::*addc1)(const ZZX&, double)  = &Ctxt::addConstant;
  void (Ctxt::*mbc1)(const ZZX&, double)  = &Ctxt::multByConstant;
  //BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(addc1, Ctxt::addConstant, 1, 2)

  class_<Ctxt>("Ctxt", no_init)
    .def(init<const FHEPubKey&, long>())
    .def(init<const Ctxt&>())
    .def("multiplyBy", &Ctxt::multiplyBy)
    .def("multByConstant", mbc1)
    .def("addConstant", addc1)
    .def("cleanUp", &Ctxt::cleanUp)
  ;


  void (EncryptedArray::*e1)(Ctxt&, const FHEPubKey&, const pyvector&) const = &EncryptedArray::encrypt;
  void (EncryptedArray::*e2)(Ctxt&, const FHEPubKey&, const NewPlaintextArray&) const = &EncryptedArray::encrypt;
  void (EncryptedArray::*d1)(const Ctxt&, const FHESecKey&, pyvector&) const = &EncryptedArray::decrypt;
  void (EncryptedArray::*d2)(const Ctxt&, const FHESecKey&, NewPlaintextArray&) const = &EncryptedArray::decrypt;
  void (EncryptedArray::*enc1)(ZZX&, const NewPlaintextArray&) const = &EncryptedArray::encode;
  void (EncryptedArray::*eashift)(Ctxt&, long) const = &EncryptedArray::shift;
  void (EncryptedArray::*earotate)(Ctxt&, long) const = &EncryptedArray::rotate;

  class_<EncryptedArray>("EncryptedArray", no_init)
    .def(init<const FHEcontext&, const ZZX&>())
    .def("encrypt", e1)
    .def("encrypt_plaintext", e2)
    .def("decrypt", d1)
    .def("decrypt_plaintext", d2)
    .def("encode", enc1)
    .def("eashift", eashift)
    .def("earotate", earotate)
    .def("size", &EncryptedArray::size)
  ;

  class_<NewPlaintextArray>("NewPlaintextArray", no_init)
    .def(init<const EncryptedArray&>())
    .def(init<const NewPlaintextArray&>())
  ;


}
