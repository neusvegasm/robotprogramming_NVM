message("---------------------------------")
message(" Executing CMake ")
message("---------------------------------")


cmake_minimum_required(VERSION 2.8.3)
project(mini_core DESCRIPTION "Exercise rp01" LANGUAGES CXX)

# TODO invokes the routines to find a package called Eigen3
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

# add project source code
add_subdirectory(src)

# TODO do the same for executables
add_subdirectory(executables)

message("---------------------------------")
message(" CMake Completed")
message(" Project name: ${PROJECT_NAME}")
message("---------------------------------")