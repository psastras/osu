# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = "/c/Program Files (x86)/CMake 2.8/bin/cmake.exe"

# The command to remove a file.
RM = "/c/Program Files (x86)/CMake 2.8/bin/cmake.exe" -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/c/Program Files (x86)/CMake 2.8/bin/cmake-gui.exe"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /C/Users/psastras/Projects/osu/core/3rdparty/OpenAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /C/Users/psastras/Projects/osu/core/3rdparty/install/src/libopenal-build

# Include any dependencies generated for this target.
include CMakeFiles/openal-info.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/openal-info.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openal-info.dir/flags.make

CMakeFiles/openal-info.dir/utils/openal-info.obj: CMakeFiles/openal-info.dir/flags.make
CMakeFiles/openal-info.dir/utils/openal-info.obj: CMakeFiles/openal-info.dir/includes_C.rsp
CMakeFiles/openal-info.dir/utils/openal-info.obj: C:/Users/psastras/Projects/osu/core/3rdparty/OpenAL/utils/openal-info.c
	$(CMAKE_COMMAND) -E cmake_progress_report /C/Users/psastras/Projects/osu/core/3rdparty/install/src/libopenal-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/openal-info.dir/utils/openal-info.obj"
	/c/QtSDK/mingw/bin/gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/openal-info.dir/utils/openal-info.obj   -c /C/Users/psastras/Projects/osu/core/3rdparty/OpenAL/utils/openal-info.c

CMakeFiles/openal-info.dir/utils/openal-info.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/openal-info.dir/utils/openal-info.i"
	/c/QtSDK/mingw/bin/gcc.exe  $(C_DEFINES) $(C_FLAGS) -E /C/Users/psastras/Projects/osu/core/3rdparty/OpenAL/utils/openal-info.c > CMakeFiles/openal-info.dir/utils/openal-info.i

CMakeFiles/openal-info.dir/utils/openal-info.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/openal-info.dir/utils/openal-info.s"
	/c/QtSDK/mingw/bin/gcc.exe  $(C_DEFINES) $(C_FLAGS) -S /C/Users/psastras/Projects/osu/core/3rdparty/OpenAL/utils/openal-info.c -o CMakeFiles/openal-info.dir/utils/openal-info.s

CMakeFiles/openal-info.dir/utils/openal-info.obj.requires:
.PHONY : CMakeFiles/openal-info.dir/utils/openal-info.obj.requires

CMakeFiles/openal-info.dir/utils/openal-info.obj.provides: CMakeFiles/openal-info.dir/utils/openal-info.obj.requires
	$(MAKE) -f CMakeFiles/openal-info.dir/build.make CMakeFiles/openal-info.dir/utils/openal-info.obj.provides.build
.PHONY : CMakeFiles/openal-info.dir/utils/openal-info.obj.provides

CMakeFiles/openal-info.dir/utils/openal-info.obj.provides.build: CMakeFiles/openal-info.dir/utils/openal-info.obj

# Object files for target openal-info
openal__info_OBJECTS = \
"CMakeFiles/openal-info.dir/utils/openal-info.obj"

# External object files for target openal-info
openal__info_EXTERNAL_OBJECTS =

openal-info.exe: CMakeFiles/openal-info.dir/utils/openal-info.obj
openal-info.exe: libOpenAL32.dll.a
openal-info.exe: CMakeFiles/openal-info.dir/build.make
openal-info.exe: CMakeFiles/openal-info.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable openal-info.exe"
	"/c/Program Files (x86)/CMake 2.8/bin/cmake.exe" -E remove -f CMakeFiles/openal-info.dir/objects.a
	/c/QtSDK/mingw/bin/ar.exe cr CMakeFiles/openal-info.dir/objects.a @CMakeFiles/openal-info.dir/objects1.rsp
	/c/QtSDK/mingw/bin/gcc.exe  -g -O2 -D_DEBUG    -Wl,--whole-archive CMakeFiles/openal-info.dir/objects.a -Wl,--no-whole-archive  -o openal-info.exe -Wl,--out-implib,libopenal-info.dll.a -Wl,--major-image-version,0,--minor-image-version,0  libOpenAL32.dll.a -lwinmm -lm -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 

# Rule to build all files generated by this target.
CMakeFiles/openal-info.dir/build: openal-info.exe
.PHONY : CMakeFiles/openal-info.dir/build

CMakeFiles/openal-info.dir/requires: CMakeFiles/openal-info.dir/utils/openal-info.obj.requires
.PHONY : CMakeFiles/openal-info.dir/requires

CMakeFiles/openal-info.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/openal-info.dir/cmake_clean.cmake
.PHONY : CMakeFiles/openal-info.dir/clean

CMakeFiles/openal-info.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /C/Users/psastras/Projects/osu/core/3rdparty/OpenAL /C/Users/psastras/Projects/osu/core/3rdparty/OpenAL /C/Users/psastras/Projects/osu/core/3rdparty/install/src/libopenal-build /C/Users/psastras/Projects/osu/core/3rdparty/install/src/libopenal-build /C/Users/psastras/Projects/osu/core/3rdparty/install/src/libopenal-build/CMakeFiles/openal-info.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openal-info.dir/depend
