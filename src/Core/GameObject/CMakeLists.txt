set(GAMEOBJECT_LIBRARY gameobject CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/GameObject)


add_library(${GAMEOBJECT_LIBRARY} STATIC ChildGameObject.cpp GameObject.cpp)
target_link_libraries(${GAMEOBJECT_LIBRARY} PRIVATE sfml-graphics ${MATH_LIBRARY} ${BEHAVIOR_LIBARY})