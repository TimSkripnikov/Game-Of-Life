# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = "/home/artem/Documents/2 course/Object-Oriented Programming/ex2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build"

# Include any dependencies generated for this target.
include library/CMakeFiles/GameOfLife.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include library/CMakeFiles/GameOfLife.dir/compiler_depend.make

# Include the progress variables for this target.
include library/CMakeFiles/GameOfLife.dir/progress.make

# Include the compile flags for this target's objects.
include library/CMakeFiles/GameOfLife.dir/flags.make

library/CMakeFiles/GameOfLife.dir/GameEngine.cpp.o: library/CMakeFiles/GameOfLife.dir/flags.make
library/CMakeFiles/GameOfLife.dir/GameEngine.cpp.o: /home/artem/Documents/2\ course/Object-Oriented\ Programming/ex2/library/GameEngine.cpp
library/CMakeFiles/GameOfLife.dir/GameEngine.cpp.o: library/CMakeFiles/GameOfLife.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object library/CMakeFiles/GameOfLife.dir/GameEngine.cpp.o"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/GameOfLife.dir/GameEngine.cpp.o -MF CMakeFiles/GameOfLife.dir/GameEngine.cpp.o.d -o CMakeFiles/GameOfLife.dir/GameEngine.cpp.o -c "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameEngine.cpp"

library/CMakeFiles/GameOfLife.dir/GameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/GameEngine.cpp.i"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameEngine.cpp" > CMakeFiles/GameOfLife.dir/GameEngine.cpp.i

library/CMakeFiles/GameOfLife.dir/GameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/GameEngine.cpp.s"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameEngine.cpp" -o CMakeFiles/GameOfLife.dir/GameEngine.cpp.s

library/CMakeFiles/GameOfLife.dir/GameInterface.cpp.o: library/CMakeFiles/GameOfLife.dir/flags.make
library/CMakeFiles/GameOfLife.dir/GameInterface.cpp.o: /home/artem/Documents/2\ course/Object-Oriented\ Programming/ex2/library/GameInterface.cpp
library/CMakeFiles/GameOfLife.dir/GameInterface.cpp.o: library/CMakeFiles/GameOfLife.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object library/CMakeFiles/GameOfLife.dir/GameInterface.cpp.o"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/GameOfLife.dir/GameInterface.cpp.o -MF CMakeFiles/GameOfLife.dir/GameInterface.cpp.o.d -o CMakeFiles/GameOfLife.dir/GameInterface.cpp.o -c "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameInterface.cpp"

library/CMakeFiles/GameOfLife.dir/GameInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/GameInterface.cpp.i"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameInterface.cpp" > CMakeFiles/GameOfLife.dir/GameInterface.cpp.i

library/CMakeFiles/GameOfLife.dir/GameInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/GameInterface.cpp.s"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameInterface.cpp" -o CMakeFiles/GameOfLife.dir/GameInterface.cpp.s

library/CMakeFiles/GameOfLife.dir/GameState.cpp.o: library/CMakeFiles/GameOfLife.dir/flags.make
library/CMakeFiles/GameOfLife.dir/GameState.cpp.o: /home/artem/Documents/2\ course/Object-Oriented\ Programming/ex2/library/GameState.cpp
library/CMakeFiles/GameOfLife.dir/GameState.cpp.o: library/CMakeFiles/GameOfLife.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object library/CMakeFiles/GameOfLife.dir/GameState.cpp.o"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/GameOfLife.dir/GameState.cpp.o -MF CMakeFiles/GameOfLife.dir/GameState.cpp.o.d -o CMakeFiles/GameOfLife.dir/GameState.cpp.o -c "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameState.cpp"

library/CMakeFiles/GameOfLife.dir/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/GameState.cpp.i"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameState.cpp" > CMakeFiles/GameOfLife.dir/GameState.cpp.i

library/CMakeFiles/GameOfLife.dir/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/GameState.cpp.s"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/GameState.cpp" -o CMakeFiles/GameOfLife.dir/GameState.cpp.s

library/CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o: library/CMakeFiles/GameOfLife.dir/flags.make
library/CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o: /home/artem/Documents/2\ course/Object-Oriented\ Programming/ex2/library/ParserCommandLine.cpp
library/CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o: library/CMakeFiles/GameOfLife.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object library/CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o -MF CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o.d -o CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o -c "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserCommandLine.cpp"

