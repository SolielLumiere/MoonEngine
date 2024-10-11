set(TEXTURE_LIBRARY textures CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/SpriteSheets)


add_library(${TEXTURE_LIBRARY} STATIC  Texture.cpp TextureLoader.cpp)
target_link_libraries(${TEXTURE_LIBRARY} PRIVATE sfml-graphics)