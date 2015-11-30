cmake_minimum_required(VERSION 2.7)
project(lidar)
file(GLOB_RECURSE shared shared/*.cpp)
file(GLOB_RECURSE main main/*.cpp)

set(tests point teleop wallFollow)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

add_executable(main ${shared} ${main})
target_include_directories(main PUBLIC shared)
target_link_libraries(main mraa)

foreach(test ${tests})
  message("building test ${test}")
  add_executable(TEST_${test} ${shared} test/${test}.cpp)
  target_include_directories(TEST_${test} PUBLIC shared)
  target_link_libraries(TEST_${test} mraa)

endforeach()

target_link_libraries(TEST_teleop ncurses)
