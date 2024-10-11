set(BEHAVIOR_LIBARY behavior CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Behavior)

add_library(${BEHAVIOR_LIBARY} STATIC Behavior.cpp MonoBehavior.cpp)
target_link_libraries(${BEHAVIOR_LIBARY} PRIVATE sfml-graphics ${COMPONENTS_LIBRARY})