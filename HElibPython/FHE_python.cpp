#include "FHE_python.hpp"

using namespace boost::python;

void export_FHEContext(){

  class_<FHEPubKey>("FHEPubKey")
    .def(init<const FHEcontext&>())
    .def("keyExists", &FHEPubKey::keyExists)
  ;

  class_<FHESecKey, bases<FHEPubKey> >("FHESecKey", no_init)
    .def(init<const FHEcontext&>())
    .def("GenSecKey", &FHESecKey::GenSecKey)
  ;

}
