#include <iostream>
#include <vector>
#include <string>
#include "land.hpp"

using namespace std;

namespace ariel{
    int Land::getNumber(){
        return this->number;
    }

    string Land::getType(){
        return this->type;
    }

    string Land::getMaterial(){
        return this->material;
    }

    void Land::setNumber(int number){
        this->number = number;
    }

    int Land::numOfNeighbors(){
        return neighbors.size();
    }

    vector<Land> Land::getNeighbors(){
        return this->neighbors;
    }

    bool Land::isNeighbor(Land other){
        bool res = false;
        for(int i=0; i<other.numOfNeighbors(); i++){
            if(other.getNeighbors()[i].getType() == this->getType() && 
                other.getNeighbors()[i].getNumber() == this->getNumber()){
                res =true;
            }
        }
        return res;
    }
}