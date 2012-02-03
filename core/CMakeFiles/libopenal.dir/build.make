# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/psastras/osu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/psastras/osu

# Utility rule file for libopenal.

core/CMakeFiles/libopenal: core/CMakeFiles/libopenal-complete

core/CMakeFiles/libopenal-complete: core/libopenal-prefix/src/libopenal-stamp/libopenal-install
core/CMakeFiles/libopenal-complete: core/libopenal-prefix/src/libopenal-stamp/libopenal-mkdir
core/CMakeFiles/libopenal-complete: core/libopenal-prefix/src/libopenal-stamp/libopenal-download
core/CMakeFiles/libopenal-complete: core/libopenal-prefix/src/libopenal-stamp/libopenal-update
core/CMakeFiles/libopenal-complete: core/libopenal-prefix/src/libopenal-stamp/libopenal-patch
core/CMakeFiles/libopenal-complete: core/libopenal-prefix/src/libopenal-stamp/libopenal-configure
core/CMakeFiles/libopenal-complete: core/libopenal-prefix/src/libopenal-stamp/libopenal-build
core/CMakeFiles/libopenal-complete: core/libopenal-prefix/src/libopenal-stamp/libopenal-install
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Completed 'libopenal'"
	cd /home/psastras/osu/core && /usr/bin/cmake -E make_directory /home/psastras/osu/core/CMakeFiles
	cd /home/psastras/osu/core && /usr/bin/cmake -E touch /home/psastras/osu/core/CMakeFiles/libopenal-complete
	cd /home/psastras/osu/core && /usr/bin/cmake -E touch /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp/libopenal-done

core/libopenal-prefix/src/libopenal-stamp/libopenal-install: core/libopenal-prefix/src/libopenal-stamp/libopenal-build
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Performing install step for 'libopenal'"
	cd /home/psastras/osu/core/libopenal-prefix/src/libopenal-build && /usr/bin/cmake --build /home/psastras/osu/core/libopenal-prefix/src/libopenal-build --config . --target install
	cd /home/psastras/osu/core/libopenal-prefix/src/libopenal-build && /usr/bin/cmake -E touch /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp/libopenal-install

core/libopenal-prefix/src/libopenal-stamp/libopenal-mkdir:
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Creating directories for 'libopenal'"
	cd /home/psastras/osu/core && /usr/bin/cmake -E make_directory /home/psastras/osu/core/3rdparty/OpenAL
	cd /home/psastras/osu/core && /usr/bin/cmake -E make_directory /home/psastras/osu/core/libopenal-prefix/src/libopenal-build
	cd /home/psastras/osu/core && /usr/bin/cmake -E make_directory /home/psastras/osu/core/3rdparty/install
	cd /home/psastras/osu/core && /usr/bin/cmake -E make_directory /home/psastras/osu/core/libopenal-prefix/tmp
	cd /home/psastras/osu/core && /usr/bin/cmake -E make_directory /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp
	cd /home/psastras/osu/core && /usr/bin/cmake -E make_directory /home/psastras/osu/core/libopenal-prefix/src
	cd /home/psastras/osu/core && /usr/bin/cmake -E touch /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp/libopenal-mkdir

core/libopenal-prefix/src/libopenal-stamp/libopenal-download: core/libopenal-prefix/src/libopenal-stamp/libopenal-mkdir
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "No download step for 'libopenal'"
	cd /home/psastras/osu/core && /usr/bin/cmake -E touch /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp/libopenal-download

core/libopenal-prefix/src/libopenal-stamp/libopenal-update: core/libopenal-prefix/src/libopenal-stamp/libopenal-download
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "No update step for 'libopenal'"
	cd /home/psastras/osu/core && /usr/bin/cmake -E touch /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp/libopenal-update

core/libopenal-prefix/src/libopenal-stamp/libopenal-patch: core/libopenal-prefix/src/libopenal-stamp/libopenal-download
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "No patch step for 'libopenal'"
	cd /home/psastras/osu/core && /usr/bin/cmake -E touch /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp/libopenal-patch

core/libopenal-prefix/src/libopenal-stamp/libopenal-configure: core/libopenal-prefix/tmp/libopenal-cfgcmd.txt
core/libopenal-prefix/src/libopenal-stamp/libopenal-configure: core/libopenal-prefix/src/libopenal-stamp/libopenal-update
core/libopenal-prefix/src/libopenal-stamp/libopenal-configure: core/libopenal-prefix/src/libopenal-stamp/libopenal-patch
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Performing configure step for 'libopenal'"
	cd /home/psastras/osu/core/libopenal-prefix/src/libopenal-build && /usr/bin/cmake "-GUnix Makefiles" /home/psastras/osu/core/3rdparty/OpenAL
	cd /home/psastras/osu/core/libopenal-prefix/src/libopenal-build && /usr/bin/cmake -E touch /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp/libopenal-configure

core/libopenal-prefix/src/libopenal-stamp/libopenal-build: core/libopenal-prefix/src/libopenal-stamp/libopenal-configure
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Performing build step for 'libopenal'"
	cd /home/psastras/osu/core/libopenal-prefix/src/libopenal-build && /usr/bin/cmake --build /home/psastras/osu/core/libopenal-prefix/src/libopenal-build --config .
	cd /home/psastras/osu/core/libopenal-prefix/src/libopenal-build && /usr/bin/cmake -E touch /home/psastras/osu/core/libopenal-prefix/src/libopenal-stamp/libopenal-build

libopenal: core/CMakeFiles/libopenal
libopenal: core/CMakeFiles/libopenal-complete
libopenal: core/libopenal-prefix/src/libopenal-stamp/libopenal-install
libopenal: core/libopenal-prefix/src/libopenal-stamp/libopenal-mkdir
libopenal: core/libopenal-prefix/src/libopenal-stamp/libopenal-download
libopenal: core/libopenal-prefix/src/libopenal-stamp/libopenal-update
libopenal: core/libopenal-prefix/src/libopenal-stamp/libopenal-patch
libopenal: core/libopenal-prefix/src/libopenal-stamp/libopenal-configure
libopenal: core/libopenal-prefix/src/libopenal-stamp/libopenal-build
libopenal: core/CMakeFiles/libopenal.dir/build.make
.PHONY : libopenal

# Rule to build all files generated by this target.
core/CMakeFiles/libopenal.dir/build: libopenal
.PHONY : core/CMakeFiles/libopenal.dir/build

core/CMakeFiles/libopenal.dir/clean:
	cd /home/psastras/osu/core && $(CMAKE_COMMAND) -P CMakeFiles/libopenal.dir/cmake_clean.cmake
.PHONY : core/CMakeFiles/libopenal.dir/clean

core/CMakeFiles/libopenal.dir/depend:
	cd /home/psastras/osu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/psastras/osu /home/psastras/osu/core /home/psastras/osu /home/psastras/osu/core /home/psastras/osu/core/CMakeFiles/libopenal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : core/CMakeFiles/libopenal.dir/depend
