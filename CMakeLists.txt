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
# supl-lpp-client
#
project(supl-lpp-client VERSION 1.0)
find_package(Threads REQUIRED)

if(USE_OPENSSL)
    find_package(OpenSSL REQUIRED)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(supl-lpp-client "src/main.cpp")
target_include_directories(supl-lpp-client PRIVATE "${LIBS}/${RTKLIB_INCLUDE_PATH}")
target_include_directories(supl-lpp-client PRIVATE "${LIBS}/${ASNLIB_INCLUDE_PATH}")
target_include_directories(supl-lpp-client PRIVATE "${LIBS}/${LPP_INCLUDE_PATH}")
target_include_directories(supl-lpp-client PRIVATE "${LIBS}/${RTCM_GENERATOR_INCLUDE_PATH}")
target_include_directories(supl-lpp-client PRIVATE "${LIBS}/${MODEM_INCLUDE_PATH}")
target_include_directories(supl-lpp-client PRIVATE "${LIBS}/${SHARED_PATH}")

target_compile_options(supl-lpp-client PRIVATE  "-Wall" "-Wextra" "-pedantic" "-Werror" 
                                        "-fvisibility=hidden" "-Wno-missing-field-initializers" 
                                        "-Wformat" "-Wformat-signedness")
target_compile_options(supl-lpp-client PRIVATE "$<$<CONFIG:DEBUG>:${CLIENT_DEBUG_OPTIONS}>")
target_compile_options(supl-lpp-client PRIVATE "$<$<CONFIG:RELEASE>:${CLIENT_RELEASE_OPTIONS}>")

if(USE_ASAN)
    target_compile_options(supl-lpp-client PRIVATE -fsanitize=address)
    target_link_libraries(supl-lpp-client -fsanitize=address)
endif()

target_link_libraries(supl-lpp-client pthread)
target_link_libraries(supl-lpp-client rtcm_generator)
target_link_libraries(supl-lpp-client lpp)
target_link_libraries(supl-lpp-client modem)
target_link_libraries(supl-lpp-client m)
