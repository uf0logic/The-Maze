cmake_minimum_required(VERSION 3.23)
SET (CMAKE_MODULE_LINKER_FLAGS ${CMAKE_MODULE_LINKER_FLAGS_INIT}
$ENV{LDFLAGS}
CACHE STRING "-lncurses")

project(Game1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Game1 src/game.c)

