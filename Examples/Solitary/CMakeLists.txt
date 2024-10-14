
set(SOLITARY solitary)
include_directories(inc)

set(SOURCES 
    main.cpp 
    src/Cards/Card.cpp 
    src/States/GameState.cpp
    src/Textures/CardsTextures.cpp
    
)


add_executable(${SOLITARY} ${SOURCES})

target_link_libraries(${SOLITARY} ${MOON_LIBRARY})
target_compile_features(${SOLITARY} PRIVATE cxx_std_17)