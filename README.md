# CDefense
CDefense is a wave-based shooter game made with Ncurses. It was made by Brett Hajdaj and Pan Pov as their final project for CPSCI-102 in the Spring of 2024 at Hamilton College.

## Gameplay
- The player (represented as 'A') moves with the arrow or WASD keys and shoot lasers with X key. The game can be paused with the P key. Enemies are represented as 'W'.
- There are two powerups: health and empower, represented as 'H' and 'E' respectively.
  - The health powerup will increase the player's health by 1, while the empower powerup will make the player's lasers much larger for a brief period of time.
  - These powerups will randomly appear in the bottom half of the screen. The player can acquire these powerups by going near them.
- There are three levels provided: easy, medium, and hard. (See the *levels* folder.)
  - These levels are essentially .txt files, that have *n* + 1 lines, where *n* is the number of waves of enemies. The first line of the .txt file is just *n*. Then, there are by *n* lines that are 74-characters long (2 characters less than the width of the game window). For the *x*th line, if the *y*th character is the 'w' character, then an enemy will be spawned on the *y*th column in the game.
 
## Build Instructions
Make sure you have Ncurses installed. If you do not have it installed and are using Ubuntu, you can type the following in your terminal:
```
sudo apt-get install libncurses-dev
```
To make the game, simply use CMake:
```
cmake ./
make
```
To run (assuming you are in the directory of the game), do:
```
./main
```
