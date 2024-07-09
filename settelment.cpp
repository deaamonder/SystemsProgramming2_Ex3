#include <iostream>
#include <string>
#include <vector>
#include "settelment.hpp"

using namespace std;

namespace ariel{
    string Settelment::getName(){
        return this->name;
    }

    bool Settelment::get_city(){
        return this->isCity;
    }

    void Settelment::setCity(bool val){
        this->isCity = val;
    }

    vector<Land> Settelment::getLandsAround(){
        return this->landsAround;
    }
}