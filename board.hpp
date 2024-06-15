#pragma once 

#include <iostream>
#include <vector>
#include "land.hpp"
#include "settelment.hpp"
#include "road.hpp"

using namespace std;

namespace ariel{
    class Board{
        private:
            vector<Land> lands;
            vector<Settelment> settelments;
            vector<Road> roads;

        public:
            /*
            * i prefer to implement the constructor in the .cpp file and not here
            * in the header file.
            */
            Board(vector<Land>& lands, vector<Settelment>& settelments, vector<Road>& Roads);
            /*
            * simple getter for lands array.
            */
            vector<Land> getLands();
            /*
            * function to place a settelment on the board.
            * the function gets an array of three neighbors lands 
            * and placing the settelment between those lands. 
            */
            void placeSettelmentOnBoard(vector<Land> crossRoad);
            /*
            * function to place a road on the board.
            * the function gets a settelment that the road must be connected to 
            * and place the road following to the settelment on the board. 
            */
            void placeRoadOnBoard(Settelment settelment);
    };
}