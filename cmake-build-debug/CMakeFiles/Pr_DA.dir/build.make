# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /cygdrive/c/Users/Miguerubsk/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Miguerubsk/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Pr_DA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pr_DA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pr_DA.dir/flags.make

CMakeFiles/Pr_DA.dir/main.c.o: CMakeFiles/Pr_DA.dir/flags.make
CMakeFiles/Pr_DA.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Pr_DA.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Pr_DA.dir/main.c.o   -c /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/main.c

CMakeFiles/Pr_DA.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Pr_DA.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/main.c > CMakeFiles/Pr_DA.dir/main.c.i

CMakeFiles/Pr_DA.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Pr_DA.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/main.c -o CMakeFiles/Pr_DA.dir/main.c.s

CMakeFiles/Pr_DA.dir/main.c.o.requires:

.PHONY : CMakeFiles/Pr_DA.dir/main.c.o.requires

CMakeFiles/Pr_DA.dir/main.c.o.provides: CMakeFiles/Pr_DA.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Pr_DA.dir/build.make CMakeFiles/Pr_DA.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Pr_DA.dir/main.c.o.provides

CMakeFiles/Pr_DA.dir/main.c.o.provides.build: CMakeFiles/Pr_DA.dir/main.c.o


# Object files for target Pr_DA
Pr_DA_OBJECTS = \
"CMakeFiles/Pr_DA.dir/main.c.o"

# External object files for target Pr_DA
Pr_DA_EXTERNAL_OBJECTS =

Pr_DA.exe: CMakeFiles/Pr_DA.dir/main.c.o
Pr_DA.exe: CMakeFiles/Pr_DA.dir/build.make
Pr_DA.exe: CMakeFiles/Pr_DA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Pr_DA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pr_DA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pr_DA.dir/build: Pr_DA.exe

.PHONY : CMakeFiles/Pr_DA.dir/build

CMakeFiles/Pr_DA.dir/requires: CMakeFiles/Pr_DA.dir/main.c.o.requires

.PHONY : CMakeFiles/Pr_DA.dir/requires

CMakeFiles/Pr_DA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pr_DA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pr_DA.dir/clean

CMakeFiles/Pr_DA.dir/depend:
	cd /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/cmake-build-debug /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/cmake-build-debug /cygdrive/e/Users/Miguerubsk/Documents/GitHub/Pr_DA/cmake-build-debug/CMakeFiles/Pr_DA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pr_DA.dir/depend

