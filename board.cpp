#include <iostream>
#include <vector>
#include <string>
#include "board.hpp"

using namespace std;

namespace ariel{
    Board::Board(vector<Land>& lands, vector<Settelment>& settelments, vector<Road>& Roads){
        this->lands = lands;
        this->settelments = settelments;
        this->roads = Roads;
    }

    vector<Land> Board::getLands(){
        return this->lands;
    }

    vector<Settelment> Board::getSettelments(){
        return this->settelments;
    }

    vector<Road> Board::getRoads(){
        return this->roads;
    }

    void Board::placeSettelmentOnBoard(vector<Land> crossRoad){
        Settelment s("settelment",crossRoad);
        this->settelments.push_back(s);
    }

    void Board::placeRoadOnBoard(Settelment settelement){
        Road r("road");
        this->roads.push_back(r);
    }
}