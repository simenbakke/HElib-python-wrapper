#include "Ctxt_Python.hpp"


using namespace boost::python;
void export_Ctxt(){


  void (Ctxt::*addc1)(const ZZX&, double)  = &Ctxt::addConstant;
  void (Ctxt::*mbc1)(const ZZX&, double)  = &Ctxt::multByConstant;
  //BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(addc1, Ctxt::addConstant, 1, 2)

  class_<Ctxt>("Ctxt", no_init)
    .def(init<const FHEPubKey&, long>())
    .def(init<const Ctxt&>())
    .def("multiplyBy", &Ctxt::multiplyBy)
    .def("multByConstant", mbc1)
    .def("addConstant", addc1)
    .def("addCtxt", &Ctxt::addCtxt)
    .def("cleanUp", &Ctxt::cleanUp)
  ;

}
