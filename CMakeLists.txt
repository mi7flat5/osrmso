cmake_minimum_required(VERSION 3.10)
project(osrm_dll)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_BINARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
find_package( Boost COMPONENTS system filesystem iostreams program_options chrono date_time thread REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(osrm_dll SHARED library.cpp library.h)
target_sources(osrm_dll PUBLIC ${CMAKE_SOURCE_DIR}/include/osrmpy.h)
target_sources(osrm_dll PUBLIC  ${CMAKE_SOURCE_DIR}/include/osrmpy.cpp)
target_link_libraries(osrm_dll PUBLIC  ${CMAKE_SOURCE_DIR}/deps/libosrm.a
        ${Boost_FILESYSTEM_LIBRARY} ${Boost_IOSTREAMS_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_CHRONO_LIBRARY} ${Boost_DATE_TIME_LIBRARY}
        ${Boost_THREAD_LIBRARY}

        )