library/CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.i"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserCommandLine.cpp" > CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.i

library/CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.s"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserCommandLine.cpp" -o CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.s

library/CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o: library/CMakeFiles/GameOfLife.dir/flags.make
library/CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o: /home/artem/Documents/2\ course/Object-Oriented\ Programming/ex2/library/ParserCommands.cpp
library/CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o: library/CMakeFiles/GameOfLife.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object library/CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o -MF CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o.d -o CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o -c "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserCommands.cpp"

library/CMakeFiles/GameOfLife.dir/ParserCommands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/ParserCommands.cpp.i"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserCommands.cpp" > CMakeFiles/GameOfLife.dir/ParserCommands.cpp.i

library/CMakeFiles/GameOfLife.dir/ParserCommands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/ParserCommands.cpp.s"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserCommands.cpp" -o CMakeFiles/GameOfLife.dir/ParserCommands.cpp.s

library/CMakeFiles/GameOfLife.dir/ParserFile.cpp.o: library/CMakeFiles/GameOfLife.dir/flags.make
library/CMakeFiles/GameOfLife.dir/ParserFile.cpp.o: /home/artem/Documents/2\ course/Object-Oriented\ Programming/ex2/library/ParserFile.cpp
library/CMakeFiles/GameOfLife.dir/ParserFile.cpp.o: library/CMakeFiles/GameOfLife.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object library/CMakeFiles/GameOfLife.dir/ParserFile.cpp.o"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/GameOfLife.dir/ParserFile.cpp.o -MF CMakeFiles/GameOfLife.dir/ParserFile.cpp.o.d -o CMakeFiles/GameOfLife.dir/ParserFile.cpp.o -c "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserFile.cpp"

library/CMakeFiles/GameOfLife.dir/ParserFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/ParserFile.cpp.i"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserFile.cpp" > CMakeFiles/GameOfLife.dir/ParserFile.cpp.i

library/CMakeFiles/GameOfLife.dir/ParserFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/ParserFile.cpp.s"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library/ParserFile.cpp" -o CMakeFiles/GameOfLife.dir/ParserFile.cpp.s

# Object files for target GameOfLife
GameOfLife_OBJECTS = \
"CMakeFiles/GameOfLife.dir/GameEngine.cpp.o" \
"CMakeFiles/GameOfLife.dir/GameInterface.cpp.o" \
"CMakeFiles/GameOfLife.dir/GameState.cpp.o" \
"CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o" \
"CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o" \
"CMakeFiles/GameOfLife.dir/ParserFile.cpp.o"

# External object files for target GameOfLife
GameOfLife_EXTERNAL_OBJECTS =

library/libGameOfLife.a: library/CMakeFiles/GameOfLife.dir/GameEngine.cpp.o
library/libGameOfLife.a: library/CMakeFiles/GameOfLife.dir/GameInterface.cpp.o
library/libGameOfLife.a: library/CMakeFiles/GameOfLife.dir/GameState.cpp.o
library/libGameOfLife.a: library/CMakeFiles/GameOfLife.dir/ParserCommandLine.cpp.o
library/libGameOfLife.a: library/CMakeFiles/GameOfLife.dir/ParserCommands.cpp.o
library/libGameOfLife.a: library/CMakeFiles/GameOfLife.dir/ParserFile.cpp.o
library/libGameOfLife.a: library/CMakeFiles/GameOfLife.dir/build.make
library/libGameOfLife.a: library/CMakeFiles/GameOfLife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libGameOfLife.a"
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && $(CMAKE_COMMAND) -P CMakeFiles/GameOfLife.dir/cmake_clean_target.cmake
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameOfLife.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
library/CMakeFiles/GameOfLife.dir/build: library/libGameOfLife.a
.PHONY : library/CMakeFiles/GameOfLife.dir/build

library/CMakeFiles/GameOfLife.dir/clean:
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" && $(CMAKE_COMMAND) -P CMakeFiles/GameOfLife.dir/cmake_clean.cmake
.PHONY : library/CMakeFiles/GameOfLife.dir/clean

library/CMakeFiles/GameOfLife.dir/depend:
	cd "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/artem/Documents/2 course/Object-Oriented Programming/ex2" "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/library" "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build" "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library" "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/library/CMakeFiles/GameOfLife.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : library/CMakeFiles/GameOfLife.dir/depend

