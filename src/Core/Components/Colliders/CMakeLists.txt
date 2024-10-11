set(COLLISION_COLLIDERS_LIBRARY components_colliders CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Collision/Colliders)

add_library(${COLLISION_COLLIDERS_LIBRARY} STATIC BoxCollider.cpp CircleCollider.cpp ICollider.cpp)
target_link_libraries(${COLLISION_COLLIDERS_LIBRARY} PRIVATE sfml-graphics ${GAMEOBJECT_LIBRARY})