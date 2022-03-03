cmake_minimum_required(VERSION 3.10)
 
project(rtklib VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE RTKLIB_SOURCE "src/*.c")
add_library (rtklib STATIC ${RTKLIB_SOURCE})
target_include_directories(rtklib PUBLIC "src")