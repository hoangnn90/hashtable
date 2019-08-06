cmake_minimum_required (VERSION 2.6)
project (hashtable)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(src)
add_subdirectory(utest)



