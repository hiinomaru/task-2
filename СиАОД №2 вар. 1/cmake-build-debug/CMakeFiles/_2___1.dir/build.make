# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_2___1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/_2___1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_2___1.dir/flags.make

CMakeFiles/_2___1.dir/main.cpp.o: CMakeFiles/_2___1.dir/flags.make
CMakeFiles/_2___1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_2___1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_2___1.dir/main.cpp.o -c "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/main.cpp"

CMakeFiles/_2___1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_2___1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/main.cpp" > CMakeFiles/_2___1.dir/main.cpp.i

CMakeFiles/_2___1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_2___1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/main.cpp" -o CMakeFiles/_2___1.dir/main.cpp.s

# Object files for target _2___1
_2___1_OBJECTS = \
"CMakeFiles/_2___1.dir/main.cpp.o"

# External object files for target _2___1
_2___1_EXTERNAL_OBJECTS =

_2___1: CMakeFiles/_2___1.dir/main.cpp.o
_2___1: CMakeFiles/_2___1.dir/build.make
_2___1: CMakeFiles/_2___1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _2___1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_2___1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_2___1.dir/build: _2___1
.PHONY : CMakeFiles/_2___1.dir/build

CMakeFiles/_2___1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_2___1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_2___1.dir/clean

CMakeFiles/_2___1.dir/depend:
	cd "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1" "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1" "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug" "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug" "/Users/igorstarikov/CLionProjects/СиАОД №2 вар. 1/cmake-build-debug/CMakeFiles/_2___1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_2___1.dir/depend

