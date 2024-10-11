set(COLLISION_LIBRARY collsion CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Collision)

add_library(${COLLISION_LIBRARY} STATIC QuadTreeCollisionEngine.cpp)
target_link_libraries(${COLLISION_LIBRARY} PRIVATE sfml-graphics)