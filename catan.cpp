#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "catan.hpp"

using namespace std;

namespace ariel{
    Player Catan::chooseStartingPlayer(){
        //same random number generate method as the roll the dice function in
        //the player class , i get the code from "https://www.geeksforgeeks.org/how-to-generate-random-number-in-range-in-cpp/"
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 3);
        int res = distrib(gen);
        switch (res) {
            case 1:
                std::cout << "Player 1 is starting" << std::endl;
                return player1;
            case 2:
                std::cout << "Player 2 is starting" << std::endl;
                return player2;
            default:
                std::cout << "Player 3 is starting" << std::endl;
                return player3;
        }
    }

    Board Catan::getBoard(){
        return this->gameBoard;
    }

    void Catan::printWinner(){
        if(this->player1.getPoints() == 10){
            cout << "player 1 win !" << endl;
        }
        else if(this->player2.getPoints() == 10){
            cout << "player 2 win !" << endl;
        }
        else if(this->player3.getPoints() == 10){
            cout << "player 3 win !" << endl;
        }
        else{
            cout << "none" << endl;
        }
    }
}