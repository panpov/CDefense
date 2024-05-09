#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

#include "Game_Window.h"
#include "Player.h"
#include "Enemy.h"
#include "Power_up.h"

#define HARD_SPEED 5
#define MED_SPEED 6
#define EASY_SPEED 8
#define CLEAN_FREQ 5
#define PWUP_FREQ 150
#define EMPOWER_DURATION 200
#define LASER_ICON 'O'

void operator+(const Player & player, const Power_up & pwup);

class Game {
private:
    Game_Window _game_window;
    int _tick;
    chtype _difficulty;
    bool _game_over;
    Player _player;

    std::vector<Power_up *> _pwups;
    int _num_pwups;

    std::vector<Enemy *> _enemies;
    int _num_enemies;
    int _enemy_speed;
    
    std::ifstream _level;
    std::vector<std::string> _waves;
    int _total_waves;
    int _curr_wave_num;

public:
    Game();
    ~Game();
    bool init();
    void get_input();
    void update();
    void refresh();
    void clean();
    bool game_over();
    void info();

    void move_entity(Entity & entity, int delta_y, int delta_x);

    void player_movement(chtype input);
    void shoot();
    void detect_damage();
    
    void enemies_init(std::vector<int> locations);
    void enemy_roam();

    void spawn_pwup();
    void pwup();

    void menu();
    void loss();
    void victory();

    void load_level();
    void next_wave();
    void check_wave();
};

#endif // GAME_H