#pragma once
#include "osrm/route_parameters.hpp"


#include "osrm/coordinate.hpp"
#include "osrm/engine_config.hpp"
#include "osrm/json_container.hpp"
#include "util/json_renderer.hpp"


#include "osrm/osrm.hpp"
#include "osrm/status.hpp"

#include <exception>
#include <iostream>
#include <string>
#include <utility>

#include <cstdlib>
#include <string>
#include <sstream>
class osrmpy
{

	osrm::EngineConfig config;
	osrm::RouteParameters params;
	osrm::OSRM* router;

	const char *data_path;
	osrm::OSRM* configFactory(const char * p) {

		// Configure based on a .osrm base path, and no datasets in shared mem from osrm-datastore
		osrm::EngineConfig config;

		config.use_mmap = false;
		config.max_locations_viaroute = 500;
		config.max_locations_trip = 500;
		config.max_locations_distance_table = 100;
		config.max_locations_map_matching = 100;
		config.max_alternatives = 0;
		config.max_radius_map_matching = -1.0;
		config.storage_config = { p };
		config.use_shared_memory = false;
		config.algorithm = osrm::EngineConfig::Algorithm::CH;

		// Routing machine with several services (such as Route, Table, Nearest, Trip, Match)
		router = new osrm::OSRM(config);

		// The following shows how to use the Route service; configure this service

		params.overview = osrm::RouteParameters::OverviewType::Simplified;
		params.steps = true;
		params.generate_hints = false;
		params.alternatives = false;
		params.geometries = osrm::RouteParameters::GeometriesType::GeoJSON;
		params.alternatives = false;
    	return router;
	}
public:
	osrmpy() {}
	osrmpy(const char * path);
	 const char* route(double src[2], double dst[2], char* refresult, size_t size);
	~osrmpy();
};


