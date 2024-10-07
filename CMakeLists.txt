cmake_minimum_required(VERSION 3.0.0)
project(nicole VERSION 0.0.1)
cmake_policy(SET CMP0072 NEW)

set (CMAKE_CXX_STANDARD 11)

set(CXX_FLAGS "-Wall" "-Werror" "-Wextra" "-fsanitize=undefined,address")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_BUILD_TYPE Debug)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(nicole 
    src/main.cpp
    vendor/include/glad/glad.c

    src/base/renderer/Window.cpp
)

link_directories(nicole
    vendor/library
)

target_include_directories(nicole 
    PRIVATE 
    vendor/include
    vendor/library
)

if (APPLE)
    target_link_libraries(nicole "-framework Cocoa")
    target_link_libraries(nicole "-framework OpenGL")
    target_link_libraries(nicole "-framework IOKit")
endif (APPLE)

target_link_libraries(nicole
    glfw
    OpenGL::GL
)

set(CMAKE_BUILD_RPATH ${CMAKE_SOURCE_DIR}/vendor/library/libglfw.3.dylib)
