set(COLLISION_MOTION_LIBRARY components_motion CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Collision/Motion)

add_library(${COLLISION_MOTION_LIBRARY} STATIC Follower.cpp)
target_link_libraries(${COLLISION_MOTION_LIBRARY} PRIVATE sfml-graphics)