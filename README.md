# CS 102 Final Project

For this project, I am requiring a "Diary"; see the project for more details. I've included one example entry.
## NOTE
We had a lot of issues with Github pushing and pulling that caused some overriding and weirdness in our Github changes. All of our progress is catalogued here in the correct order, but it may not say so on Github. We talked to Prof. Helmuth & James Frazier about this and they said it's fine.

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

-- Pan and Brett

## April 27

Today, we started small by learning more about Ncurses. We watched some videos from the [Making Snake in ncurses playlist by Casual Coder on Youtube](https://www.youtube.com/playlist?list=PL2U2TQ__OrQ_TV2-wuHqGaK8qlnxgKUvK). Then we started thinking about we wanted our game to look. Since it is a vertically scrolling game, we want the game to be taller than it is wide. We also want our window to be able to resize itself to some extent, so that it looks nice on any machine it runs on, instead of just looking nice on my (Pan) computer. We have done some calculations in our main.cc file for this as well as started playing around with the Ncurses functions for windows. Tomorrow, we plan on moving the code we have written for our game windows into a dedicated file and to start designing its methods.

-- Pan and Brett

## April 28

Today, we set up our codebase together and found out how to collaborate our code. We experimented with LiveShare but decided just to keep up to date by pushing and pulling from the repository. We also got the ncurses window to automatically resize based on the size of the terminal. If the terminal is too small, an error message occurs causing the game to fail to start. Additionally, we began working on the Player class and plan to use inheritance for the enemy classes. More specifically, there will be a parent enemy class and there will be subclasses of enemies with different behaviors. Some objects in the game are destructible and will be treated as enemies but with zero movement attributes. There are a lot of questions to think about going forward. Namely, how do we set the player as the thing ncurses is moving around and how do we detect when a projectile hits the player or hits an enemy? (Maybe some kind of hitbox and detection system but it would have to be constantly checking for a collision, no?)

-- Pan and Brett

## April 29

Note: Unfortunately, I (Pan) was following this guide to delete files from the repository using the terminal and ended up deleting this diary entry. (I think it was {git push --force -u origin main} that did it.) So I am now writing this again, at midnight.

For today, we watched most of the remaining videos from the Making Snake in ncurses playlist by Casual Coder on Youtube and looked at the documentation for Ncurses to become more familiar with the library and the process of creating a basic video game. We did some more brainstorming for how we want to implement our player, enemy, items, and projectile classes. The main things we think we will be challenging to implement are collision, enemy movement, and the "vertically scrolling" aspect of the game. If the latter proves to be too challenging, we might not implement it and perhaps explore adding sound. Besides more planning, we followed along with the tutorial videos, updated the Game_Window class and added the Game class. We hope to implement all the important classes and methods shown in the tutorial videos soon so that we can move on to customizing the game and shaping it into what we actually want it to be, not Snake.

-- Pan and Brett

## April 30

A lot of time today was spent on trying to fix and learn how Github's pulling and pushing worked. Currently, our "branches" are different and we're having a lot of trouble with synchronizing our work. As for actual code, work was done on the Player and Enemy classes although the changes have not yet been pushed to Github because we don't know how to synchronize it. The player will be able to move across the bounds of the screen (left and right) and maybe teleport to the other side of the screen once they get to an edge. The alternative is just having the edge be a firm boundary. The enemies will spawn in after random intervals of time (hence our ctime import) and shoot projectiles downwards. The enemy class is a very general parent class that will allow us to make classes for each of the potential enemies as subclasses.

-- Pan and Brett

## May 1

Note: I (Pan) accidentally did {git push --force} again, and this entry is a rewrite.

What we did today:
- We figured out how to properly use VS Code's Live Share and cleaned up our repository.
- The Game_Window class has been updated so that the game window no longer resizes itself. We think that having the window be able to resize itself would make it harder for us to tell the game how to move things. The Game_Window still has a method to detect whether the window of the terminal is too small (its height is less than 40 lines). If it is, the game will print a message containing the current height and the minimum height and not start.
- The Drawable class and its subclasses Empty and Player have been implemented. The Drawable class, adapted from the tutorials, represents an object that can be displayed on the game window. An accompanying Game_Window method to display a Drawable object has also been created. The Player class does not have much now, but we will (tomorrow) define basic information such as initial health, damage, etc.
- At this point, we think we have basically everything we need for our game. We will skim the rest of the tutorials and see what else we might need, but we will start writing our own methods and classes soon.

-- Pan and Brett

## May 2

- We spent the better part of today's lab figuring out how to display and align things within the game window. We thought that when we are moving things within the game window, it would be relative to the terminal's window as the game window is defined relative to the terminal's window. It turns out that it is relative to the game window itself. So, to print an object at the very top of the game window, we simply set y = 1 (not 0, as it would be right on the border) and not ((_max_y / 2) - (HEIGHT / 2)) like in the game window's definition.
- A method, get_top_spaces(), for Game_Window has been implemented. This basically selects a random column at the top of the window (y = 1). What this will be useful for is enemy appearance. A number of them will appear at the top and gradually move down. If they reach the bottom, you lose. This will also be useful for randomly generating dots (representative of the ground), to create the "vertically-scrolling" effect.
- Initial player stats have been defined. We will be implementing player movement tomorrow, then collision.
- The update() method in the Game class has been updated to display both the player and anything else we want.
- Other things we should tackle soon are level generation, representation of that as a data structure (probably vector), export to / import as a file, and operators for our classes.

-- Pan and Brett

## May 3

Today, we updated the get_input() method in the Game class so that it actually processes inputs from the user and changes the operation of the game in some way. The main use for this is controlling the game. Player movement has been added, but is buggy. The game displays the player's icon at all the places it has been placed it does not get rid of the player's previous appearance on the screen. This should be easy to fix. We will rework the add_at() and add() methods of the Game_Window class so that it prints Drawable objects instead of adding them to the window. This weekend, we will refine player movement and work on the gameplay.

-- Pan and Brett

## May 4

- Player movement has been fixed by placing a space at previous position.
- Corner detection for Drawables has been added.
- A draft of move_drawable() has been added. This is supposed to place a space at the Drawable's previous position and update it to the new position. It is currently not working as intended. There might be a problem with the refresh and update functions.
- An Enemy class has been created and we are currently looking at how to move them individually but still keep track of all of them.

-- Pan and Brett

## May 5

- Added a menu system that includes the title screen that has difficulty options and a pause menu that freezes the window and can be activated with 'p'.
- Added documentation for all functions
- Added more comments
- Added Entity class to be a parent of player and enemy classes
- Updated Drawable's move function to be consolidated into one function
- We are going to change the premise of our game a bit. We're hoping to have enemies that pathfind the player. The main mechanic will either be shooting or maze running, we're not sure yet.

-- Pan and Brett

## May 6

- Enemy now has a pathfinding method. This still has to be refined.
- Game Window's get_input() method has been updated so that every time a player presses a key, the enemy does not also move. To achieve this, we watched tutorial 13 from the Making Snake in NCurses playlist. We will review how the code works so we can explain it in our comments.
- Entity now has a get_speed() method for easier access.
- We have started designing mazes. Our next task is to figure out how to have our game read them in.
- We are beginning to design how the game ends and how enemies will catch the player.

-- Pan and Brett

## May 7

- The premise of our game is back to the original: simplified Tyrian.
- Enemy pathfinding has been refined.
- We have added a shoot function. Any enemy that is hit by the laser dies.
- Spawning multiple enemies has been handled with vectors.
- Borders of the game window has been changed. Top side is made up of 'v' and bottom side is made up of '-'.
- Damage detection has been added. If an enemy goes beyond the bottom of the screen or hits the player, the player's heath points decrease by one.
- The game now ends if the player's health points are 0.
- Miscellaneous get functions have been added for the Entity class.
- A draft of the level read functionality has been implemented. This still has to be refined.

-- Pan and Brett

## May 8

The project is complete, Yay!!

To complete the project, we implemented the following changes today:
- Fixed all memory leaks
- Added powerups and implemented an operator to add them to a player
- Powerups: Large beam and health bonus
- Finished the read_waves() function. Making levels is very modular and easy for players too.
- Made game run slightly smoother
- Polished documentation

-- Pan and Brett