set(CMAKE_PREFIX_PATH "/home/jrchyang/open-srcs/seastar/build/release")
set(CMAKE_MODULE_PATH "/home/jrchyang/open-srcs/seastar/cmake")

find_package(Seastar REQUIRED)
find_package(Valgrind REQUIRED)

add_executable(seastar_helloworld seastar_helloworld.cc)
target_link_libraries(seastar_helloworld PRIVATE Seastar::seastar)
