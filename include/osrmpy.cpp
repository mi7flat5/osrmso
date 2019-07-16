
#include "osrmpy.h"
#define TRUNCATE ((size_t)-1)

using namespace osrm;
osrmpy::osrmpy(const char * path) : data_path(path), router(configFactory(path))
{

}

 const char* osrmpy::route(double src[2], double dst[2], char* refresult, size_t size)
{
	params.coordinates.clear();
	params.coordinates.push_back({ util::FloatLongitude{src[0]}, util::FloatLatitude{src[1]} });
	params.coordinates.push_back({ util::FloatLongitude{dst[0]}, util::FloatLatitude{dst[1]} });

	json::Object result;

	// Execute routing request, this does the heavy lifting
	const auto status = router->Route(params, result);
	
	if (status == Status::Ok)
	{
		std::ostringstream s;
		json::render(s, result);
		std::string stringResult = s.str();

		sprintf(refresult, stringResult.c_str());
		return stringResult.c_str();
	}
	else if (status == Status::Error)
	{
		const auto code = result.values["code"].get<json::String>().value;
		const auto message = result.values["message"].get<json::String>().value;

		std::cout << "Code: " << code << "\n";
		std::cout << "Message: " << message << "\n";
		const char * res = (code + std::string(" : ") + message).c_str();
		sprintf(refresult,res);
		return res;
	}

}

osrmpy::~osrmpy()
{
}
