cmake_minimum_required (VERSION 3.10)
project (yaml-parser)  # change name as required

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_library(yaml-parser STATIC ${SOURCES})

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O2 -Wall -Wextra -pedantic -lyaml-cpp")
endif ()

SET(GCC_COVERAGE_COMPILE_FLAGS "")
SET(GCC_COVERAGE_LINK_FLAGS    "")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
