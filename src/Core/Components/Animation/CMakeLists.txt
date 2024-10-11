set(COMPONENTS_ANIMATION_LIBRARY components_animation CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Components/Animation)

add_library(${COMPONENTS_ANIMATION_LIBRARY} STATIC ErasableRectAnimation.cpp RectAnimation.cpp)
target_link_libraries(${COMPONENTS_ANIMATION_LIBRARY} PRIVATE sfml-graphics ${GAMEOBJECT_LIBRARY})