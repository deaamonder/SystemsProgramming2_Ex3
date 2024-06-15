#include <iostream>
#include <vector>
#include <string>
#include "board.hpp"

using namespace std;

namespace ariel{
    Board::Board(vector<Land> lands, vector<Settelment> settelments, vector<Road> Roads){
        this->lands = lands;
        this->settelments = settelments;
        this->roads = Roads;
    }
}