#include "EncryptedArray_python.hpp"

using namespace boost::python;
void export_EncryptedArray(){



  //Overloaded functions
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

  void (*encf1)(const EncryptedArray& ea, NewPlaintextArray& pa, const vector<long>& array) = &encode;
  def("encodePtxtVec", encf1);

  //Overladed functions in EncryptedArray class
  void (EncryptedArray::*e1)(Ctxt&, const FHEPubKey&, const pyvector&) const = &EncryptedArray::encrypt;
  void (EncryptedArray::*e2)(Ctxt&, const FHEPubKey&, const NewPlaintextArray&) const = &EncryptedArray::encrypt;

  void (EncryptedArray::*d1)(const Ctxt&, const FHESecKey&, pyvector&) const = &EncryptedArray::decrypt;
  void (EncryptedArray::*d2)(const Ctxt&, const FHESecKey&, NewPlaintextArray&) const = &EncryptedArray::decrypt;

  void (EncryptedArray::*enc1)(ZZX&, const NewPlaintextArray&) const = &EncryptedArray::encode;
  void (EncryptedArray::*enc2)(ZZX&, const vector< ZZX >&) const = &EncryptedArray::encode;
  void (EncryptedArray::*enc3)(ZZX&, const vector< long >&) const = &EncryptedArray::encode;
  void (EncryptedArray::*enc4)(zzX&, const vector< long >&) const = &EncryptedArray::encode;
  void (EncryptedArray::*enc5)(zzX&, const vector< zzX >&) const = &EncryptedArray::encode;
  void (EncryptedArray::*enc6)(zzX&, const NewPlaintextArray&) const = &EncryptedArray::encode;

  void (EncryptedArray::*dec1)(vector<long >& , const ZZX&) const = &EncryptedArray::decode;
  void (EncryptedArray::*dec2)(vector<ZZX>& , const ZZX&) const = &EncryptedArray::decode;
  void (EncryptedArray::*dec3)(NewPlaintextArray&, const ZZX&) const = &EncryptedArray::decode;

  void (EncryptedArray::*eashift)(Ctxt&, long) const = &EncryptedArray::shift;
  void (EncryptedArray::*earotate)(Ctxt&, long) const = &EncryptedArray::rotate;

  class_<EncryptedArray>("EncryptedArray", no_init)
    //constructors
    .def(init<const FHEcontext&, const ZZX&>())
    .def(init<const FHEcontext&, const PAlgebraMod&>())

    .def("encodeZZXPtxt", enc1)
    .def("encodeZZXZZX", enc2)
    .def("encodeZZXvec", enc3)
    .def("encodezzXvec", enc4)
    .def("encodezzXzzX", enc5)
    .def("encodezzXPtxt", enc6)

    .def("decodeVecZZX", dec1)
    .def("decodeZZXZZX", dec2)
    .def("decodePtxtZZX", dec3)

    .def("encrypt", e1)
    .def("encrypt_plaintext", e2)
    .def("decrypt", d1)
    .def("decrypt_plaintext", d2)

    .def("eashift", eashift)
    .def("earotate", earotate)
    .def("size", &EncryptedArray::size)
  ;

  class_<NewPlaintextArray>("NewPlaintextArray", no_init)
    .def(init<const EncryptedArray&>())
    .def(init<const NewPlaintextArray&>())
  ;


}
