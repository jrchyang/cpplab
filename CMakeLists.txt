cmake_minimum_required(VERSION 3.10)

project(cpplab
  VERSION 0.0.1
  LANGUAGES CXX C)

if (NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message(FATAL_ERROR "This project only supports Linux. Current system: ${CMAKE_SYSTEM_NAME}")
endif()

# 设置 C++ 标准为 C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules/")

if(NOT CMAKE_BUILD_TYPE AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
  set(default_build_type "Debug")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Default BUILD_TYPE is Debug, other options are: RelWithDebInfo, Release, and MinSizeRel." FORCE)
endif()

option(ALGO "Build the algo directory" ON)
if(ALGO)
  add_subdirectory(algo)
endif()
