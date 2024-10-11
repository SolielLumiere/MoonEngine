set(COMPONENTS_LIBRARY components CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Components)

add_subdirectory(Animation)
add_subdirectory(Colliders)
add_subdirectory(Motion)

add_library(${COMPONENTS_LIBRARY} STATIC  Component.cpp MousePosition.cpp StateHandler.cpp)
target_link_libraries(${COMPONENTS_LIBRARY} PRIVATE sfml-graphics 
    ${COMPONENTS_ANIMATION_LIBRARY} 
    ${COLLISION_COLLIDERS_LIBRARY} 
    ${COLLISION_MOTION_LIBRARY}
    ${BEHAVIOR_LIBARY})