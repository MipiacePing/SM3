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
CMAKE_SOURCE_DIR = /mnt/d/junior_term2/创新实践/SM3/my_SM3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/junior_term2/创新实践/SM3/my_SM3

# Include any dependencies generated for this target.
include CMakeFiles/SM3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SM3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SM3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SM3.dir/flags.make

CMakeFiles/SM3.dir/mymain.cpp.o: CMakeFiles/SM3.dir/flags.make
CMakeFiles/SM3.dir/mymain.cpp.o: mymain.cpp
CMakeFiles/SM3.dir/mymain.cpp.o: CMakeFiles/SM3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/junior_term2/创新实践/SM3/my_SM3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SM3.dir/mymain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SM3.dir/mymain.cpp.o -MF CMakeFiles/SM3.dir/mymain.cpp.o.d -o CMakeFiles/SM3.dir/mymain.cpp.o -c /mnt/d/junior_term2/创新实践/SM3/my_SM3/mymain.cpp

CMakeFiles/SM3.dir/mymain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SM3.dir/mymain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/junior_term2/创新实践/SM3/my_SM3/mymain.cpp > CMakeFiles/SM3.dir/mymain.cpp.i

CMakeFiles/SM3.dir/mymain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SM3.dir/mymain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/junior_term2/创新实践/SM3/my_SM3/mymain.cpp -o CMakeFiles/SM3.dir/mymain.cpp.s

CMakeFiles/SM3.dir/mysm3.cpp.o: CMakeFiles/SM3.dir/flags.make
CMakeFiles/SM3.dir/mysm3.cpp.o: mysm3.cpp
CMakeFiles/SM3.dir/mysm3.cpp.o: CMakeFiles/SM3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/junior_term2/创新实践/SM3/my_SM3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SM3.dir/mysm3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SM3.dir/mysm3.cpp.o -MF CMakeFiles/SM3.dir/mysm3.cpp.o.d -o CMakeFiles/SM3.dir/mysm3.cpp.o -c /mnt/d/junior_term2/创新实践/SM3/my_SM3/mysm3.cpp

CMakeFiles/SM3.dir/mysm3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SM3.dir/mysm3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/junior_term2/创新实践/SM3/my_SM3/mysm3.cpp > CMakeFiles/SM3.dir/mysm3.cpp.i

CMakeFiles/SM3.dir/mysm3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SM3.dir/mysm3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/junior_term2/创新实践/SM3/my_SM3/mysm3.cpp -o CMakeFiles/SM3.dir/mysm3.cpp.s

# Object files for target SM3
SM3_OBJECTS = \
"CMakeFiles/SM3.dir/mymain.cpp.o" \
"CMakeFiles/SM3.dir/mysm3.cpp.o"

# External object files for target SM3
SM3_EXTERNAL_OBJECTS =

SM3: CMakeFiles/SM3.dir/mymain.cpp.o
SM3: CMakeFiles/SM3.dir/mysm3.cpp.o
SM3: CMakeFiles/SM3.dir/build.make
SM3: CMakeFiles/SM3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/junior_term2/创新实践/SM3/my_SM3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SM3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SM3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SM3.dir/build: SM3
.PHONY : CMakeFiles/SM3.dir/build

CMakeFiles/SM3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SM3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SM3.dir/clean

CMakeFiles/SM3.dir/depend:
	cd /mnt/d/junior_term2/创新实践/SM3/my_SM3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/junior_term2/创新实践/SM3/my_SM3 /mnt/d/junior_term2/创新实践/SM3/my_SM3 /mnt/d/junior_term2/创新实践/SM3/my_SM3 /mnt/d/junior_term2/创新实践/SM3/my_SM3 /mnt/d/junior_term2/创新实践/SM3/my_SM3/CMakeFiles/SM3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SM3.dir/depend

