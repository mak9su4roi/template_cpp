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
add_executable(${PROJECT_NAME} src/main.cc
				src/options_parser/options_parser.cc src/options_parser/options_parser.h)

#! Put path to your project headers
target_include_directories(${PROJECT_NAME} PRIVATE options_parser)

#! Add external packages
# options_parser requires boost::program_options library
find_package(Boost 1.71.0 COMPONENTS program_options system REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::program_options Boost::system)


##########################################################
# Fixed CMakeLists.txt part 
##########################################################

INSTALL(PROGRAMS
		$<TARGET_FILE:${PROJECT_NAME}>	# ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
		DESTINATION bin)

#########################################################
# GTEST part
#########################################################


find_package(GTest CONFIG REQUIRED)
add_executable( ${PROJECT_NAME}.test src/main.test.cc
				src/options_parser/options_parser.cc src/options_parser/options_parser.h
)

target_include_directories(${PROJECT_NAME}.test PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(
  ${PROJECT_NAME}.test
  PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main Boost::program_options Boost::system
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}.test)
enable_testing()

#########################################################
# GBenchmark
#########################################################
find_package(benchmark CONFIG REQUIRED)
#target_link_libraries(main PRIVATE benchmark::benchmark benchmark::benchmark_main)
add_executable( ${PROJECT_NAME}.bench src/main.bench.cc
				src/options_parser/options_parser.cc src/options_parser/options_parser.h
)

target_include_directories(${PROJECT_NAME}.bench PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(
  ${PROJECT_NAME}.bench
  PRIVATE  benchmark::benchmark benchmark::benchmark_main Boost::program_options Boost::system
)

include(CTest)
add_test(NAME GBENCH_1 COMMAND ${PROJECT_NAME}.bench --benchmark_filter=BM_StringCreation)
add_test(NAME GBENCH_2 COMMAND ${PROJECT_NAME}.bench --benchmark_filter=BM_StringCopy)
enable_testing()
# Define ALL_TARGETS variable to use in PVS and Sanitizers
set(ALL_TARGETS ${PROJECT_NAME})

# Include CMake setup
include(tools/cmake/main-config.cmake)