set(CMAKE_PREFIX_PATH "/home/jrchyang/open-srcs/seastar/build/release")
set(CMAKE_MODULE_PATH "/home/jrchyang/open-srcs/seastar/cmake")

find_package(Seastar REQUIRED)
find_package(Valgrind REQUIRED)

add_executable(helloworld helloworld.cpp)
target_link_libraries(helloworld PRIVATE Seastar::seastar)
