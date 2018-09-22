cmake_minimum_required(VERSION 3.8)
project(Acryl2D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")


include_directories(${PROJECT_SOURCE_DIR}/source/)
include_directories(${PROJECT_SOURCE_DIR}/external/include/)

link_directories(${PROJECT_SOURCE_DIR}/external/lib/SDL2/)

set(SOURCE_FILES source/test/main.cpp source/engine/acryl2d.cpp source/engine/acryl2d.h)
add_executable(Acryl2D ${SOURCE_FILES})

target_link_libraries(Acryl2D mingw32 SDL2main SDL2)