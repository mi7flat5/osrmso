#ifndef OSRM_DLL_LIBRARY_H
#define OSRM_DLL_LIBRARY_H
#include "osrmpy.h"
#include <iostream>
extern "C" void initRouter(const char * path);
extern "C" const char * DoRoute(double src[2],double dst[2],char* refresult, size_t size);

#endif