#include "library.h"
#include<memory>
std::unique_ptr<osrmpy>  router;

extern "C" void initRouter(const char * path) {
    router = std::make_unique<osrmpy>(osrmpy(path));
}

 extern "C" const char * DoRoute(double src[2],double dst[2],char* refresult, size_t size){
    const char* result = router->route(src,dst,refresult,size);
    return result;
}