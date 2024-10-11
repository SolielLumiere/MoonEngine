set(GAME_LIBRARY game CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Game)


add_library(${GAME_LIBRARY} STATIC Game.cpp IGame.cpp)
target_link_libraries(${GAME_LIBRARY} PRIVATE sfml-graphics ${STATES_LIBRARY})