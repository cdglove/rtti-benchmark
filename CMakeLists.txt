###############################################################################
# rtti-benchmark/CMakeLists.txt
#
# Copyright Chris Glover 2016
#
# Distributed under the Boost Software License, Version 1.0.
# http://www.boost.org/LICENSE_1_0.txt
#
###############################################################################
cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 14)

###############################################################################
#
# Configure packages
#
###############################################################################
include(contrib/cmaketools/external_git.cmake)

###############################################################################
#
# Find google benchmark
#
###############################################################################
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
add_external_git_repo(
	URL "https://github.com/google/benchmark.git"
	TAG "v1.0.0"
	PREFIX "contrib/google/benchmark"
	ALWAYS_UPDATE)
 
set(Boost_USE_MULTI_THREADED ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED)

add_executable(rtti-benchmark main.cpp factory.cpp)
target_link_libraries(rtti-benchmark PUBLIC benchmark)
target_include_directories(rtti-benchmark PRIVATE ${Boost_INCLUDE_DIR})
