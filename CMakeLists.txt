cmake_minimum_required (VERSION 3.10)
project (yaml-parser)  # change name as required

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "Setting CXX Standard to : ${CMAKE_CXX_STANDARD}")


if (CMAKE_BUILD_TYPE STREQUAL "")
    message(STATUS "CMAKE_BUILD_TYPE not defined, 'Release' will be used")
    set(CMAKE_BUILD_TYPE "Release")
endif()

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_library(yaml-parser STATIC ${SOURCES})

# for testing 
add_executable(yamlparser ${SOURCES})

set_target_properties(yaml-parser PROPERTIES PUBLIC_HEADER "./include/YamlParser.hpp")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Compiler Detected as ${CMAKE_CXX_COMPILER_ID} ")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -pedantic")
    message(STATUS "Setting CXX_COMPILER_FLAGS -O2 -Wall -Wextra -pedantic")

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
message(STATUS "Compiler Detected as ${CMAKE_CXX_COMPILER_ID} ")

endif ()

SET(GCC_COVERAGE_COMPILE_FLAGS "")
SET(GCC_COVERAGE_LINK_FLAGS    "")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
set(ARCHIVE_OUTPUT_PATH "${CMAKE_BINARY_DIR/lib}")

if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
    set(CMAKE_INSTALL_PREFIX /usr/include )
    message( STATUS "Setting Installation location to ${CMAKE_INSTALL_PREFIX}")
elseif(WIN32)
    message("This is a Windows System")
endif()


install(TARGETS yaml-parser
    EXPORT yaml-parser
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}
    )

install(EXPORT yaml-parser DESTINATION ${CMAKE_INSTALL_PREFIX})
