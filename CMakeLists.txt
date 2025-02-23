cmake_minimum_required(VERSION 3.10)
project(SpaceInvaders)

# Find ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Source files
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/game.h
)

# Executable
add_executable(space_invaders ${SOURCES})

# Link ncurses
target_link_libraries(space_invaders ${CURSES_LIBRARIES})
