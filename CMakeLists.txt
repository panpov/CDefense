cmake_minimum_required(VERSION 3.17)
project(project09)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -Werror=all -g)

add_library(ncurses STATIC IMPORTED)
set_property(TARGET ncurses PROPERTY
             IMPORTED_LOCATION "./ncurses-6.2/myinstall/lib/libncurses.a")

include_directories(BEFORE SYSTEM ./ncurses-6.2/myinstall/include)

add_executable(
    main
    main.cc
    ./classes/Game_Window.cc
    ./classes/Game.cc
    ./classes/Drawable.cc
    ./classes/Empty.cc
    ./classes/Player.cc
)

target_link_libraries(main ncurses)
