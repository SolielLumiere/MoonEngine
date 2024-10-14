cmake_minimum_required(VERSION 3.5.0)
project(MoonEngine VERSION 0.1.0 LANGUAGES C CXX)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS system window graphics network audio)
add_compile_definitions(SHOW_COLLIDERS)

include_directories(inc)
add_subdirectory(Examples)
add_subdirectory(src)
