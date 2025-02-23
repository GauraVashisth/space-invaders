cmake_minimum_required(VERSION 3.16)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set architecture (for Apple Silicon)
if(APPLE AND CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
    message(STATUS "Building for Apple Silicon (arm64)")
    set(CMAKE_OSX_ARCHITECTURES "arm64")
endif()

# Find OpenGL (built-in on macOS)
find_package(OpenGL REQUIRED)

# Homebrew paths for GLFW and GLEW
set(GLFW_PATH "/opt/homebrew/opt/glfw")
set(GLEW_PATH "/opt/homebrew/opt/glew")

include_directories(${GLFW_PATH}/include ${GLEW_PATH}/include)
link_directories(${GLFW_PATH}/lib ${GLEW_PATH}/lib)

# Add executable
add_executable(SpaceInvaders src/main.cpp)

# Link GLFW, GLEW, and OpenGL
target_link_libraries(SpaceInvaders glfw GLEW ${OPENGL_LIBRARIES})

# macOS-specific: Link OpenGL framework
if(APPLE)
    target_link_libraries(SpaceInvaders "-framework OpenGL")
endif()
