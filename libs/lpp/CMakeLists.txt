cmake_minimum_required(VERSION 3.10)
 
project(lpp VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(LPP_DEBUG_OPTIONS "-O0" "-g" "-DRELEASE=0" "-DDEBUG=1")
set(LPP_RELEASE_OPTIONS "-O3" "-DRELEASE=1" "-DDEBUG=0")

if(USE_OPENSSL)
    find_package(OpenSSL REQUIRED)
endif()

list(APPEND lpp_SOURCES 
    "include/asn_helper.h"
    "include/asnlib.h"
    "include/internal_lpp.h"
    "include/lpp.h"
    "include/supl.h"
    "include/tcp.h"
    "src/asn_helper.cpp"
    "src/assistance_data.cpp"
    "src/capabilities.cpp"
    "src/gather.cpp"
    "src/internal_lpp.cpp"
    "src/lpp.cpp"
    "src/supl.cpp"
    "src/tcp.cpp"
)

add_library (lpp STATIC ${lpp_SOURCES})
target_include_directories(lpp PRIVATE "include")
target_include_directories(lpp PRIVATE "../${RTKLIB_INCLUDE_PATH}")
target_include_directories(lpp PRIVATE "../${ASNLIB_INCLUDE_PATH}")
target_include_directories(lpp PRIVATE "../${SHARED_PATH}")

target_link_libraries(lpp rtklib)
target_link_libraries(lpp asnlib)

target_compile_options(lpp PRIVATE  "-Wall" "-Wextra" "-pedantic" "-Werror" 
                                    "-fvisibility=hidden" "-Wformat" "-Wformat-signedness")
target_compile_options(lpp PRIVATE "$<$<CONFIG:DEBUG>:${LPP_DEBUG_OPTIONS}>")
target_compile_options(lpp PRIVATE "$<$<CONFIG:RELEASE>:${LPP_RELEASE_OPTIONS}>")

if(USE_OPENSSL)
    target_link_libraries(lpp OpenSSL::SSL)
endif()

if(USE_ASAN)
    target_compile_options(lpp PRIVATE -fsanitize=address)
    target_link_libraries(lpp -fsanitize=address)
endif()
