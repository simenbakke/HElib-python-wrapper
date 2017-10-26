#include "FHEContext.h"
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
//#include <boost/python/long.hpp>
//#include <boost/python/docstring_options.hpp>
#include <Python.h>
#include <vector>
#include <iostream>
#include <sstream>

using namespace boost::python;


// int temp(){
//
//   long a,b,c = 1;
//   vector<long> v1,v2;
//   FHEcontext context(a,b,c,v1,v2);
//   return 0;
//
// }

void writeContext(const FHEcontext& context){

  writeContextBase(std::cout, context);

}


BOOST_PYTHON_MODULE(PythonWrapper)
{

  def("FindM", FindM);
  def("buildModChain", buildModChain);
  def("writeContext", writeContext);

  //Vector converter for python
  typedef std::vector<long>  pyvector;
  class_<std::vector<long>> ("pyvector")
  .def(vector_indexing_suite< std::vector<long> >());



  scope in_context = class_<FHEcontext>("FHEcontext", no_init)
    .def(init<unsigned long,unsigned long,unsigned long, pyvector, pyvector>())
    //.def("writeContextBase", writeContextBase(stream, const FHEcontext&))
  ;

  class_<PAlgebra>("zMStar", no_init)
    .def(init<unsigned long,unsigned long, pyvector, pyvector>())
    .def("printout", &PAlgebra::printout)
  ;

  class_<PAlgebraMod>("PAlgebraMod", no_init)
    .def(init<const PAlgebra&, long>())
    .def("getFactorsOverZZ",&PAlgebraMod::getFactorsOverZZ, return_value_policy<reference_existing_object>())

  ;

}
