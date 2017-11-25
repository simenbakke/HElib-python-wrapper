#include "PAlgebra_python.hpp"

using namespace boost::python;

void export_PAlgebra(){

  class_<PAlgebra>("PAlgebra", no_init)
    //.def(init<unsigned long,unsigned long, pyvector, pyvector>())
    .def("printout", &PAlgebra::printout)
  ;

  class_<PAlgebraMod>("PAlgebraMod", no_init)
    .def("getFactorsOverZZ",&PAlgebraMod::getFactorsOverZZ, return_value_policy<reference_existing_object>())
  ;


}
