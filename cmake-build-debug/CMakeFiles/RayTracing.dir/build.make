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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangyihan/Desktop/ComputerGraphics/RayTracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RayTracing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RayTracing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RayTracing.dir/flags.make

CMakeFiles/RayTracing.dir/main.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RayTracing.dir/main.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/main.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/main.cpp

CMakeFiles/RayTracing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/main.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/main.cpp > CMakeFiles/RayTracing.dir/main.cpp.i

CMakeFiles/RayTracing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/main.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/main.cpp -o CMakeFiles/RayTracing.dir/main.cpp.s

CMakeFiles/RayTracing.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/main.cpp.o.requires

CMakeFiles/RayTracing.dir/main.cpp.o.provides: CMakeFiles/RayTracing.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/main.cpp.o.provides

CMakeFiles/RayTracing.dir/main.cpp.o.provides.build: CMakeFiles/RayTracing.dir/main.cpp.o


CMakeFiles/RayTracing.dir/Ray.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Ray.cpp.o: ../Ray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RayTracing.dir/Ray.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Ray.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Ray.cpp

CMakeFiles/RayTracing.dir/Ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Ray.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Ray.cpp > CMakeFiles/RayTracing.dir/Ray.cpp.i

CMakeFiles/RayTracing.dir/Ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Ray.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Ray.cpp -o CMakeFiles/RayTracing.dir/Ray.cpp.s

CMakeFiles/RayTracing.dir/Ray.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Ray.cpp.o.requires

CMakeFiles/RayTracing.dir/Ray.cpp.o.provides: CMakeFiles/RayTracing.dir/Ray.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Ray.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Ray.cpp.o.provides

CMakeFiles/RayTracing.dir/Ray.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Ray.cpp.o


CMakeFiles/RayTracing.dir/Object.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Object.cpp.o: ../Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RayTracing.dir/Object.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Object.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Object.cpp

CMakeFiles/RayTracing.dir/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Object.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Object.cpp > CMakeFiles/RayTracing.dir/Object.cpp.i

CMakeFiles/RayTracing.dir/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Object.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Object.cpp -o CMakeFiles/RayTracing.dir/Object.cpp.s

CMakeFiles/RayTracing.dir/Object.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Object.cpp.o.requires

CMakeFiles/RayTracing.dir/Object.cpp.o.provides: CMakeFiles/RayTracing.dir/Object.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Object.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Object.cpp.o.provides

CMakeFiles/RayTracing.dir/Object.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Object.cpp.o


CMakeFiles/RayTracing.dir/Scene.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Scene.cpp.o: ../Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RayTracing.dir/Scene.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Scene.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Scene.cpp

CMakeFiles/RayTracing.dir/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Scene.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Scene.cpp > CMakeFiles/RayTracing.dir/Scene.cpp.i

CMakeFiles/RayTracing.dir/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Scene.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Scene.cpp -o CMakeFiles/RayTracing.dir/Scene.cpp.s

CMakeFiles/RayTracing.dir/Scene.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Scene.cpp.o.requires

CMakeFiles/RayTracing.dir/Scene.cpp.o.provides: CMakeFiles/RayTracing.dir/Scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Scene.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Scene.cpp.o.provides

CMakeFiles/RayTracing.dir/Scene.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Scene.cpp.o


CMakeFiles/RayTracing.dir/Camera.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Camera.cpp.o: ../Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RayTracing.dir/Camera.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Camera.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Camera.cpp

CMakeFiles/RayTracing.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Camera.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Camera.cpp > CMakeFiles/RayTracing.dir/Camera.cpp.i

CMakeFiles/RayTracing.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Camera.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Camera.cpp -o CMakeFiles/RayTracing.dir/Camera.cpp.s

CMakeFiles/RayTracing.dir/Camera.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Camera.cpp.o.requires

CMakeFiles/RayTracing.dir/Camera.cpp.o.provides: CMakeFiles/RayTracing.dir/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Camera.cpp.o.provides

CMakeFiles/RayTracing.dir/Camera.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Camera.cpp.o


CMakeFiles/RayTracing.dir/Light.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Light.cpp.o: ../Light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RayTracing.dir/Light.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Light.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Light.cpp

