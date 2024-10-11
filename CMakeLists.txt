cmake_minimum_required(VERSION 3.5.0)
project(MoonEngine VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


add_subdirectory(src)


