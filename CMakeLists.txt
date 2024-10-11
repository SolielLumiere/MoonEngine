cmake_minimum_required(VERSION 3.5.0)
project(MoonEngine VERSION 0.1.0 LANGUAGES C CXX)
set(SFML_STATIC_LIBRARIES TRUE)

include_directories(include)
find_package(SFML REQUIRED COMPONENTS system window graphics network audio)



add_subdirectory(src)


