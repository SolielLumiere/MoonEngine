set(SPRITESHEET_LIBRARY spritesheet CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/SpriteSheets)


add_library(${SPRITESHEET_LIBRARY} STATIC ISpriteSheet.cpp SpriteSheet.cpp)
target_link_libraries(${SPRITESHEET_LIBRARY} PRIVATE sfml-graphics)