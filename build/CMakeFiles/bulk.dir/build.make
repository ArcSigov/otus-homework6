# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sigov/doc/otus-homework6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sigov/doc/otus-homework6/build

# Include any dependencies generated for this target.
include CMakeFiles/bulk.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bulk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bulk.dir/flags.make

CMakeFiles/bulk.dir/bulk.cpp.o: CMakeFiles/bulk.dir/flags.make
CMakeFiles/bulk.dir/bulk.cpp.o: ../bulk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sigov/doc/otus-homework6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bulk.dir/bulk.cpp.o"
	/usr/bin/clang++-6.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bulk.dir/bulk.cpp.o -c /home/sigov/doc/otus-homework6/bulk.cpp

CMakeFiles/bulk.dir/bulk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bulk.dir/bulk.cpp.i"
	/usr/bin/clang++-6.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sigov/doc/otus-homework6/bulk.cpp > CMakeFiles/bulk.dir/bulk.cpp.i

CMakeFiles/bulk.dir/bulk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bulk.dir/bulk.cpp.s"
	/usr/bin/clang++-6.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sigov/doc/otus-homework6/bulk.cpp -o CMakeFiles/bulk.dir/bulk.cpp.s

CMakeFiles/bulk.dir/bulk.cpp.o.requires:

.PHONY : CMakeFiles/bulk.dir/bulk.cpp.o.requires

CMakeFiles/bulk.dir/bulk.cpp.o.provides: CMakeFiles/bulk.dir/bulk.cpp.o.requires
	$(MAKE) -f CMakeFiles/bulk.dir/build.make CMakeFiles/bulk.dir/bulk.cpp.o.provides.build
.PHONY : CMakeFiles/bulk.dir/bulk.cpp.o.provides

CMakeFiles/bulk.dir/bulk.cpp.o.provides.build: CMakeFiles/bulk.dir/bulk.cpp.o


# Object files for target bulk
bulk_OBJECTS = \
"CMakeFiles/bulk.dir/bulk.cpp.o"

# External object files for target bulk
bulk_EXTERNAL_OBJECTS =

bulk: CMakeFiles/bulk.dir/bulk.cpp.o
bulk: CMakeFiles/bulk.dir/build.make
bulk: CMakeFiles/bulk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sigov/doc/otus-homework6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bulk"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bulk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bulk.dir/build: bulk

.PHONY : CMakeFiles/bulk.dir/build

CMakeFiles/bulk.dir/requires: CMakeFiles/bulk.dir/bulk.cpp.o.requires

.PHONY : CMakeFiles/bulk.dir/requires

CMakeFiles/bulk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bulk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bulk.dir/clean

CMakeFiles/bulk.dir/depend:
	cd /home/sigov/doc/otus-homework6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sigov/doc/otus-homework6 /home/sigov/doc/otus-homework6 /home/sigov/doc/otus-homework6/build /home/sigov/doc/otus-homework6/build /home/sigov/doc/otus-homework6/build/CMakeFiles/bulk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bulk.dir/depend