CMakeFiles/RayTracing.dir/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Light.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Light.cpp > CMakeFiles/RayTracing.dir/Light.cpp.i

CMakeFiles/RayTracing.dir/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Light.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Light.cpp -o CMakeFiles/RayTracing.dir/Light.cpp.s

CMakeFiles/RayTracing.dir/Light.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Light.cpp.o.requires

CMakeFiles/RayTracing.dir/Light.cpp.o.provides: CMakeFiles/RayTracing.dir/Light.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Light.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Light.cpp.o.provides

CMakeFiles/RayTracing.dir/Light.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Light.cpp.o


CMakeFiles/RayTracing.dir/Kd_tree.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Kd_tree.cpp.o: ../Kd_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/RayTracing.dir/Kd_tree.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Kd_tree.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Kd_tree.cpp

CMakeFiles/RayTracing.dir/Kd_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Kd_tree.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Kd_tree.cpp > CMakeFiles/RayTracing.dir/Kd_tree.cpp.i

CMakeFiles/RayTracing.dir/Kd_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Kd_tree.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Kd_tree.cpp -o CMakeFiles/RayTracing.dir/Kd_tree.cpp.s

CMakeFiles/RayTracing.dir/Kd_tree.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Kd_tree.cpp.o.requires

CMakeFiles/RayTracing.dir/Kd_tree.cpp.o.provides: CMakeFiles/RayTracing.dir/Kd_tree.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Kd_tree.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Kd_tree.cpp.o.provides

CMakeFiles/RayTracing.dir/Kd_tree.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Kd_tree.cpp.o


CMakeFiles/RayTracing.dir/Bezier.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Bezier.cpp.o: ../Bezier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/RayTracing.dir/Bezier.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Bezier.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Bezier.cpp

CMakeFiles/RayTracing.dir/Bezier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Bezier.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Bezier.cpp > CMakeFiles/RayTracing.dir/Bezier.cpp.i

CMakeFiles/RayTracing.dir/Bezier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Bezier.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Bezier.cpp -o CMakeFiles/RayTracing.dir/Bezier.cpp.s

CMakeFiles/RayTracing.dir/Bezier.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Bezier.cpp.o.requires

CMakeFiles/RayTracing.dir/Bezier.cpp.o.provides: CMakeFiles/RayTracing.dir/Bezier.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Bezier.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Bezier.cpp.o.provides

CMakeFiles/RayTracing.dir/Bezier.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Bezier.cpp.o


CMakeFiles/RayTracing.dir/Polynomial.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Polynomial.cpp.o: ../Polynomial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/RayTracing.dir/Polynomial.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Polynomial.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Polynomial.cpp

CMakeFiles/RayTracing.dir/Polynomial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Polynomial.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Polynomial.cpp > CMakeFiles/RayTracing.dir/Polynomial.cpp.i

CMakeFiles/RayTracing.dir/Polynomial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Polynomial.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Polynomial.cpp -o CMakeFiles/RayTracing.dir/Polynomial.cpp.s

CMakeFiles/RayTracing.dir/Polynomial.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Polynomial.cpp.o.requires

CMakeFiles/RayTracing.dir/Polynomial.cpp.o.provides: CMakeFiles/RayTracing.dir/Polynomial.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Polynomial.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Polynomial.cpp.o.provides

CMakeFiles/RayTracing.dir/Polynomial.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Polynomial.cpp.o


CMakeFiles/RayTracing.dir/BoundingBox.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/BoundingBox.cpp.o: ../BoundingBox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/RayTracing.dir/BoundingBox.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/BoundingBox.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/BoundingBox.cpp

CMakeFiles/RayTracing.dir/BoundingBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/BoundingBox.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/BoundingBox.cpp > CMakeFiles/RayTracing.dir/BoundingBox.cpp.i

CMakeFiles/RayTracing.dir/BoundingBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/BoundingBox.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/BoundingBox.cpp -o CMakeFiles/RayTracing.dir/BoundingBox.cpp.s

CMakeFiles/RayTracing.dir/BoundingBox.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/BoundingBox.cpp.o.requires

CMakeFiles/RayTracing.dir/BoundingBox.cpp.o.provides: CMakeFiles/RayTracing.dir/BoundingBox.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/BoundingBox.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/BoundingBox.cpp.o.provides

