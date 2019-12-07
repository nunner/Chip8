cmake_minimum_required(VERSION 3.14)
project(Chip8 C)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED COMPONENTS SDL2::SDL2)
include_directories(Chip8 ${SDL2_INCLUDE_DIRS})
add_executable(Chip8 src/main.c src/cpu.c src/cpu.h src/codes.c src/codes.h src/types.h)
target_link_libraries(Chip8 SDL2::SDL2)