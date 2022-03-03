cmake_minimum_required(VERSION 3.10)
 
project(asnlib VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE ASNLIB_SOURCE "src/*.c")
add_library (asnlib STATIC ${ASNLIB_SOURCE})
target_compile_options(asnlib PRIVATE "-Wformat-truncation=0" "-Wno-format-overflow" "-Wno-unused-result")
target_include_directories(asnlib PUBLIC "src")

