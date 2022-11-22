#= Set SMake requirements then declare project

cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

#- When Makefiles are generated output all command lines by default
# do this to begin with so its easy to see what compiler command/flags are used
# ALso can be done by removing 'set' command and running make as 'make VERBOSE=1'

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 14)

add_executable(mpags-cipher mpags-cipher.cpp 
MPAGSCipher/transformChar.cpp
MPAGSCipher/transformChar.hpp
MPAGSCipher/processCommandLine.cpp
MPAGSCipher/processCommandLine.hpp
MPAGSCipher/RunCeasarCipher.cpp
MPAGSCipher/RunCeasarCipher.hpp
)

target_include_directories(mpags-cipher 
PRIVATE MPAGSCipher)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher 
PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)