#include "FHE_python.hpp"

using namespace boost::python;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(GenSecKey_overloads, GenSecKey, 1, 3)
BOOST_PYTHON_FUNCTION_OVERLOADS(addSome1DMatrices_overloads, addSome1DMatrices, 1, 3)

void export_FHEContext(){


  def("addSome1DMatrices", addSome1DMatrices, addSome1DMatrices_overloads());

  class_<FHEPubKey>("FHEPubKey")
    .def(init<const FHEcontext&>())
    .def("keyExists", &FHEPubKey::keyExists)
  ;

  class_<FHESecKey, bases<FHEPubKey> >("FHESecKey", no_init)
    .def(init<const FHEcontext&>())
    .def("GenSecKey", &FHESecKey::GenSecKey, GenSecKey_overloads())
  ;

}
