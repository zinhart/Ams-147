# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ogun/Desktop/ams147-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ogun/Desktop/ams147-project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/net.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/net.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/net.dir/flags.make

src/CMakeFiles/net.dir/Net.cpp.o: src/CMakeFiles/net.dir/flags.make
src/CMakeFiles/net.dir/Net.cpp.o: ../src/Net.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ogun/Desktop/ams147-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/net.dir/Net.cpp.o"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/Net.cpp.o -c /home/ogun/Desktop/ams147-project/src/Net.cpp

src/CMakeFiles/net.dir/Net.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/Net.cpp.i"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ogun/Desktop/ams147-project/src/Net.cpp > CMakeFiles/net.dir/Net.cpp.i

src/CMakeFiles/net.dir/Net.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/Net.cpp.s"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ogun/Desktop/ams147-project/src/Net.cpp -o CMakeFiles/net.dir/Net.cpp.s

src/CMakeFiles/net.dir/Net.cpp.o.requires:

.PHONY : src/CMakeFiles/net.dir/Net.cpp.o.requires

src/CMakeFiles/net.dir/Net.cpp.o.provides: src/CMakeFiles/net.dir/Net.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/net.dir/build.make src/CMakeFiles/net.dir/Net.cpp.o.provides.build
.PHONY : src/CMakeFiles/net.dir/Net.cpp.o.provides

src/CMakeFiles/net.dir/Net.cpp.o.provides.build: src/CMakeFiles/net.dir/Net.cpp.o


src/CMakeFiles/net.dir/TrainingData.cpp.o: src/CMakeFiles/net.dir/flags.make
src/CMakeFiles/net.dir/TrainingData.cpp.o: ../src/TrainingData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ogun/Desktop/ams147-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/net.dir/TrainingData.cpp.o"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/TrainingData.cpp.o -c /home/ogun/Desktop/ams147-project/src/TrainingData.cpp

src/CMakeFiles/net.dir/TrainingData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/TrainingData.cpp.i"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ogun/Desktop/ams147-project/src/TrainingData.cpp > CMakeFiles/net.dir/TrainingData.cpp.i

src/CMakeFiles/net.dir/TrainingData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/TrainingData.cpp.s"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ogun/Desktop/ams147-project/src/TrainingData.cpp -o CMakeFiles/net.dir/TrainingData.cpp.s

src/CMakeFiles/net.dir/TrainingData.cpp.o.requires:

.PHONY : src/CMakeFiles/net.dir/TrainingData.cpp.o.requires

src/CMakeFiles/net.dir/TrainingData.cpp.o.provides: src/CMakeFiles/net.dir/TrainingData.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/net.dir/build.make src/CMakeFiles/net.dir/TrainingData.cpp.o.provides.build
.PHONY : src/CMakeFiles/net.dir/TrainingData.cpp.o.provides

src/CMakeFiles/net.dir/TrainingData.cpp.o.provides.build: src/CMakeFiles/net.dir/TrainingData.cpp.o


src/CMakeFiles/net.dir/Neuron.cpp.o: src/CMakeFiles/net.dir/flags.make
src/CMakeFiles/net.dir/Neuron.cpp.o: ../src/Neuron.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ogun/Desktop/ams147-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/net.dir/Neuron.cpp.o"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/net.dir/Neuron.cpp.o -c /home/ogun/Desktop/ams147-project/src/Neuron.cpp

src/CMakeFiles/net.dir/Neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/net.dir/Neuron.cpp.i"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ogun/Desktop/ams147-project/src/Neuron.cpp > CMakeFiles/net.dir/Neuron.cpp.i

src/CMakeFiles/net.dir/Neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/net.dir/Neuron.cpp.s"
	cd /home/ogun/Desktop/ams147-project/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ogun/Desktop/ams147-project/src/Neuron.cpp -o CMakeFiles/net.dir/Neuron.cpp.s

src/CMakeFiles/net.dir/Neuron.cpp.o.requires:

.PHONY : src/CMakeFiles/net.dir/Neuron.cpp.o.requires

src/CMakeFiles/net.dir/Neuron.cpp.o.provides: src/CMakeFiles/net.dir/Neuron.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/net.dir/build.make src/CMakeFiles/net.dir/Neuron.cpp.o.provides.build
.PHONY : src/CMakeFiles/net.dir/Neuron.cpp.o.provides

src/CMakeFiles/net.dir/Neuron.cpp.o.provides.build: src/CMakeFiles/net.dir/Neuron.cpp.o


# Object files for target net
net_OBJECTS = \
"CMakeFiles/net.dir/Net.cpp.o" \
"CMakeFiles/net.dir/TrainingData.cpp.o" \
"CMakeFiles/net.dir/Neuron.cpp.o"

# External object files for target net
net_EXTERNAL_OBJECTS =

src/libnet.a: src/CMakeFiles/net.dir/Net.cpp.o
src/libnet.a: src/CMakeFiles/net.dir/TrainingData.cpp.o
src/libnet.a: src/CMakeFiles/net.dir/Neuron.cpp.o
src/libnet.a: src/CMakeFiles/net.dir/build.make
src/libnet.a: src/CMakeFiles/net.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ogun/Desktop/ams147-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libnet.a"
	cd /home/ogun/Desktop/ams147-project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/net.dir/cmake_clean_target.cmake
	cd /home/ogun/Desktop/ams147-project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/net.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/net.dir/build: src/libnet.a

.PHONY : src/CMakeFiles/net.dir/build

src/CMakeFiles/net.dir/requires: src/CMakeFiles/net.dir/Net.cpp.o.requires
src/CMakeFiles/net.dir/requires: src/CMakeFiles/net.dir/TrainingData.cpp.o.requires
src/CMakeFiles/net.dir/requires: src/CMakeFiles/net.dir/Neuron.cpp.o.requires

.PHONY : src/CMakeFiles/net.dir/requires

src/CMakeFiles/net.dir/clean:
	cd /home/ogun/Desktop/ams147-project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/net.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/net.dir/clean

src/CMakeFiles/net.dir/depend:
	cd /home/ogun/Desktop/ams147-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ogun/Desktop/ams147-project /home/ogun/Desktop/ams147-project/src /home/ogun/Desktop/ams147-project/build /home/ogun/Desktop/ams147-project/build/src /home/ogun/Desktop/ams147-project/build/src/CMakeFiles/net.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/net.dir/depend
