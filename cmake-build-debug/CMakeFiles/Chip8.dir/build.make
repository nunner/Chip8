# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/nun/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7479.33/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nun/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7479.33/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nun/Programming/C/Chip8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nun/Programming/C/Chip8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Chip8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chip8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chip8.dir/flags.make

CMakeFiles/Chip8.dir/src/main.c.o: CMakeFiles/Chip8.dir/flags.make
CMakeFiles/Chip8.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nun/Programming/C/Chip8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Chip8.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Chip8.dir/src/main.c.o   -c /home/nun/Programming/C/Chip8/src/main.c

CMakeFiles/Chip8.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Chip8.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nun/Programming/C/Chip8/src/main.c > CMakeFiles/Chip8.dir/src/main.c.i

CMakeFiles/Chip8.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Chip8.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nun/Programming/C/Chip8/src/main.c -o CMakeFiles/Chip8.dir/src/main.c.s

CMakeFiles/Chip8.dir/src/cpu.c.o: CMakeFiles/Chip8.dir/flags.make
CMakeFiles/Chip8.dir/src/cpu.c.o: ../src/cpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nun/Programming/C/Chip8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Chip8.dir/src/cpu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Chip8.dir/src/cpu.c.o   -c /home/nun/Programming/C/Chip8/src/cpu.c

CMakeFiles/Chip8.dir/src/cpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Chip8.dir/src/cpu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nun/Programming/C/Chip8/src/cpu.c > CMakeFiles/Chip8.dir/src/cpu.c.i

CMakeFiles/Chip8.dir/src/cpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Chip8.dir/src/cpu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nun/Programming/C/Chip8/src/cpu.c -o CMakeFiles/Chip8.dir/src/cpu.c.s

CMakeFiles/Chip8.dir/src/codes.c.o: CMakeFiles/Chip8.dir/flags.make
CMakeFiles/Chip8.dir/src/codes.c.o: ../src/codes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nun/Programming/C/Chip8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Chip8.dir/src/codes.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Chip8.dir/src/codes.c.o   -c /home/nun/Programming/C/Chip8/src/codes.c

CMakeFiles/Chip8.dir/src/codes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Chip8.dir/src/codes.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nun/Programming/C/Chip8/src/codes.c > CMakeFiles/Chip8.dir/src/codes.c.i

CMakeFiles/Chip8.dir/src/codes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Chip8.dir/src/codes.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nun/Programming/C/Chip8/src/codes.c -o CMakeFiles/Chip8.dir/src/codes.c.s

# Object files for target Chip8
Chip8_OBJECTS = \
"CMakeFiles/Chip8.dir/src/main.c.o" \
"CMakeFiles/Chip8.dir/src/cpu.c.o" \
"CMakeFiles/Chip8.dir/src/codes.c.o"

# External object files for target Chip8
Chip8_EXTERNAL_OBJECTS =

Chip8: CMakeFiles/Chip8.dir/src/main.c.o
Chip8: CMakeFiles/Chip8.dir/src/cpu.c.o
Chip8: CMakeFiles/Chip8.dir/src/codes.c.o
Chip8: CMakeFiles/Chip8.dir/build.make
Chip8: CMakeFiles/Chip8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nun/Programming/C/Chip8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Chip8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chip8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chip8.dir/build: Chip8

.PHONY : CMakeFiles/Chip8.dir/build

CMakeFiles/Chip8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chip8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chip8.dir/clean

CMakeFiles/Chip8.dir/depend:
	cd /home/nun/Programming/C/Chip8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nun/Programming/C/Chip8 /home/nun/Programming/C/Chip8 /home/nun/Programming/C/Chip8/cmake-build-debug /home/nun/Programming/C/Chip8/cmake-build-debug /home/nun/Programming/C/Chip8/cmake-build-debug/CMakeFiles/Chip8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Chip8.dir/depend

