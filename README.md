# CDefense
CDefense is a wave-based shooter game made with ncurses. It was made by Brett Hajdaj and Pan Pov as their final project for CPSCI-102 in the Spring of 2024 at Hamilton College.

<p align="center">
  <img src="https://github.com/panpov/CDefense/blob/main/images/titlescreen.png" width="420" alt="game preview">
  <img src="https://github.com/panpov/CDefense/blob/main/images/preview.png" width="420" alt="title screen">
</p>

## Gameplay and Features

<p align="center">
  <img src="https://github.com/panpov/CDefense/blob/main/images/winscreen.png" width="400" alt="win screen">
</p>

- The player (represented as 'A') moves with the arrow or WASD keys and shoot lasers with X key. The game can be paused with the P key. Enemies are represented as 'W'.
- There are two powerups: health and empower, represented as 'H' and 'E' respectively.
  - The health powerup will increase the player's health by 1, while the empower powerup will make the player's lasers much larger for a brief period of time.
  - These powerups will randomly appear in the bottom half of the screen. The player can acquire these powerups by going near them.
- There are three levels provided: easy, medium, and hard. (See the *levels* folder.)
  - The goal of each level is to defeat all waves of enemies. If an enemy collides with the player or reaches the bottom of the screen, the player loses 1 health point. If the player's health reaches 0, the game ends.
  - These levels are essentially .txt files, that have *n* + 1 lines, where *n* is the number of waves of enemies. The first line of the .txt file is just *n*. Then, there are *n* lines that are 74-characters long (2 characters less than the width of the game window). For the *x*th line, if the *y*th character is the 'w' character, then an enemy will be spawned on the *y*th column in the game's *x*th wave. You can look at the provided .txt files and edit them as you please; make the levels harder, easier, longer, etc.
 
## Build Instructions
Make sure you have ncurses and CMake installed. If you do not have both installed and are using Ubuntu, you can type the following in your terminal:
```
sudo apt-get install libncurses-dev cmake
```
First, clone the repository:
```
git clone https://github.com/panpov/CDefense.git
```
To make the game, change into the game's directory and use CMake:
```
cd CDefense
mkdir build
cd build
cmake ..
make
```
To run (assuming you are in the directory of the game), do:
```
./cdefense
```
