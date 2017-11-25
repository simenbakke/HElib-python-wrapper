#include "FHEContext_python.hpp"

using namespace boost::python;
void export_FHE(){


  class_<FHEcontext>("FHEcontext", no_init)
    .def(init<unsigned long,unsigned long,unsigned long, pyvector, pyvector>())
    .add_property("zMStar", &FHEcontext::zMStar)
    .add_property("alMod", &FHEcontext::alMod)
  ;
}
