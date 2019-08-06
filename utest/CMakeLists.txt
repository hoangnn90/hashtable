cmake_minimum_required(VERSION 2.6)

project(hashtable_utest)

SET(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

set(SOURCE_CODE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src)

include_directories(${SOURCE_CODE_DIR})

file(GLOB SOURCES *.cpp ${SOURCE_CODE_DIR}/*.cpp)
list(REMOVE_ITEM SOURCES ${SOURCE_CODE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gmock pthread)

