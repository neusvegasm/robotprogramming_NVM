# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/build

# Include any dependencies generated for this target.
include CMakeFiles/btree_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/btree_library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/btree_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/btree_library.dir/flags.make

CMakeFiles/btree_library.dir/btree.cpp.o: CMakeFiles/btree_library.dir/flags.make
CMakeFiles/btree_library.dir/btree.cpp.o: ../btree.cpp
CMakeFiles/btree_library.dir/btree.cpp.o: CMakeFiles/btree_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/btree_library.dir/btree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btree_library.dir/btree.cpp.o -MF CMakeFiles/btree_library.dir/btree.cpp.o.d -o CMakeFiles/btree_library.dir/btree.cpp.o -c /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/btree.cpp

CMakeFiles/btree_library.dir/btree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btree_library.dir/btree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/btree.cpp > CMakeFiles/btree_library.dir/btree.cpp.i

CMakeFiles/btree_library.dir/btree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btree_library.dir/btree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/btree.cpp -o CMakeFiles/btree_library.dir/btree.cpp.s

# Object files for target btree_library
btree_library_OBJECTS = \
"CMakeFiles/btree_library.dir/btree.cpp.o"

# External object files for target btree_library
btree_library_EXTERNAL_OBJECTS =

libbtree_library.a: CMakeFiles/btree_library.dir/btree.cpp.o
libbtree_library.a: CMakeFiles/btree_library.dir/build.make
libbtree_library.a: CMakeFiles/btree_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbtree_library.a"
	$(CMAKE_COMMAND) -P CMakeFiles/btree_library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/btree_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/btree_library.dir/build: libbtree_library.a
.PHONY : CMakeFiles/btree_library.dir/build

CMakeFiles/btree_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/btree_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/btree_library.dir/clean

CMakeFiles/btree_library.dir/depend:
	cd /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/build /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/build /home/neusvegasm/gitrepo/exercises/rp_02_introduction_cpp/btree/build/CMakeFiles/btree_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/btree_library.dir/depend

