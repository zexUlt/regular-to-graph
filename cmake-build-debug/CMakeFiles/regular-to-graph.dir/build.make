# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\RegularToGraph\regular-to-graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\RegularToGraph\regular-to-graph\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\regular-to-graph.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\regular-to-graph.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\regular-to-graph.dir\flags.make

CMakeFiles\regular-to-graph.dir\main.cpp.obj: CMakeFiles\regular-to-graph.dir\flags.make
CMakeFiles\regular-to-graph.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\RegularToGraph\regular-to-graph\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/regular-to-graph.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\regular-to-graph.dir\main.cpp.obj /FdCMakeFiles\regular-to-graph.dir\ /FS -c F:\RegularToGraph\regular-to-graph\main.cpp
<<

CMakeFiles\regular-to-graph.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/regular-to-graph.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\regular-to-graph.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\RegularToGraph\regular-to-graph\main.cpp
<<

CMakeFiles\regular-to-graph.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/regular-to-graph.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\regular-to-graph.dir\main.cpp.s /c F:\RegularToGraph\regular-to-graph\main.cpp
<<

CMakeFiles\regular-to-graph.dir\RegExprParser.cpp.obj: CMakeFiles\regular-to-graph.dir\flags.make
CMakeFiles\regular-to-graph.dir\RegExprParser.cpp.obj: ..\RegExprParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\RegularToGraph\regular-to-graph\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/regular-to-graph.dir/RegExprParser.cpp.obj"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\regular-to-graph.dir\RegExprParser.cpp.obj /FdCMakeFiles\regular-to-graph.dir\ /FS -c F:\RegularToGraph\regular-to-graph\RegExprParser.cpp
<<

CMakeFiles\regular-to-graph.dir\RegExprParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/regular-to-graph.dir/RegExprParser.cpp.i"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\regular-to-graph.dir\RegExprParser.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\RegularToGraph\regular-to-graph\RegExprParser.cpp
<<

CMakeFiles\regular-to-graph.dir\RegExprParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/regular-to-graph.dir/RegExprParser.cpp.s"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\regular-to-graph.dir\RegExprParser.cpp.s /c F:\RegularToGraph\regular-to-graph\RegExprParser.cpp
<<

CMakeFiles\regular-to-graph.dir\Graph.cpp.obj: CMakeFiles\regular-to-graph.dir\flags.make
CMakeFiles\regular-to-graph.dir\Graph.cpp.obj: ..\Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\RegularToGraph\regular-to-graph\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/regular-to-graph.dir/Graph.cpp.obj"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\regular-to-graph.dir\Graph.cpp.obj /FdCMakeFiles\regular-to-graph.dir\ /FS -c F:\RegularToGraph\regular-to-graph\Graph.cpp
<<

CMakeFiles\regular-to-graph.dir\Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/regular-to-graph.dir/Graph.cpp.i"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\regular-to-graph.dir\Graph.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\RegularToGraph\regular-to-graph\Graph.cpp
<<

CMakeFiles\regular-to-graph.dir\Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/regular-to-graph.dir/Graph.cpp.s"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\regular-to-graph.dir\Graph.cpp.s /c F:\RegularToGraph\regular-to-graph\Graph.cpp
<<

# Object files for target regular-to-graph
regular__to__graph_OBJECTS = \
"CMakeFiles\regular-to-graph.dir\main.cpp.obj" \
"CMakeFiles\regular-to-graph.dir\RegExprParser.cpp.obj" \
"CMakeFiles\regular-to-graph.dir\Graph.cpp.obj"

# External object files for target regular-to-graph
regular__to__graph_EXTERNAL_OBJECTS =

regular-to-graph.exe: CMakeFiles\regular-to-graph.dir\main.cpp.obj
regular-to-graph.exe: CMakeFiles\regular-to-graph.dir\RegExprParser.cpp.obj
regular-to-graph.exe: CMakeFiles\regular-to-graph.dir\Graph.cpp.obj
regular-to-graph.exe: CMakeFiles\regular-to-graph.dir\build.make
regular-to-graph.exe: CMakeFiles\regular-to-graph.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\RegularToGraph\regular-to-graph\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable regular-to-graph.exe"
	"F:\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\regular-to-graph.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\regular-to-graph.dir\objects1.rsp @<<
 /out:regular-to-graph.exe /implib:regular-to-graph.lib /pdb:F:\RegularToGraph\regular-to-graph\cmake-build-debug\regular-to-graph.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\regular-to-graph.dir\build: regular-to-graph.exe

.PHONY : CMakeFiles\regular-to-graph.dir\build

CMakeFiles\regular-to-graph.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\regular-to-graph.dir\cmake_clean.cmake
.PHONY : CMakeFiles\regular-to-graph.dir\clean

CMakeFiles\regular-to-graph.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" F:\RegularToGraph\regular-to-graph F:\RegularToGraph\regular-to-graph F:\RegularToGraph\regular-to-graph\cmake-build-debug F:\RegularToGraph\regular-to-graph\cmake-build-debug F:\RegularToGraph\regular-to-graph\cmake-build-debug\CMakeFiles\regular-to-graph.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\regular-to-graph.dir\depend

