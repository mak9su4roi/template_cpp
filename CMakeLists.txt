cmake_minimum_required(VERSION 3.15)

#! Check every comment after the "#!"
project(${PROJECT_NAME} C CXX)

##########################################################
# User configurable options of the template
##########################################################
# Note: symbols like WARNINGS_AS_ERRORS in configuration are intentionally variables
# and not CMake options --using options creates too much problem for students.

# Warnings as errors should be imported here -- do not move this line
include(tools/cmake/CompilerWarnings.cmake)

##########################################################
# Project files, packages, libraries and so on
##########################################################

#! Project main executable source compilation
add_executable(${PROJECT_NAME} src/main.cpp
				src/options_parser/options_parser.cpp src/options_parser/options_parser.h)

#! Put path to your project headers
target_include_directories(${PROJECT_NAME} PRIVATE options_parser)

#! Add external packages
# options_parser requires boost::program_options library
find_package(Boost 1.71.0 COMPONENTS program_options system REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::program_options Boost::system)

						
##########################################################
# Fixed CMakeLists.txt part 
##########################################################

INSTALL(PROGRAMS
		$<TARGET_FILE:${PROJECT_NAME}>	# ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
		DESTINATION bin)

# Define ALL_TARGETS variable to use in PVS and Sanitizers
set(ALL_TARGETS ${PROJECT_NAME})

# Include CMake setup
include(tools/cmake/main-config.cmake)