# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\github\234123\ex3\Code_Skeleton

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\github\234123\ex3\Code_Skeleton\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Code_Skeleton.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Code_Skeleton.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Code_Skeleton.dir/flags.make

CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj: CMakeFiles/Code_Skeleton.dir/flags.make
CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj: CMakeFiles/Code_Skeleton.dir/includes_CXX.rsp
CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj: ../Part2/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\234123\ex3\Code_Skeleton\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj"
	D:\TDM-GCC-64\bin\c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Code_Skeleton.dir\Part2\Game.cpp.obj -c D:\github\234123\ex3\Code_Skeleton\Part2\Game.cpp

CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.i"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\234123\ex3\Code_Skeleton\Part2\Game.cpp > CMakeFiles\Code_Skeleton.dir\Part2\Game.cpp.i

CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.s"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\234123\ex3\Code_Skeleton\Part2\Game.cpp -o CMakeFiles\Code_Skeleton.dir\Part2\Game.cpp.s

CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj.requires:

.PHONY : CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj.requires

CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj.provides: CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Code_Skeleton.dir\build.make CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj.provides.build
.PHONY : CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj.provides

CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj.provides.build: CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj


CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj: CMakeFiles/Code_Skeleton.dir/flags.make
CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj: CMakeFiles/Code_Skeleton.dir/includes_CXX.rsp
CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj: ../Part2/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\234123\ex3\Code_Skeleton\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj"
	D:\TDM-GCC-64\bin\c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Code_Skeleton.dir\Part2\main.cpp.obj -c D:\github\234123\ex3\Code_Skeleton\Part2\main.cpp

CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.i"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\234123\ex3\Code_Skeleton\Part2\main.cpp > CMakeFiles\Code_Skeleton.dir\Part2\main.cpp.i

CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.s"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\234123\ex3\Code_Skeleton\Part2\main.cpp -o CMakeFiles\Code_Skeleton.dir\Part2\main.cpp.s

CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj.requires:

.PHONY : CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj.requires

CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj.provides: CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Code_Skeleton.dir\build.make CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj.provides

CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj.provides.build: CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj


CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj: CMakeFiles/Code_Skeleton.dir/flags.make
CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj: CMakeFiles/Code_Skeleton.dir/includes_CXX.rsp
CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj: ../Part2/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\234123\ex3\Code_Skeleton\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj"
	D:\TDM-GCC-64\bin\c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Code_Skeleton.dir\Part2\utils.cpp.obj -c D:\github\234123\ex3\Code_Skeleton\Part2\utils.cpp

CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.i"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\234123\ex3\Code_Skeleton\Part2\utils.cpp > CMakeFiles\Code_Skeleton.dir\Part2\utils.cpp.i

CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.s"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\234123\ex3\Code_Skeleton\Part2\utils.cpp -o CMakeFiles\Code_Skeleton.dir\Part2\utils.cpp.s

CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj.requires:

.PHONY : CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj.requires

CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj.provides: CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Code_Skeleton.dir\build.make CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj.provides.build
.PHONY : CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj.provides

CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj.provides.build: CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj


# Object files for target Code_Skeleton
Code_Skeleton_OBJECTS = \
"CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj" \
"CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj" \
"CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj"

# External object files for target Code_Skeleton
Code_Skeleton_EXTERNAL_OBJECTS =

Code_Skeleton.exe: CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj
Code_Skeleton.exe: CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj
Code_Skeleton.exe: CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj
Code_Skeleton.exe: CMakeFiles/Code_Skeleton.dir/build.make
Code_Skeleton.exe: CMakeFiles/Code_Skeleton.dir/linklibs.rsp
Code_Skeleton.exe: CMakeFiles/Code_Skeleton.dir/objects1.rsp
Code_Skeleton.exe: CMakeFiles/Code_Skeleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\234123\ex3\Code_Skeleton\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Code_Skeleton.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Code_Skeleton.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Code_Skeleton.dir/build: Code_Skeleton.exe

.PHONY : CMakeFiles/Code_Skeleton.dir/build

CMakeFiles/Code_Skeleton.dir/requires: CMakeFiles/Code_Skeleton.dir/Part2/Game.cpp.obj.requires
CMakeFiles/Code_Skeleton.dir/requires: CMakeFiles/Code_Skeleton.dir/Part2/main.cpp.obj.requires
CMakeFiles/Code_Skeleton.dir/requires: CMakeFiles/Code_Skeleton.dir/Part2/utils.cpp.obj.requires

.PHONY : CMakeFiles/Code_Skeleton.dir/requires

CMakeFiles/Code_Skeleton.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Code_Skeleton.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Code_Skeleton.dir/clean

CMakeFiles/Code_Skeleton.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\234123\ex3\Code_Skeleton D:\github\234123\ex3\Code_Skeleton D:\github\234123\ex3\Code_Skeleton\cmake-build-debug D:\github\234123\ex3\Code_Skeleton\cmake-build-debug D:\github\234123\ex3\Code_Skeleton\cmake-build-debug\CMakeFiles\Code_Skeleton.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Code_Skeleton.dir/depend

