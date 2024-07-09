#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "card.hpp"
#include "board.hpp"
#include "settelment.hpp"
#include "road.hpp"

using namespace std;

namespace ariel{
    class Player{
        private:
            string Name;
            bool isHisTurn;
            int points;
            int numOfKnightsCard;
            vector<Card> cardsOwned;
            vector<string> matterials;
            vector<Settelment> settelments;
            vector<Road> roads;
        public:
            Player(string name){
                this->Name = name;
                this->points = 2; //each player start with 2 points
                this->numOfKnightsCard = 0;
            }

            /*
            * this function gets the places where to set a settelment and their numbers
            * and place a settelment for the player.
            */
            void placeSettelment(vector<string> places, vector<int> placesNum, Board board);
            /*
            * this function gets the places , their numbers and the game board and set a road.
            */
            void placeRoad(vector<string> places, vector<int> placesNum, Board board);
            /*
            * roll a random number between 1 and the max land number on the board and print
            * it and return it. if the player call this function not on his turn we get
            * an error .
            */
            int rollDice();
            /*
            * ends the player turn.
            */
            void endTurn();
            /*
            * this function get a player i want to trade with , the thing I want to trade 
            * the thing i want from the other player , number of pieces of my thing 
            * number of pieces from his thing. and the function place a trade according 
            * to the game roles .
            * note : in the myThingC and otherThingC the "C" at the end stand for capacity. 
            */
            void trade(Player other, string myThing, string othersThing, int myThingC, int otherThingC);
            /*
            * this function allow the player to buy a development card for materials
            * (iron,wood,etc...)
            */
            void buyDevelopmentCard();
            /*
            * this function simpley print the amount of points of the player. 
            */
            void printPoints();
            /*
            * set a settelment
            */
            void setSettelment(Settelment s);
            /*
            * matterials getter
            */
            vector<string> getMatterials();
            /*
            * points getter
            */
            int getPoints();
            /*
            * name getter
            */
            string getName();

    };
}

#endif // PLAYER_HPP