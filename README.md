# CS 102 Final Project

For this project, I am requiring a "Diary"; see the project for more details. I've included one example entry.

# Diary Entries

## April 23

Prof. Helmuth setup the repository:
- I created a .gitignore file, to make git not track unneeded files.
- I copied Prof. Strash's CMakeLists.txt file from last semester. You'll learn how to use this in lab this week.
- I made this readme!

## April 26

Initial idea: Ncurses Tyrian
- Two modes: random / levels
- Save file to keep track of general stats (unlocked ships, enemies destroyed, etc.)
- Features: level editor (import/export), adjustable difficulty, mini bosses, different ships, power ups

Brett and I want to implement a fun game for this final project. The game we have been thinking about is Tyrian, a retro vertically-scrolling shoot-em-up game. Though we do not have much experience implementing C++ programs that utilize graphics, we still want it to be visually appealing yet simple. To this end, we will utilize the Ncurses library.

We would like to implement what we think are the main features of not just Tyrian but a typical vertically-scrolling shoot-em-up game, including past-paced gameplay involving mini bosses, power ups, and progressive difficulty. Two of the data structures we plan on using are queues (for power up selection) and vectors (for waves of enemies). We will definitely be using templated classes for power ups, types of ships, mini bosses, and types of enemies. Since we will be dealing with damage and health systems in this project, we will have many ways to utilize operators for our classes. We are not yet sure what data structure we are going to use to represent a level of the game (what enemies will show up, when, where, etc). One way we will have the program write to or read from files is through player save files, which will keep track of general statistics and unlocked items. The other, perhaps more interesting, way is for the program to be able to export a randomly generated level file, which players can edit, perhaps to make more or less challenging, as well as import it for players to complete.

The game will probably be silent, unless we decide to make use of a sound library.

- Pan and Brett

## April 27

Today, we started small by learning more about Ncurses. We watched some videos from the [Making Snake in ncurses playlist by Casual Coder on Youtube]([url](https://www.youtube.com/playlist?list=PL2U2TQ__OrQ_TV2-wuHqGaK8qlnxgKUvK)). Then we started thinking about we wanted our game to look. Since it is a vertically scrolling game, we want the game to be taller than it is wide. We also want our window to be able to resize itself to some extent, so that it looks nice on any machine it runs on, instead of just looking nice on my (Pan) computer. We have done some calculations in our main.cc file for this as well as started playing around with the Ncurses functions for windows. Tomorrow, we plan on moving the code we have written for our game windows into a dedicated file and start designing its methods.

- Pan and Brett

## April 28

Today, we set up our codebase together and found out how to collaborate our code. We experimented with LiveShare but decided just to keep up to date by pushing and pulling from the repository. We also got the ncurses window to automatically resize based on the size of the terminal. If the terminal is too small, an error message occurs causing the game to fail to start. Additionally, we began working on the Player class and plan to use inheritance for the enemy classes. More specifically, there will be a parent enemy class and there will be subclasses of enemies with different behaviors. Some objects in the game are destructible and will be treated as enemies but with zero movement attributes. There are a lot of questions to think about going forward. Namely, How do we set the player as the thing ncruses is moving around and how do we detect when a projectile hits the player or hits an enemy? (Maybe some kind of hitbox and detection system but it would have to be constantly checking for a collision, no?).

- Pan and Brett
