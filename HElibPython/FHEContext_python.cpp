#include "FHEContext_python.hpp"

using namespace boost::python;

BOOST_PYTHON_FUNCTION_OVERLOADS(FindM_overloads, FindM, 7, 8)
BOOST_PYTHON_FUNCTION_OVERLOADS(buildModChain_overloads, buildModChain, 2, 4)

void export_FHE(){

def("FindM", FindM, FindM_overloads());
def("buildModChain", buildModChain, buildModChain_overloads());

  class_<FHEcontext>("FHEcontext", no_init)
    .def(init<unsigned long,unsigned long,unsigned long, pyvector, pyvector>())
    .add_property("zMStar", &FHEcontext::zMStar)
    .add_property("alMod", &FHEcontext::alMod)
  ;
}
