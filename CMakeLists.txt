cmake_minimum_required(VERSION 3.5)

project(cpplab
  VERSION 0.0.1
  LANGUAGES CXX C)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message(FATAL_ERROR "This project requires Linux operating system.")
endif()

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

if(NOT CMAKE_BUILD_TYPE AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
  set(default_build_type "Debug")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Default BUILD_TYPE is Debug, other options are: RelWithDebInfo, Release, and MinSizeRel." FORCE)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

option(ALGO "Build the algo directory" ON)
option(BOOST "Build the boost directory" ON)
option(SYNTAX "Build the syntax directory" ON)
option(SEASTAR "Build the seastar directory" ON)

if(ALGO)
  add_subdirectory(algo)
endif()

if(BOOST)
  add_subdirectory(boost)
endif()

if(SYNTAX)
  add_subdirectory(syntax)
endif()

if(SEASTAR)
  add_subdirectory(seastar)
endif()
