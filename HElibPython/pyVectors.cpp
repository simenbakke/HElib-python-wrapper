#include "pyVectors.hpp"


using namespace boost::python;
void export_pyVectors(){

  //Vector converter for python
  
  class_<std::vector<long>> ("pyvector")
  .def(vector_indexing_suite< std::vector<long> >());

  //NTL vector converter
  class_<std::vector<NTL::ZZX, std::allocator<NTL::ZZX>> >("ntlVector")
    .def(vector_indexing_suite<std::vector<NTL::ZZX, std::allocator<NTL::ZZX> >>());

}
