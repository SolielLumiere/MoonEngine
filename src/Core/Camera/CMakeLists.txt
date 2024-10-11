set(CAMERA_LIBRARY camera CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Camera)

add_library(${CAMERA_LIBRARY} STATIC  Camera.cpp ObserverCamera.cpp)
target_link_libraries(${CAMERA_LIBRARY} PRIVATE sfml-graphics)