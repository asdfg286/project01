# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/0_wsl_workspace/project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/0_wsl_workspace/project1/build

# Include any dependencies generated for this target.
include CMakeFiles/tjurm_tutorial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tjurm_tutorial.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tjurm_tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tjurm_tutorial.dir/flags.make

CMakeFiles/tjurm_tutorial.dir/main.cc.o: CMakeFiles/tjurm_tutorial.dir/flags.make
CMakeFiles/tjurm_tutorial.dir/main.cc.o: ../main.cc
CMakeFiles/tjurm_tutorial.dir/main.cc.o: CMakeFiles/tjurm_tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/0_wsl_workspace/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tjurm_tutorial.dir/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tjurm_tutorial.dir/main.cc.o -MF CMakeFiles/tjurm_tutorial.dir/main.cc.o.d -o CMakeFiles/tjurm_tutorial.dir/main.cc.o -c /mnt/d/0_wsl_workspace/project1/main.cc

CMakeFiles/tjurm_tutorial.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tjurm_tutorial.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/0_wsl_workspace/project1/main.cc > CMakeFiles/tjurm_tutorial.dir/main.cc.i

CMakeFiles/tjurm_tutorial.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tjurm_tutorial.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/0_wsl_workspace/project1/main.cc -o CMakeFiles/tjurm_tutorial.dir/main.cc.s

CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o: CMakeFiles/tjurm_tutorial.dir/flags.make
CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o: ../src/Contours.cc
CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o: CMakeFiles/tjurm_tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/0_wsl_workspace/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o -MF CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o.d -o CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o -c /mnt/d/0_wsl_workspace/project1/src/Contours.cc

CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/0_wsl_workspace/project1/src/Contours.cc > CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.i

CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/0_wsl_workspace/project1/src/Contours.cc -o CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.s

CMakeFiles/tjurm_tutorial.dir/src/base.cc.o: CMakeFiles/tjurm_tutorial.dir/flags.make
CMakeFiles/tjurm_tutorial.dir/src/base.cc.o: ../src/base.cc
CMakeFiles/tjurm_tutorial.dir/src/base.cc.o: CMakeFiles/tjurm_tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/0_wsl_workspace/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tjurm_tutorial.dir/src/base.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tjurm_tutorial.dir/src/base.cc.o -MF CMakeFiles/tjurm_tutorial.dir/src/base.cc.o.d -o CMakeFiles/tjurm_tutorial.dir/src/base.cc.o -c /mnt/d/0_wsl_workspace/project1/src/base.cc

CMakeFiles/tjurm_tutorial.dir/src/base.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tjurm_tutorial.dir/src/base.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/0_wsl_workspace/project1/src/base.cc > CMakeFiles/tjurm_tutorial.dir/src/base.cc.i

CMakeFiles/tjurm_tutorial.dir/src/base.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tjurm_tutorial.dir/src/base.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/0_wsl_workspace/project1/src/base.cc -o CMakeFiles/tjurm_tutorial.dir/src/base.cc.s

CMakeFiles/tjurm_tutorial.dir/src/line.cc.o: CMakeFiles/tjurm_tutorial.dir/flags.make
CMakeFiles/tjurm_tutorial.dir/src/line.cc.o: ../src/line.cc
CMakeFiles/tjurm_tutorial.dir/src/line.cc.o: CMakeFiles/tjurm_tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/0_wsl_workspace/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tjurm_tutorial.dir/src/line.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tjurm_tutorial.dir/src/line.cc.o -MF CMakeFiles/tjurm_tutorial.dir/src/line.cc.o.d -o CMakeFiles/tjurm_tutorial.dir/src/line.cc.o -c /mnt/d/0_wsl_workspace/project1/src/line.cc

CMakeFiles/tjurm_tutorial.dir/src/line.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tjurm_tutorial.dir/src/line.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/0_wsl_workspace/project1/src/line.cc > CMakeFiles/tjurm_tutorial.dir/src/line.cc.i

CMakeFiles/tjurm_tutorial.dir/src/line.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tjurm_tutorial.dir/src/line.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/0_wsl_workspace/project1/src/line.cc -o CMakeFiles/tjurm_tutorial.dir/src/line.cc.s

