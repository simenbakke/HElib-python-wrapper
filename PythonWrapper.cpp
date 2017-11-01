#include "FHEContext.h"
#include "FHE.h"
#include <NTL/ZZ.h>
#include <NTL/lzz_pXFactoring.h>
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
// struct ZZX_to_python
// {
//   static PyObject* convert(const ZZX& G){
//
//     return  incref(object(G).ptr());
//
//   }
//
// };

// EncryptedArray* getFactorsPython(const FHEcontext& context){
//
//   ZZX G = context.alMod.getFactorsOverZZ()[0];
//   EncryptedArray *ea = new EncryptedArray(context, G);
//   //ea(context, G);
//   return ea;
//
// }

void temp_function(const FHEcontext& context){

  if (context.ea == NULL){
    cout << "fucked";
  }
  else{
    cout << "works";
  }
}



BOOST_PYTHON_MODULE(PythonWrapper)
{

  //to_python_converter<ZZX, ZZX_to_python>();

  def("FindM", FindM);
  def("buildModChain", buildModChain);
  def("function", temp_function);
  //def("getFactorsPython", getFactorsPython);

  //Vector converter for python
  typedef std::vector<long>  pyvector;
  class_<std::vector<long>> ("pyvector")
  .def(vector_indexing_suite< std::vector<long> >());

  //typedef const vector<ZZX>&  ntlVector;
  //class_<ZZX, ZZX&>;

  class_<std::vector<NTL::ZZX, std::allocator<NTL::ZZX>> >("ntlVector")
    .def(vector_indexing_suite<std::vector<NTL::ZZX, std::allocator<NTL::ZZX> >>());

  {
    scope in_context = class_<FHEcontext>("FHEcontext", no_init)
      .def(init<unsigned long,unsigned long,unsigned long, pyvector, pyvector>())
      //.add_property("stdev", &FHEcontext::bitsPerLevel)
      .add_property("zMStar", &FHEcontext::zMStar)
      .add_property("alMod", &FHEcontext::alMod)
      // .add_property("ea",
      // make_getter(&FHEcontext::ea, return_internal_reference<>()),
      // make_setter(&FHEcontext::ea, return_internal_reference<>()))
    ;

    class_<PAlgebra>("PAlgebra", no_init)
      //.def(init<unsigned long,unsigned long, pyvector, pyvector>())
      .def("printout", &PAlgebra::printout)
    ;

    class_<PAlgebraMod>("PAlgebraMod", no_init)
      .def("getFactorsOverZZ",&PAlgebraMod::getFactorsOverZZ, return_value_policy<reference_existing_object>())
    ;
  }


  class_<NTL::ZZX>("pythonZZX")

  ;

  class_<FHEPubKey>("FHEPubKey", no_init)
  ;

  class_<FHESecKey, bases<FHEPubKey> >("FHESecKey", no_init)
    //.def("__init__", make_constructor(&FHEPubKey::FHEPubKey))
    //.def(init<&FHEPubKey(const FHEcontext& _context)>())

  ;
  // scope in_base = class_<EncryptedArrayBase>("EncryptedArrayBase", no_init)
  //
  // ;

  // class_<EncryptedArray>("EncryptedArray", no_init)
  //
  // ;

}
