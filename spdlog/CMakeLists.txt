# fmt
find_package(fmt 6.0.0 QUIET)
if(fmt_FOUND)
  include_directories(SYSTEM "${fmt_INCLUDE_DIR}")
else(fmt_FOUND)
  message(FATAL_ERROR "fmt library not found")
endif(fmt_FOUND)

add_executable(spdlog_helloworld spdlog_helloworld.cc)
target_link_libraries(spdlog_helloworld PRIVATE fmt::fmt)