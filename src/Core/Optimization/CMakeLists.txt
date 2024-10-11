set(OPTTIMIZATION_LIBRARY optimization CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Optimization)


add_library(${OPTTIMIZATION_LIBRARY} STATIC ObjectPoolManager.cpp)
target_link_libraries(${OPTTIMIZATION_LIBRARY} PRIVATE sfml-graphics)