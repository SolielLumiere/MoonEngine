set(MATH_LIBRARY moonmath CACHE INTERNAL "")
include_directories(${PROJECT_SOURCE_DIR}/inc/Core/Math)


add_library(${MATH_LIBRARY} STATIC  Math.cpp)
target_link_libraries(${MATH_LIBRARY} PRIVATE sfml-graphics)