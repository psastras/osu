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
CMAKE_BINARY_DIR = /gpfs/main/home/psastras/osu

# Include any dependencies generated for this target.
include desktop/CMakeFiles/osu.dir/depend.make

# Include the progress variables for this target.
include desktop/CMakeFiles/osu.dir/progress.make

# Include the compile flags for this target's objects.
include desktop/CMakeFiles/osu.dir/flags.make

desktop/CMakeFiles/osu.dir/main.cpp.o: desktop/CMakeFiles/osu.dir/flags.make
desktop/CMakeFiles/osu.dir/main.cpp.o: /home/psastras/osu/desktop/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /gpfs/main/home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object desktop/CMakeFiles/osu.dir/main.cpp.o"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/osu.dir/main.cpp.o -c /home/psastras/osu/desktop/main.cpp

desktop/CMakeFiles/osu.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osu.dir/main.cpp.i"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/psastras/osu/desktop/main.cpp > CMakeFiles/osu.dir/main.cpp.i

desktop/CMakeFiles/osu.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osu.dir/main.cpp.s"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/psastras/osu/desktop/main.cpp -o CMakeFiles/osu.dir/main.cpp.s

desktop/CMakeFiles/osu.dir/main.cpp.o.requires:
.PHONY : desktop/CMakeFiles/osu.dir/main.cpp.o.requires

desktop/CMakeFiles/osu.dir/main.cpp.o.provides: desktop/CMakeFiles/osu.dir/main.cpp.o.requires
	$(MAKE) -f desktop/CMakeFiles/osu.dir/build.make desktop/CMakeFiles/osu.dir/main.cpp.o.provides.build
.PHONY : desktop/CMakeFiles/osu.dir/main.cpp.o.provides

desktop/CMakeFiles/osu.dir/main.cpp.o.provides.build: desktop/CMakeFiles/osu.dir/main.cpp.o
.PHONY : desktop/CMakeFiles/osu.dir/main.cpp.o.provides.build

desktop/CMakeFiles/osu.dir/mainwindow.cpp.o: desktop/CMakeFiles/osu.dir/flags.make
desktop/CMakeFiles/osu.dir/mainwindow.cpp.o: /home/psastras/osu/desktop/mainwindow.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /gpfs/main/home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object desktop/CMakeFiles/osu.dir/mainwindow.cpp.o"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/osu.dir/mainwindow.cpp.o -c /home/psastras/osu/desktop/mainwindow.cpp

desktop/CMakeFiles/osu.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osu.dir/mainwindow.cpp.i"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/psastras/osu/desktop/mainwindow.cpp > CMakeFiles/osu.dir/mainwindow.cpp.i

desktop/CMakeFiles/osu.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osu.dir/mainwindow.cpp.s"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/psastras/osu/desktop/mainwindow.cpp -o CMakeFiles/osu.dir/mainwindow.cpp.s

desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.requires:
.PHONY : desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.requires

desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.provides: desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.requires
	$(MAKE) -f desktop/CMakeFiles/osu.dir/build.make desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.provides.build
.PHONY : desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.provides

desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.provides.build: desktop/CMakeFiles/osu.dir/mainwindow.cpp.o
.PHONY : desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.provides.build

desktop/CMakeFiles/osu.dir/glwidget.cpp.o: desktop/CMakeFiles/osu.dir/flags.make
desktop/CMakeFiles/osu.dir/glwidget.cpp.o: /home/psastras/osu/desktop/glwidget.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /gpfs/main/home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object desktop/CMakeFiles/osu.dir/glwidget.cpp.o"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/osu.dir/glwidget.cpp.o -c /home/psastras/osu/desktop/glwidget.cpp

desktop/CMakeFiles/osu.dir/glwidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osu.dir/glwidget.cpp.i"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/psastras/osu/desktop/glwidget.cpp > CMakeFiles/osu.dir/glwidget.cpp.i

desktop/CMakeFiles/osu.dir/glwidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osu.dir/glwidget.cpp.s"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/psastras/osu/desktop/glwidget.cpp -o CMakeFiles/osu.dir/glwidget.cpp.s

desktop/CMakeFiles/osu.dir/glwidget.cpp.o.requires:
.PHONY : desktop/CMakeFiles/osu.dir/glwidget.cpp.o.requires

desktop/CMakeFiles/osu.dir/glwidget.cpp.o.provides: desktop/CMakeFiles/osu.dir/glwidget.cpp.o.requires
	$(MAKE) -f desktop/CMakeFiles/osu.dir/build.make desktop/CMakeFiles/osu.dir/glwidget.cpp.o.provides.build
.PHONY : desktop/CMakeFiles/osu.dir/glwidget.cpp.o.provides

desktop/CMakeFiles/osu.dir/glwidget.cpp.o.provides.build: desktop/CMakeFiles/osu.dir/glwidget.cpp.o
.PHONY : desktop/CMakeFiles/osu.dir/glwidget.cpp.o.provides.build

desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o: desktop/CMakeFiles/osu.dir/flags.make
desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o: desktop/moc_mainwindow.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /gpfs/main/home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/osu.dir/moc_mainwindow.cxx.o -c /gpfs/main/home/psastras/osu/desktop/moc_mainwindow.cxx

desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osu.dir/moc_mainwindow.cxx.i"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /gpfs/main/home/psastras/osu/desktop/moc_mainwindow.cxx > CMakeFiles/osu.dir/moc_mainwindow.cxx.i

desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osu.dir/moc_mainwindow.cxx.s"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /gpfs/main/home/psastras/osu/desktop/moc_mainwindow.cxx -o CMakeFiles/osu.dir/moc_mainwindow.cxx.s

desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.requires:
.PHONY : desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.requires

desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.provides: desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.requires
	$(MAKE) -f desktop/CMakeFiles/osu.dir/build.make desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.provides.build
.PHONY : desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.provides

desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.provides.build: desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o
.PHONY : desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.provides.build

desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o: desktop/CMakeFiles/osu.dir/flags.make
desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o: desktop/moc_glwidget.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /gpfs/main/home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/osu.dir/moc_glwidget.cxx.o -c /gpfs/main/home/psastras/osu/desktop/moc_glwidget.cxx

desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/osu.dir/moc_glwidget.cxx.i"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /gpfs/main/home/psastras/osu/desktop/moc_glwidget.cxx > CMakeFiles/osu.dir/moc_glwidget.cxx.i

desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/osu.dir/moc_glwidget.cxx.s"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /gpfs/main/home/psastras/osu/desktop/moc_glwidget.cxx -o CMakeFiles/osu.dir/moc_glwidget.cxx.s

desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.requires:
.PHONY : desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.requires

desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.provides: desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.requires
	$(MAKE) -f desktop/CMakeFiles/osu.dir/build.make desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.provides.build
.PHONY : desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.provides

desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.provides.build: desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o
.PHONY : desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.provides.build

desktop/moc_mainwindow.cxx: /home/psastras/osu/desktop/mainwindow.h
	$(CMAKE_COMMAND) -E cmake_progress_report /gpfs/main/home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_mainwindow.cxx"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/moc-qt4 -o /gpfs/main/home/psastras/osu/desktop/moc_mainwindow.cxx /home/psastras/osu/desktop/mainwindow.h

desktop/moc_glwidget.cxx: /home/psastras/osu/desktop/glwidget.h
	$(CMAKE_COMMAND) -E cmake_progress_report /gpfs/main/home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_glwidget.cxx"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/moc-qt4 -o /gpfs/main/home/psastras/osu/desktop/moc_glwidget.cxx /home/psastras/osu/desktop/glwidget.h

desktop/ui_mainwindow.h: /home/psastras/osu/desktop/mainwindow.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /gpfs/main/home/psastras/osu/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_mainwindow.h"
	cd /gpfs/main/home/psastras/osu/desktop && /usr/bin/uic-qt4 -o /gpfs/main/home/psastras/osu/desktop/ui_mainwindow.h /home/psastras/osu/desktop/mainwindow.ui

# Object files for target osu
osu_OBJECTS = \
"CMakeFiles/osu.dir/main.cpp.o" \
"CMakeFiles/osu.dir/mainwindow.cpp.o" \
"CMakeFiles/osu.dir/glwidget.cpp.o" \
"CMakeFiles/osu.dir/moc_mainwindow.cxx.o" \
"CMakeFiles/osu.dir/moc_glwidget.cxx.o"

# External object files for target osu
osu_EXTERNAL_OBJECTS =

desktop/bin/osu: desktop/CMakeFiles/osu.dir/main.cpp.o
desktop/bin/osu: desktop/CMakeFiles/osu.dir/mainwindow.cpp.o
desktop/bin/osu: desktop/CMakeFiles/osu.dir/glwidget.cpp.o
desktop/bin/osu: desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o
desktop/bin/osu: desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o
desktop/bin/osu: /usr/lib/libQtOpenGL.so
desktop/bin/osu: /usr/lib/libQtGui.so
desktop/bin/osu: /usr/lib/libQtCore.so
desktop/bin/osu: core/bin/libcore.a
desktop/bin/osu: /home/psastras/osu/core/3rdparty/install/lib/libmpg123.so
desktop/bin/osu: /home/psastras/osu/core/3rdparty/install/lib/libopenal.so
desktop/bin/osu: desktop/CMakeFiles/osu.dir/build.make
desktop/bin/osu: desktop/CMakeFiles/osu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/osu"
	cd /gpfs/main/home/psastras/osu/desktop && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/osu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
desktop/CMakeFiles/osu.dir/build: desktop/bin/osu
.PHONY : desktop/CMakeFiles/osu.dir/build

desktop/CMakeFiles/osu.dir/requires: desktop/CMakeFiles/osu.dir/main.cpp.o.requires
desktop/CMakeFiles/osu.dir/requires: desktop/CMakeFiles/osu.dir/mainwindow.cpp.o.requires
desktop/CMakeFiles/osu.dir/requires: desktop/CMakeFiles/osu.dir/glwidget.cpp.o.requires
desktop/CMakeFiles/osu.dir/requires: desktop/CMakeFiles/osu.dir/moc_mainwindow.cxx.o.requires
desktop/CMakeFiles/osu.dir/requires: desktop/CMakeFiles/osu.dir/moc_glwidget.cxx.o.requires
.PHONY : desktop/CMakeFiles/osu.dir/requires

desktop/CMakeFiles/osu.dir/clean:
	cd /gpfs/main/home/psastras/osu/desktop && $(CMAKE_COMMAND) -P CMakeFiles/osu.dir/cmake_clean.cmake
.PHONY : desktop/CMakeFiles/osu.dir/clean

desktop/CMakeFiles/osu.dir/depend: desktop/moc_mainwindow.cxx
desktop/CMakeFiles/osu.dir/depend: desktop/moc_glwidget.cxx
desktop/CMakeFiles/osu.dir/depend: desktop/ui_mainwindow.h
	cd /gpfs/main/home/psastras/osu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/psastras/osu /home/psastras/osu/desktop /gpfs/main/home/psastras/osu /gpfs/main/home/psastras/osu/desktop /gpfs/main/home/psastras/osu/desktop/CMakeFiles/osu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : desktop/CMakeFiles/osu.dir/depend

