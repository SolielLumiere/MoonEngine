set(INTERFACES_LIBRARY interfaces CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Interfaces)


add_library(${INTERFACES_LIBRARY} STATIC IAnimatable.cpp ICollisionEngine.cpp)
target_link_libraries(${INTERFACES_LIBRARY} PRIVATE sfml-graphics ${COMPONENTS_ANIMATION_LIBRARY})