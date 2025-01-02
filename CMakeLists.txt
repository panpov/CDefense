cmake_minimum_required(VERSION 3.17)
project(CDefense)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -Werror=all -g)

add_executable(
    main
    main.cc
    ./classes/Game_Window.cc
    ./classes/Game.cc
    ./classes/Drawable.cc
    ./classes/Entity.cc
    ./classes/Player.cc
    ./classes/Enemy.cc
    ./classes/Power_up.cc
    ./classes/Time.cc
)

target_link_libraries(main ncurses)