CMakeFiles/tjurm_tutorial.dir/src/point.cc.o: CMakeFiles/tjurm_tutorial.dir/flags.make
CMakeFiles/tjurm_tutorial.dir/src/point.cc.o: ../src/point.cc
CMakeFiles/tjurm_tutorial.dir/src/point.cc.o: CMakeFiles/tjurm_tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/0_wsl_workspace/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tjurm_tutorial.dir/src/point.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tjurm_tutorial.dir/src/point.cc.o -MF CMakeFiles/tjurm_tutorial.dir/src/point.cc.o.d -o CMakeFiles/tjurm_tutorial.dir/src/point.cc.o -c /mnt/d/0_wsl_workspace/project1/src/point.cc

CMakeFiles/tjurm_tutorial.dir/src/point.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tjurm_tutorial.dir/src/point.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/0_wsl_workspace/project1/src/point.cc > CMakeFiles/tjurm_tutorial.dir/src/point.cc.i

CMakeFiles/tjurm_tutorial.dir/src/point.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tjurm_tutorial.dir/src/point.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/0_wsl_workspace/project1/src/point.cc -o CMakeFiles/tjurm_tutorial.dir/src/point.cc.s

CMakeFiles/tjurm_tutorial.dir/src/test.cc.o: CMakeFiles/tjurm_tutorial.dir/flags.make
CMakeFiles/tjurm_tutorial.dir/src/test.cc.o: ../src/test.cc
CMakeFiles/tjurm_tutorial.dir/src/test.cc.o: CMakeFiles/tjurm_tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/0_wsl_workspace/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tjurm_tutorial.dir/src/test.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tjurm_tutorial.dir/src/test.cc.o -MF CMakeFiles/tjurm_tutorial.dir/src/test.cc.o.d -o CMakeFiles/tjurm_tutorial.dir/src/test.cc.o -c /mnt/d/0_wsl_workspace/project1/src/test.cc

CMakeFiles/tjurm_tutorial.dir/src/test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tjurm_tutorial.dir/src/test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/0_wsl_workspace/project1/src/test.cc > CMakeFiles/tjurm_tutorial.dir/src/test.cc.i

CMakeFiles/tjurm_tutorial.dir/src/test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tjurm_tutorial.dir/src/test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/0_wsl_workspace/project1/src/test.cc -o CMakeFiles/tjurm_tutorial.dir/src/test.cc.s

# Object files for target tjurm_tutorial
tjurm_tutorial_OBJECTS = \
"CMakeFiles/tjurm_tutorial.dir/main.cc.o" \
"CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o" \
"CMakeFiles/tjurm_tutorial.dir/src/base.cc.o" \
"CMakeFiles/tjurm_tutorial.dir/src/line.cc.o" \
"CMakeFiles/tjurm_tutorial.dir/src/point.cc.o" \
"CMakeFiles/tjurm_tutorial.dir/src/test.cc.o"

# External object files for target tjurm_tutorial
tjurm_tutorial_EXTERNAL_OBJECTS =

tjurm_tutorial: CMakeFiles/tjurm_tutorial.dir/main.cc.o
tjurm_tutorial: CMakeFiles/tjurm_tutorial.dir/src/Contours.cc.o
tjurm_tutorial: CMakeFiles/tjurm_tutorial.dir/src/base.cc.o
tjurm_tutorial: CMakeFiles/tjurm_tutorial.dir/src/line.cc.o
tjurm_tutorial: CMakeFiles/tjurm_tutorial.dir/src/point.cc.o
tjurm_tutorial: CMakeFiles/tjurm_tutorial.dir/src/test.cc.o
tjurm_tutorial: CMakeFiles/tjurm_tutorial.dir/build.make
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_gapi.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_highgui.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_ml.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_objdetect.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_photo.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_stitching.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_video.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_videoio.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_imgcodecs.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_dnn.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_calib3d.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_features2d.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_flann.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_imgproc.so.4.5.4
tjurm_tutorial: /usr/local/opencv4.5.4/lib/libopencv_core.so.4.5.4
tjurm_tutorial: CMakeFiles/tjurm_tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/0_wsl_workspace/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable tjurm_tutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tjurm_tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tjurm_tutorial.dir/build: tjurm_tutorial
.PHONY : CMakeFiles/tjurm_tutorial.dir/build

CMakeFiles/tjurm_tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tjurm_tutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tjurm_tutorial.dir/clean

CMakeFiles/tjurm_tutorial.dir/depend:
	cd /mnt/d/0_wsl_workspace/project1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/0_wsl_workspace/project1 /mnt/d/0_wsl_workspace/project1 /mnt/d/0_wsl_workspace/project1/build /mnt/d/0_wsl_workspace/project1/build /mnt/d/0_wsl_workspace/project1/build/CMakeFiles/tjurm_tutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tjurm_tutorial.dir/depend

