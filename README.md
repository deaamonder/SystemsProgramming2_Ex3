# Catan Game Implementation in C++

## Introduction
This project implements a simplified version of the popular board game Catan using C++. It includes classes for players, the game board, settlements, roads, cards, and lands, allowing players to interact with the game through various actions such as placing settlements, rolling dice, trading, and buying development cards.

## Contributors
- **Developer:** @deaamonder

## Course Information
- **Course:** Systems Programming 2
- **University:** Ariel University

## Files Included
- **catan.hpp:** Header file containing the main Catan class and its methods.
- **catan.cpp:** Implementation file for the Catan class methods.
- **player.hpp:** Header file defining the Player class and its methods.
- **player.cpp:** Implementation file for the Player class methods.
- **board.hpp:** Header file for the Board class and its methods.
- **board.cpp:** Implementation file for the Board class methods.
- **land.hpp:** Header file for the Land class and its methods.
- **land.cpp:** Implementation file for the Land class methods.
- **settelment.hpp:** Header file for the Settelment class and its methods.
- **settelment.cpp:** Implementation file for the Settelment class methods.
- **road.hpp:** Header file for the Road class and its methods.
- **Demo.cpp:** Main program demonstrating the usage of the implemented classes.

## How to Compile and Run
To compile the project, use the provided makefile. Simply navigate to the project directory in your terminal and run:
```bash
make

This will compile the project and generate an executable named CatanGame. To run the game, execute:
```bash
./CatanGame
```

Game Instructions
Follow the prompts and instructions provided in the Demo.cpp file to play the game. Each player takes turns placing settlements and roads, rolling dice, trading resources, and buying development cards. The game continues until one player reaches 10 points, at which point they are declared the winner.

Notes
Ensure you have a C++ compiler installed to build the project.
This project assumes a basic understanding of C++ programming concepts such as classes, inheritance, and standard library containers.
Enjoy playing Catan in your terminal!
