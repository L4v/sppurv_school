# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/hk-47/Downloads/_zips/_extracts/CLion-2018.3.4/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hk-47/Downloads/_zips/_extracts/CLion-2018.3.4/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vezba03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vezba03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vezba03.dir/flags.make

CMakeFiles/vezba03.dir/main.cpp.o: CMakeFiles/vezba03.dir/flags.make
CMakeFiles/vezba03.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vezba03.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vezba03.dir/main.cpp.o -c /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/main.cpp

CMakeFiles/vezba03.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vezba03.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/main.cpp > CMakeFiles/vezba03.dir/main.cpp.i

CMakeFiles/vezba03.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vezba03.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/main.cpp -o CMakeFiles/vezba03.dir/main.cpp.s

CMakeFiles/vezba03.dir/matrixFunctions.cpp.o: CMakeFiles/vezba03.dir/flags.make
CMakeFiles/vezba03.dir/matrixFunctions.cpp.o: ../matrixFunctions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vezba03.dir/matrixFunctions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vezba03.dir/matrixFunctions.cpp.o -c /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/matrixFunctions.cpp

CMakeFiles/vezba03.dir/matrixFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vezba03.dir/matrixFunctions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/matrixFunctions.cpp > CMakeFiles/vezba03.dir/matrixFunctions.cpp.i

CMakeFiles/vezba03.dir/matrixFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vezba03.dir/matrixFunctions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/matrixFunctions.cpp -o CMakeFiles/vezba03.dir/matrixFunctions.cpp.s

# Object files for target vezba03
vezba03_OBJECTS = \
"CMakeFiles/vezba03.dir/main.cpp.o" \
"CMakeFiles/vezba03.dir/matrixFunctions.cpp.o"

# External object files for target vezba03
vezba03_EXTERNAL_OBJECTS =

vezba03: CMakeFiles/vezba03.dir/main.cpp.o
vezba03: CMakeFiles/vezba03.dir/matrixFunctions.cpp.o
vezba03: CMakeFiles/vezba03.dir/build.make
vezba03: CMakeFiles/vezba03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable vezba03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vezba03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vezba03.dir/build: vezba03

.PHONY : CMakeFiles/vezba03.dir/build

CMakeFiles/vezba03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vezba03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vezba03.dir/clean

CMakeFiles/vezba03.dir/depend:
	cd /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03 /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03 /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/cmake-build-debug /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/cmake-build-debug /home/hk-47/workspace/sppurv/sppurv_school/_homework/vezba03/cmake-build-debug/CMakeFiles/vezba03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vezba03.dir/depend
