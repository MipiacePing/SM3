# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/build

# Include any dependencies generated for this target.
include CMakeFiles/SM3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SM3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SM3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SM3.dir/flags.make

CMakeFiles/SM3.dir/main.cpp.o: CMakeFiles/SM3.dir/flags.make
CMakeFiles/SM3.dir/main.cpp.o: /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/main.cpp
CMakeFiles/SM3.dir/main.cpp.o: CMakeFiles/SM3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SM3.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SM3.dir/main.cpp.o -MF CMakeFiles/SM3.dir/main.cpp.o.d -o CMakeFiles/SM3.dir/main.cpp.o -c /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/main.cpp

CMakeFiles/SM3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SM3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/main.cpp > CMakeFiles/SM3.dir/main.cpp.i

CMakeFiles/SM3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SM3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/main.cpp -o CMakeFiles/SM3.dir/main.cpp.s

CMakeFiles/SM3.dir/sm3/sm3.c.o: CMakeFiles/SM3.dir/flags.make
CMakeFiles/SM3.dir/sm3/sm3.c.o: /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/sm3/sm3.c
CMakeFiles/SM3.dir/sm3/sm3.c.o: CMakeFiles/SM3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SM3.dir/sm3/sm3.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SM3.dir/sm3/sm3.c.o -MF CMakeFiles/SM3.dir/sm3/sm3.c.o.d -o CMakeFiles/SM3.dir/sm3/sm3.c.o -c /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/sm3/sm3.c

CMakeFiles/SM3.dir/sm3/sm3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SM3.dir/sm3/sm3.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/sm3/sm3.c > CMakeFiles/SM3.dir/sm3/sm3.c.i

CMakeFiles/SM3.dir/sm3/sm3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SM3.dir/sm3/sm3.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/sm3/sm3.c -o CMakeFiles/SM3.dir/sm3/sm3.c.s

# Object files for target SM3
SM3_OBJECTS = \
"CMakeFiles/SM3.dir/main.cpp.o" \
"CMakeFiles/SM3.dir/sm3/sm3.c.o"

# External object files for target SM3
SM3_EXTERNAL_OBJECTS =

SM3: CMakeFiles/SM3.dir/main.cpp.o
SM3: CMakeFiles/SM3.dir/sm3/sm3.c.o
SM3: CMakeFiles/SM3.dir/build.make
SM3: CMakeFiles/SM3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SM3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SM3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SM3.dir/build: SM3
.PHONY : CMakeFiles/SM3.dir/build

CMakeFiles/SM3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SM3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SM3.dir/clean

CMakeFiles/SM3.dir/depend:
	cd /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/build /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/build /mnt/d/junior_term2/创新实践/SM3/SM3-openSSL/build/CMakeFiles/SM3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SM3.dir/depend

