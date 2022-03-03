cmake_minimum_required(VERSION 3.10)

project(modem VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MODEM_DEBUG_OPTIONS "-O0" "-g" "-DRELEASE=0" "-DDEBUG=1")
set(MODEM_RELEASE_OPTIONS "-O3" "-DRELEASE=1" "-DDEBUG=0")

list(APPEND modem_SOURCES 
    "include/modem.h"
    "src/modem.cpp"
)

add_library (modem STATIC ${modem_SOURCES})
target_include_directories(modem PRIVATE "include")
target_include_directories(modem PRIVATE "../${SHARED_PATH}")

target_compile_options(modem PRIVATE    "-Wall" "-Wextra" "-pedantic" "-Werror" 
                                        "-fvisibility=hidden" "-Wformat" "-Wformat-signedness")
target_compile_options(modem PRIVATE "$<$<CONFIG:DEBUG>:${MODEM_DEBUG_OPTIONS}>")
target_compile_options(modem PRIVATE "$<$<CONFIG:RELEASE>:${MODEM_RELEASE_OPTIONS}>")
target_compile_options(modem PRIVATE -latomic)

if(USE_ASAN)
    target_compile_options(modem PRIVATE -fsanitize=address)
    target_link_libraries(modem -fsanitize=address)
endif()
