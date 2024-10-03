message("---------------------------------")
message(" Executing CMake ")
message("---------------------------------")

# Minimum required versio n= my version installed
cmake_minimum_required(VERSION 3.30.4)

# Name of the project
project (helloworld_program DESCRIPTION "Hello Wrld cmake Example" LANGUAGES CXX)

# We can add here packages (by default this 2)
#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)

# We need to add all the paths for the previous packages PACKAGENAME_INCLUDE_DIRS
#include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Generate the executable, we can either writte the name of the project or use the variable ${PROJECT_NAME} that stores automatically the project name set in project ()
# After the name we add the dependent files (if we are not in the same directory we must add the path, example: ${PROJECT_SOURCE_DIR}/src/file.cpp) 
add_executable(${PROJECT_NAME} hello_world.cpp)

# If we have header files we need to include the path using:
# target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/headers)

# If we need libraries we tell the executable which it needs
#target_link_libraries(${PROJECT_NAME}
#    ${OPENGL_gl_LIBRARY}
#    ${OPENGL_glu_LIBRARY}
#    ${GLUT_glut_LIBRARY}
#    m
#)

message("---------------------------------")
message(" CMake Completed")
message(" Project name: ${PROJECT_NAME}")
message("---------------------------------")
