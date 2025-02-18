#include "conv_pif.hpp"
#include <fstream>

using namespace boost::python;


Ctxt Ctxt_sum(Ctxt& ct1, Ctxt& ct2){

  Ctxt ctSum = ct1;
  ctSum += ct2;

  return ctSum;
}

Ctxt Ctxt_prod(Ctxt& ct1, Ctxt& ct2){

  Ctxt ctSum = ct1;
  ctSum *= ct2;

  return ctSum;
}

void debugCompare(EncryptedArray& ea, FHESecKey& sk, NewPlaintextArray& p, Ctxt& c){
  NewPlaintextArray pp(ea);\
  ea.decrypt(c, sk, pp);\
  if (!equals(ea, pp, p)) { \
    std::cout << "oops:\n"; std::cout << p << "\n\n"; \
    std::cout << pp << "\n"; \
    exit(0); \
  }

}

void debugCompareVector(EncryptedArray& ea, FHESecKey& sk, const vector<ZZX>& p, Ctxt& c){
  NewPlaintextArray pp(ea);\
  ea.decrypt(c, sk, pp);\
  if (!equals(ea, pp, p)) { \
    std::cout << "oops:\n"; std::cout << p << "\n\n"; \
    std::cout << pp << "\n"; \
    exit(0); \
  }

}

void printAllTimersPython(){

  std::ofstream ofs;
  ofs.open("script/test.txt", std::ofstream::out | std::ofstream::app);

  printAllTimers(ofs);
  ofs.close();

}
void add_ctxt(Ctxt& a, Ctxt& b){
      a += b;
}

void sub_ctxt(Ctxt& a, Ctxt& b){
      a -= b;
}


void export_EncryptedArray();
void export_Ctxt();
void export_pyVectors();
void export_FHEContext();
void export_PAlgebra();
void export_FHE();




BOOST_PYTHON_MODULE(PythonWrapper)
{

  //Functions for sum and multiply Ctxt
  def("Ctxt_sum", Ctxt_sum);
  def("Ctxt_prod", Ctxt_prod);
  def("add_ctxt", add_ctxt);
  def("sub_ctxt", sub_ctxt);

  //Debug functions
  def("debugCompare", debugCompare);
  def("debugCompareVector", debugCompareVector);

  //timer functions
  def("setTimersOn", setTimersOn);
  def("resetAllTimers", resetAllTimers);
  def("printAllTimers", printAllTimersPython);

  def("makeIrredPoly", makeIrredPoly);

  long (*cprod)(const pyvector&) = &computeProd;
  def("computeProd", cprod);

  //NTL functions
  long (*rb)(long) = &NTL::RandomBnd;
  def("RandomBnd", rb);


  export_pyVectors();
  export_FHEContext();
  export_PAlgebra();
  export_EncryptedArray();
  export_Ctxt();
  export_FHE();
  //NTL vector class
  class_<NTL::ZZX>("ZZX")
  ;

  class_<FHEtimer>("FHEtimer", no_init)
    .def(init<const char*, const char*>())
  ;

  class_<auto_timer>("auto_timer", no_init)
    .def(init<FHEtimer*>())
    .def("stop", &auto_timer::stop)
 ;


}
