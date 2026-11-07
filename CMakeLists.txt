cmake_minimum_required(VERSION 3.15)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2DGameEngine WIN32
  main.cpp
  window.cpp
  window.h
  renderer.cpp
  renderer.h
)

target_link_libraries(2DGameEngine PRIVATE d2d1)