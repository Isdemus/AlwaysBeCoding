cmake_minimum_required (VERSION 2.6)
project (Testing)

add_executable (Testing test.cpp)
target_link_libraries (Testing)

install (TARGETS Testing DESTINATION bin)
