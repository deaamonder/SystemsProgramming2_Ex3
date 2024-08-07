#ifndef SETTELMENT_HPP
#define SETTELMENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "land.hpp"

using namespace std;

namespace ariel{
    class Settelment{
        private:
            string name;
            bool isCity = false;//a settelment is not city by default
            vector<Land> landsAround;

        public:
            Settelment(string name, vector<Land> landsAround){
                this->name=name;
                this->landsAround = landsAround;
            }
            /*
            * name getter
            */
            string getName();
            /*
            * city getter
            */
            bool get_city();
            /*
            * city setter 
            */
            void setCity(bool val);
            /*
            * lands getter
            */
            vector<Land> getLandsAround();
        
    };
}

#endif // SETTELMENT_HPP