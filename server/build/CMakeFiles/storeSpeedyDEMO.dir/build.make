# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cameronhardin/Desktop/storeSpeedyDemo/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cameronhardin/Desktop/storeSpeedyDemo/server/build

# Include any dependencies generated for this target.
include CMakeFiles/storeSpeedyDEMO.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/storeSpeedyDEMO.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/storeSpeedyDEMO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/storeSpeedyDEMO.dir/flags.make

CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/flags.make
CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o: /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/main.cpp
CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameronhardin/Desktop/storeSpeedyDemo/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o -MF CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o.d -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o -c /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/main.cpp

CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/main.cpp > CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.i

CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/main.cpp -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.s

CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/flags.make
CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o: /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/api/api_util.cpp
CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameronhardin/Desktop/storeSpeedyDemo/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o -MF CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o.d -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o -c /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/api/api_util.cpp

CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/api/api_util.cpp > CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.i

CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/api/api_util.cpp -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.s

CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/flags.make
CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o: /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/api/json/StoreSpeedyJsonHandler.cpp
CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameronhardin/Desktop/storeSpeedyDemo/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o -MF CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o.d -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o -c /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/api/json/StoreSpeedyJsonHandler.cpp

CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/api/json/StoreSpeedyJsonHandler.cpp > CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.i

CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/api/json/StoreSpeedyJsonHandler.cpp -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.s

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/flags.make
CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o: /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/aisle.cpp
CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameronhardin/Desktop/storeSpeedyDemo/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o -MF CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o.d -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o -c /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/aisle.cpp

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/aisle.cpp > CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.i

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/aisle.cpp -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.s

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/flags.make
CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o: /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/cart.cpp
CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameronhardin/Desktop/storeSpeedyDemo/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o -MF CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o.d -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o -c /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/cart.cpp

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/cart.cpp > CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.i

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/cart.cpp -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.s

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/flags.make
CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o: /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/item.cpp
CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o: CMakeFiles/storeSpeedyDEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cameronhardin/Desktop/storeSpeedyDemo/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o -MF CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o.d -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o -c /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/item.cpp

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/item.cpp > CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.i

CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cameronhardin/Desktop/storeSpeedyDemo/server/driver/src/objects/item.cpp -o CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.s

# Object files for target storeSpeedyDEMO
storeSpeedyDEMO_OBJECTS = \
"CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o" \
"CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o" \
"CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o" \
"CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o" \
"CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o" \
"CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o"

# External object files for target storeSpeedyDEMO
storeSpeedyDEMO_EXTERNAL_OBJECTS =

storeSpeedyDEMO: CMakeFiles/storeSpeedyDEMO.dir/driver/src/main.cpp.o
storeSpeedyDEMO: CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/api_util.cpp.o
storeSpeedyDEMO: CMakeFiles/storeSpeedyDEMO.dir/driver/src/api/json/StoreSpeedyJsonHandler.cpp.o
storeSpeedyDEMO: CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/aisle.cpp.o
storeSpeedyDEMO: CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/cart.cpp.o
storeSpeedyDEMO: CMakeFiles/storeSpeedyDEMO.dir/driver/src/objects/item.cpp.o
storeSpeedyDEMO: CMakeFiles/storeSpeedyDEMO.dir/build.make
storeSpeedyDEMO: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/usr/lib/libcurl.tbd
storeSpeedyDEMO: /opt/homebrew/lib/libjsoncpp.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_gapi.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_stitching.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_alphamat.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_aruco.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_bgsegm.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_bioinspired.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_ccalib.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_dnn_objdetect.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_dnn_superres.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_dpm.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_face.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_freetype.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_fuzzy.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_hfs.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_img_hash.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_intensity_transform.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_line_descriptor.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_mcc.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_quality.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_rapid.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_reg.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_rgbd.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_saliency.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_sfm.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_signal.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_stereo.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_structured_light.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_superres.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_surface_matching.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_tracking.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_videostab.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_viz.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_wechat_qrcode.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_xfeatures2d.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_xobjdetect.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_xphoto.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_shape.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_highgui.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_datasets.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_plot.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_text.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_ml.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_phase_unwrapping.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_optflow.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_ximgproc.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_video.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_videoio.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_imgcodecs.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_objdetect.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_calib3d.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_dnn.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_features2d.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_flann.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_photo.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_imgproc.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/lib/libopencv_core.4.10.0.dylib
storeSpeedyDEMO: /opt/homebrew/Cellar/poppler/24.04.0/lib/libpoppler-cpp.dylib
storeSpeedyDEMO: CMakeFiles/storeSpeedyDEMO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/cameronhardin/Desktop/storeSpeedyDemo/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable storeSpeedyDEMO"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/storeSpeedyDEMO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/storeSpeedyDEMO.dir/build: storeSpeedyDEMO
.PHONY : CMakeFiles/storeSpeedyDEMO.dir/build

CMakeFiles/storeSpeedyDEMO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/storeSpeedyDEMO.dir/cmake_clean.cmake
.PHONY : CMakeFiles/storeSpeedyDEMO.dir/clean

CMakeFiles/storeSpeedyDEMO.dir/depend:
	cd /Users/cameronhardin/Desktop/storeSpeedyDemo/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cameronhardin/Desktop/storeSpeedyDemo/server /Users/cameronhardin/Desktop/storeSpeedyDemo/server /Users/cameronhardin/Desktop/storeSpeedyDemo/server/build /Users/cameronhardin/Desktop/storeSpeedyDemo/server/build /Users/cameronhardin/Desktop/storeSpeedyDemo/server/build/CMakeFiles/storeSpeedyDEMO.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/storeSpeedyDEMO.dir/depend

