cmake_minimum_required(VERSION 3.10)

set(LIBS "libs")
set(SHARED_PATH "shared")

set(RTKLIB_INCLUDE_PATH "rtklib/src")
set(ASNLIB_INCLUDE_PATH "asnlib/src")
set(LPP_INCLUDE_PATH "lpp/include")
set(MODEM_INCLUDE_PATH "modem/include")
set(RTCM_GENERATOR_INCLUDE_PATH "rtcm_generator/include")

option(USE_OPENSSL "USE_OPENSSL" ON)
option(USE_ASAN "USE_ASAN" OFF)

set(CLIENT_DEBUG_OPTIONS "-O0" "-g" "-DRELEASE=0" "-DDEBUG=1")
set(CLIENT_RELEASE_OPTIONS "-O3" "-DRELEASE=1" "-DDEBUG=0" )

add_definitions(
    "-DASN_DISABLE_OER_SUPPORT" "-DENAGLO" "-DENAGAL" 
    "-DNFREQ=4" "-DNEXOBS=3" 
    "-DSVR_REUSEADDR" "-DASN_EMIT_DEBUG=0")

if(USE_OPENSSL)
    add_definitions("-DUSE_OPENSSL=1")
endif()

if(USE_ASAN)
    add_definitions("-DUSE_ASAN=1")
endif()

add_subdirectory("libs/rtklib")
add_subdirectory("libs/asnlib")
add_subdirectory("libs/modem")
add_subdirectory("libs/lpp")
add_subdirectory("libs/rtcm_generator")

#
# Example
#
project(example VERSION 1.0)
find_package(Threads REQUIRED)

if(USE_OPENSSL)
    find_package(OpenSSL REQUIRED)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(example "src/main.cpp")
target_include_directories(example PRIVATE "${LIBS}/${RTKLIB_INCLUDE_PATH}")
target_include_directories(example PRIVATE "${LIBS}/${ASNLIB_INCLUDE_PATH}")
target_include_directories(example PRIVATE "${LIBS}/${LPP_INCLUDE_PATH}")
target_include_directories(example PRIVATE "${LIBS}/${RTCM_GENERATOR_INCLUDE_PATH}")
target_include_directories(example PRIVATE "${LIBS}/${MODEM_INCLUDE_PATH}")
target_include_directories(example PRIVATE "${LIBS}/${SHARED_PATH}")

target_compile_options(example PRIVATE  "-Wall" "-Wextra" "-pedantic" "-Werror" 
                                        "-fvisibility=hidden" "-Wno-missing-field-initializers" 
                                        "-Wformat" "-Wformat-signedness")
target_compile_options(example PRIVATE "$<$<CONFIG:DEBUG>:${CLIENT_DEBUG_OPTIONS}>")
target_compile_options(example PRIVATE "$<$<CONFIG:RELEASE>:${CLIENT_RELEASE_OPTIONS}>")

if(USE_ASAN)
    target_compile_options(example PRIVATE -fsanitize=address)
    target_link_libraries(example -fsanitize=address)
endif()

target_link_libraries(example pthread)
target_link_libraries(example rtcm_generator)
target_link_libraries(example lpp)
target_link_libraries(example modem)
target_link_libraries(example m)
