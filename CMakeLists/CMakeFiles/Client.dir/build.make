# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /root/Documents/VSCode/Multicast/ClientCopy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Documents/VSCode/Multicast/ClientCopy/CMakeLists

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/Src/MulticastServer.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Src/MulticastServer.cpp.o: ../Src/MulticastServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/Src/MulticastServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Src/MulticastServer.cpp.o -c /root/Documents/VSCode/Multicast/ClientCopy/Src/MulticastServer.cpp

CMakeFiles/Client.dir/Src/MulticastServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Src/MulticastServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/VSCode/Multicast/ClientCopy/Src/MulticastServer.cpp > CMakeFiles/Client.dir/Src/MulticastServer.cpp.i

CMakeFiles/Client.dir/Src/MulticastServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Src/MulticastServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/VSCode/Multicast/ClientCopy/Src/MulticastServer.cpp -o CMakeFiles/Client.dir/Src/MulticastServer.cpp.s

CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.o: ../Src/ReceiveSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.o -c /root/Documents/VSCode/Multicast/ClientCopy/Src/ReceiveSocket.cpp

CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/VSCode/Multicast/ClientCopy/Src/ReceiveSocket.cpp > CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.i

CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/VSCode/Multicast/ClientCopy/Src/ReceiveSocket.cpp -o CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.s

CMakeFiles/Client.dir/Src/RedisCommand.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Src/RedisCommand.cpp.o: ../Src/RedisCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Client.dir/Src/RedisCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Src/RedisCommand.cpp.o -c /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisCommand.cpp

CMakeFiles/Client.dir/Src/RedisCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Src/RedisCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisCommand.cpp > CMakeFiles/Client.dir/Src/RedisCommand.cpp.i

CMakeFiles/Client.dir/Src/RedisCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Src/RedisCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisCommand.cpp -o CMakeFiles/Client.dir/Src/RedisCommand.cpp.s

CMakeFiles/Client.dir/Src/RedisConnection.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Src/RedisConnection.cpp.o: ../Src/RedisConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Client.dir/Src/RedisConnection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Src/RedisConnection.cpp.o -c /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisConnection.cpp

CMakeFiles/Client.dir/Src/RedisConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Src/RedisConnection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisConnection.cpp > CMakeFiles/Client.dir/Src/RedisConnection.cpp.i

CMakeFiles/Client.dir/Src/RedisConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Src/RedisConnection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisConnection.cpp -o CMakeFiles/Client.dir/Src/RedisConnection.cpp.s

CMakeFiles/Client.dir/Src/RedisDriver.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Src/RedisDriver.cpp.o: ../Src/RedisDriver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Client.dir/Src/RedisDriver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Src/RedisDriver.cpp.o -c /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisDriver.cpp

CMakeFiles/Client.dir/Src/RedisDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Src/RedisDriver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisDriver.cpp > CMakeFiles/Client.dir/Src/RedisDriver.cpp.i

CMakeFiles/Client.dir/Src/RedisDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Src/RedisDriver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/VSCode/Multicast/ClientCopy/Src/RedisDriver.cpp -o CMakeFiles/Client.dir/Src/RedisDriver.cpp.s

CMakeFiles/Client.dir/Src/SendSocket.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Src/SendSocket.cpp.o: ../Src/SendSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Client.dir/Src/SendSocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/Src/SendSocket.cpp.o -c /root/Documents/VSCode/Multicast/ClientCopy/Src/SendSocket.cpp

CMakeFiles/Client.dir/Src/SendSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Src/SendSocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/VSCode/Multicast/ClientCopy/Src/SendSocket.cpp > CMakeFiles/Client.dir/Src/SendSocket.cpp.i

CMakeFiles/Client.dir/Src/SendSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Src/SendSocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/VSCode/Multicast/ClientCopy/Src/SendSocket.cpp -o CMakeFiles/Client.dir/Src/SendSocket.cpp.s

CMakeFiles/Client.dir/main.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Client.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/main.cpp.o -c /root/Documents/VSCode/Multicast/ClientCopy/main.cpp

CMakeFiles/Client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Documents/VSCode/Multicast/ClientCopy/main.cpp > CMakeFiles/Client.dir/main.cpp.i

CMakeFiles/Client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Documents/VSCode/Multicast/ClientCopy/main.cpp -o CMakeFiles/Client.dir/main.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/Src/MulticastServer.cpp.o" \
"CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.o" \
"CMakeFiles/Client.dir/Src/RedisCommand.cpp.o" \
"CMakeFiles/Client.dir/Src/RedisConnection.cpp.o" \
"CMakeFiles/Client.dir/Src/RedisDriver.cpp.o" \
"CMakeFiles/Client.dir/Src/SendSocket.cpp.o" \
"CMakeFiles/Client.dir/main.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/Src/MulticastServer.cpp.o
Client: CMakeFiles/Client.dir/Src/ReceiveSocket.cpp.o
Client: CMakeFiles/Client.dir/Src/RedisCommand.cpp.o
Client: CMakeFiles/Client.dir/Src/RedisConnection.cpp.o
Client: CMakeFiles/Client.dir/Src/RedisDriver.cpp.o
Client: CMakeFiles/Client.dir/Src/SendSocket.cpp.o
Client: CMakeFiles/Client.dir/main.cpp.o
Client: CMakeFiles/Client.dir/build.make
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd /root/Documents/VSCode/Multicast/ClientCopy/CMakeLists && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Documents/VSCode/Multicast/ClientCopy /root/Documents/VSCode/Multicast/ClientCopy /root/Documents/VSCode/Multicast/ClientCopy/CMakeLists /root/Documents/VSCode/Multicast/ClientCopy/CMakeLists /root/Documents/VSCode/Multicast/ClientCopy/CMakeLists/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

