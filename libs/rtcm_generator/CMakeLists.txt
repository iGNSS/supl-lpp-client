cmake_minimum_required(VERSION 3.10)

project(rtcm_generator VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(RTCM_GENERATOR_DEBUG_OPTIONS "-O0" "-g" "-DRELEASE=0" "-DDEBUG=1")
set(RTCM_GENERATOR_RELEASE_OPTIONS "-O3" "-DRELEASE=1" "-DDEBUG=0")

list(APPEND rtcm_generator_SOURCES 
    "include/lpp2osr.h"
    "include/osr2rtcm.h"
    "include/osr2rtklib.h"
    "include/osr.h"
    "include/rtcm_generator.h"
    "src/lpp2osr.cpp"
    "src/osr2rtcm.cpp"
    "src/osr2rtklib.cpp"
    "src/osr.cpp"
    "src/rtcm_generator.cpp"
)

add_library (rtcm_generator STATIC ${rtcm_generator_SOURCES})
target_include_directories(rtcm_generator PRIVATE "include")
target_include_directories(rtcm_generator PRIVATE "../${RTKLIB_INCLUDE_PATH}")
target_include_directories(rtcm_generator PRIVATE "../${ASNLIB_INCLUDE_PATH}")
target_include_directories(rtcm_generator PRIVATE "../${LPP_INCLUDE_PATH}")
target_include_directories(rtcm_generator PRIVATE "../${SHARED_PATH}")

target_compile_options(rtcm_generator PRIVATE "-Wall" "-Wextra" "-pedantic" "-Werror" "-fvisibility=hidden" "-Wno-missing-field-initializers")
target_compile_options(rtcm_generator PRIVATE "$<$<CONFIG:DEBUG>:${RTCM_GENERATOR_DEBUG_OPTIONS}>")
target_compile_options(rtcm_generator PRIVATE "$<$<CONFIG:RELEASE>:${RTCM_GENERATOR_RELEASE_OPTIONS}>")

target_link_libraries(rtcm_generator rtklib)
target_link_libraries(rtcm_generator asnlib)

if(USE_ASAN)
    target_compile_options(rtcm_generator PRIVATE -fsanitize=address)
    target_link_libraries(rtcm_generator -fsanitize=address)
endif()