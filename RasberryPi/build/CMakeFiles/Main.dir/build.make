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
CMAKE_SOURCE_DIR = /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/build

# Include any dependencies generated for this target.
include CMakeFiles/Main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.dir/flags.make

CMakeFiles/Main.dir/src/main.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Main.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/src/main.cpp.o -c /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/src/main.cpp

CMakeFiles/Main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/src/main.cpp > CMakeFiles/Main.dir/src/main.cpp.i

CMakeFiles/Main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/src/main.cpp -o CMakeFiles/Main.dir/src/main.cpp.s

CMakeFiles/Main.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Main.dir/src/main.cpp.o.requires

CMakeFiles/Main.dir/src/main.cpp.o.provides: CMakeFiles/Main.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Main.dir/src/main.cpp.o.provides

CMakeFiles/Main.dir/src/main.cpp.o.provides.build: CMakeFiles/Main.dir/src/main.cpp.o


# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/src/main.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

Main: CMakeFiles/Main.dir/src/main.cpp.o
Main: CMakeFiles/Main.dir/build.make
Main: /usr/local/lib/libopencv_dnn.so.4.1.1
Main: /usr/local/lib/libopencv_gapi.so.4.1.1
Main: /usr/local/lib/libopencv_highgui.so.4.1.1
Main: /usr/local/lib/libopencv_ml.so.4.1.1
Main: /usr/local/lib/libopencv_objdetect.so.4.1.1
Main: /usr/local/lib/libopencv_photo.so.4.1.1
Main: /usr/local/lib/libopencv_stitching.so.4.1.1
Main: /usr/local/lib/libopencv_video.so.4.1.1
Main: /usr/local/lib/libopencv_videoio.so.4.1.1
Main: /usr/local/lib/libopencv_imgcodecs.so.4.1.1
Main: /usr/local/lib/libopencv_calib3d.so.4.1.1
Main: /usr/local/lib/libopencv_features2d.so.4.1.1
Main: /usr/local/lib/libopencv_flann.so.4.1.1
Main: /usr/local/lib/libopencv_imgproc.so.4.1.1
Main: /usr/local/lib/libopencv_core.so.4.1.1
Main: CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.dir/build: Main

.PHONY : CMakeFiles/Main.dir/build

CMakeFiles/Main.dir/requires: CMakeFiles/Main.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/Main.dir/requires

CMakeFiles/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.dir/clean

CMakeFiles/Main.dir/depend:
	cd /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/build /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/build /home/hidetoniwa/Desktop/raspi-tracer/RasberryPi/build/CMakeFiles/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Main.dir/depend

