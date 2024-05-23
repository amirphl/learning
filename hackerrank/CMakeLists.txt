# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Hackerrank)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(a main.cpp)

# Enable debugging information
set(CMAKE_BUILD_TYPE Debug)

# Optionally, add more flags for debugging
# This is compiler-specific, here is an example for GCC/Clang
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(a PRIVATE -g -O0)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(a PRIVATE /Zi /Od)
    set_target_properties(a PROPERTIES LINK_FLAGS /DEBUG)
endif()

# If you want to include directories or link libraries, add them here
# target_include_directories(MyExecutable PRIVATE ${CMAKE_SOURCE_DIR}/include)
# target_link_libraries(MyExecutable PRIVATE some_library)
