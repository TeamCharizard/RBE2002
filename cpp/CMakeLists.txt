cmake_minimum_required(VERSION 2.7)
project(charizard)

file(GLOB_RECURSE shared shared/*.cpp)
file(GLOB_RECURSE tests test/*.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

include_directories(shared)
add_library(${PROJECT_NAME} ${shared})
target_link_libraries(${PROJECT_NAME} mraa)

foreach(test ${tests})
  get_filename_component(test_name ${test} NAME_WE)
  add_executable(${test_name} ${test})
  target_link_libraries(${test_name} ${PROJECT_NAME} mraa)
endforeach()
