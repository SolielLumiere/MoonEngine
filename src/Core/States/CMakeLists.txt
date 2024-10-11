set(STATES_LIBRARY states CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/SpriteSheets)


add_library(${STATES_LIBRARY} STATIC  State.cpp)
target_link_libraries(${STATES_LIBRARY} PRIVATE sfml-graphics ${GAMEOBJECT_LIBRARY})