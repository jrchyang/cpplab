cmake_minimum_required(VERSION 3.10)

project(cpplab
  VERSION 0.0.1
  LANGUAGES CXX C)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux" AND NOT CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  message(FATAL_ERROR "This project requires Linux or MacOS operating system.")
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

include_directories(${CMAKE_SOURCE_DIR}/include)

# Boost
option(WITH_SYSTEM_BOOST "require and build with system Boost" ON)

## Boost::thread depends on Boost::atomic, so list it explicitly.
set(BOOST_COMPONENTS
  atomic chrono thread system regex random program_options date_time
  iostreams context coroutine timer filesystem)
set(BOOST_HEADER_COMPONENTS container)

set(Boost_USE_MULTITHREADED ON)
# require minimally the bundled version
if(WITH_SYSTEM_BOOST)
  if(ENABLE_SHARED)
    set(Boost_USE_STATIC_LIBS OFF)
  else()
    set(Boost_USE_STATIC_LIBS ON)
  endif()
  if(BOOST_ROOT AND CMAKE_LIBRARY_ARCHITECTURE)
    set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib/${CMAKE_LIBRARY_ARCHITECTURE}")
  endif()
  find_package(Boost 1.73 COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
  if(NOT ENABLE_SHARED)
    set_property(TARGET Boost::iostreams APPEND PROPERTY
      INTERFACE_LINK_LIBRARIES ZLIB::ZLIB)
  endif()
else()
  set(BOOST_J 1 CACHE STRING
    "max jobs for Boost build") # override w/-DBOOST_J=<n>
  set(Boost_USE_STATIC_LIBS ON)
  include(BuildBoost)
  build_boost(1.75
    COMPONENTS ${BOOST_COMPONENTS} ${BOOST_HEADER_COMPONENTS})
endif()
include_directories(BEFORE SYSTEM ${Boost_INCLUDE_DIRS})
add_definitions(-DBOOST_ASIO_DISABLE_THREAD_KEYWORD_EXTENSION)
if(Boost_VERSION VERSION_GREATER_EQUAL 1.74)
  add_definitions(-DBOOST_ASIO_USE_TS_EXECUTOR_AS_DEFAULT)
endif()
list(APPEND target_deps
  Boost::thread
  Boost::system
  Boost::random
  Boost::program_options
  Boost::date_time
  Boost::iostreams
  Boost::filesystem)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fpermissive>)

option(SYNTAX "Build the syntax directory" ON)
if(SYNTAX)
  add_subdirectory(syntax)
endif()

option(STL "Build the stl directory" ON)
if(STL)
  add_subdirectory(stl)
endif()

option(ALGO "Build the algo directory" ON)
if(ALGO)
  add_subdirectory(algo)
endif()

option(BOOST "Build the boost directory" ON)
if(BOOST)
  add_subdirectory(boost)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")

option(SEASTAR "Build the seastar directory" ON)
if(SEASTAR)
  add_subdirectory(seastar)
endif()

option(SPDLOG "Build the spdlog directory" ON)
if(SPDLOG)
  add_subdirectory(spdlog)
endif()

endif()
