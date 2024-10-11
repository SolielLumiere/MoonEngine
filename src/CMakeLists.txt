add_subdirectory(Core)

include_directories(${PROJECT_SOURCE_DIR}/inc)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-audio sfml-system)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)