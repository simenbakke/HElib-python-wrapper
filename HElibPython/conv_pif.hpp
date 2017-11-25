#include <NTL/ZZ.h>
#include <NTL/lzz_pXFactoring.h>
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "EncryptedArray.h"
// #include "Ctxt.h"
#include <cassert>
#include <cstdio>
#include <NTL/BasicThreadPool.h>
#include "timing.h"
#include <Python.h>
#include <vector>
#include <iostream>
#include <sstream>

typedef std::vector<long>  pyvector;