CMakeFiles/RayTracing.dir/BoundingBox.cpp.o.provides.build: CMakeFiles/RayTracing.dir/BoundingBox.cpp.o


CMakeFiles/RayTracing.dir/Texture.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Texture.cpp.o: ../Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/RayTracing.dir/Texture.cpp.o"
	/usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Texture.cpp.o -c /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Texture.cpp

CMakeFiles/RayTracing.dir/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Texture.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Texture.cpp > CMakeFiles/RayTracing.dir/Texture.cpp.i

CMakeFiles/RayTracing.dir/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Texture.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/Texture.cpp -o CMakeFiles/RayTracing.dir/Texture.cpp.s

CMakeFiles/RayTracing.dir/Texture.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Texture.cpp.o.requires

CMakeFiles/RayTracing.dir/Texture.cpp.o.provides: CMakeFiles/RayTracing.dir/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Texture.cpp.o.provides

CMakeFiles/RayTracing.dir/Texture.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Texture.cpp.o


# Object files for target RayTracing
RayTracing_OBJECTS = \
"CMakeFiles/RayTracing.dir/main.cpp.o" \
"CMakeFiles/RayTracing.dir/Ray.cpp.o" \
"CMakeFiles/RayTracing.dir/Object.cpp.o" \
"CMakeFiles/RayTracing.dir/Scene.cpp.o" \
"CMakeFiles/RayTracing.dir/Camera.cpp.o" \
"CMakeFiles/RayTracing.dir/Light.cpp.o" \
"CMakeFiles/RayTracing.dir/Kd_tree.cpp.o" \
"CMakeFiles/RayTracing.dir/Bezier.cpp.o" \
"CMakeFiles/RayTracing.dir/Polynomial.cpp.o" \
"CMakeFiles/RayTracing.dir/BoundingBox.cpp.o" \
"CMakeFiles/RayTracing.dir/Texture.cpp.o"

# External object files for target RayTracing
RayTracing_EXTERNAL_OBJECTS =

RayTracing: CMakeFiles/RayTracing.dir/main.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Ray.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Object.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Scene.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Camera.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Light.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Kd_tree.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Bezier.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Polynomial.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/BoundingBox.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Texture.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/build.make
RayTracing: /usr/local/lib/libopencv_stitching.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_superres.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_videostab.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_aruco.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_bgsegm.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_bioinspired.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_ccalib.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_dnn_objdetect.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_dpm.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_face.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_fuzzy.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_hfs.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_img_hash.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_line_descriptor.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_optflow.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_reg.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_rgbd.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_saliency.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_stereo.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_structured_light.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_surface_matching.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_tracking.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_xfeatures2d.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_ximgproc.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_xobjdetect.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_xphoto.3.4.1.dylib
RayTracing: /usr/local/opt/libomp/lib/libomp.dylib
RayTracing: /usr/local/lib/libopencv_shape.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_photo.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_datasets.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_plot.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_text.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_dnn.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_ml.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_video.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_calib3d.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_features2d.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_highgui.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_videoio.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_phase_unwrapping.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_flann.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_imgcodecs.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_objdetect.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_imgproc.3.4.1.dylib
RayTracing: /usr/local/lib/libopencv_core.3.4.1.dylib
RayTracing: CMakeFiles/RayTracing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable RayTracing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RayTracing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RayTracing.dir/build: RayTracing

.PHONY : CMakeFiles/RayTracing.dir/build

CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/main.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Ray.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Object.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Scene.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Camera.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Light.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Kd_tree.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Bezier.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Polynomial.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/BoundingBox.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Texture.cpp.o.requires

.PHONY : CMakeFiles/RayTracing.dir/requires

CMakeFiles/RayTracing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RayTracing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RayTracing.dir/clean

CMakeFiles/RayTracing.dir/depend:
	cd /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangyihan/Desktop/ComputerGraphics/RayTracing /Users/wangyihan/Desktop/ComputerGraphics/RayTracing /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug /Users/wangyihan/Desktop/ComputerGraphics/RayTracing/cmake-build-debug/CMakeFiles/RayTracing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RayTracing.dir/depend
