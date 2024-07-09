#ifndef LAND_HPP
#define LAND_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace ariel{
    class Land{
        private:
            string type;
            int number;
            string material;
            vector<Land> neighbors;//for each peice of land we want to know who are the neighbors
        
        public:
            Land(string type, int number, vector<Land> n){
                this->number = number;
                this->type = type;
                this->neighbors = n;
                if(this->type == "Forest"){
                    this->material = "wood";
                }
                else if(this->type == "Hills"){
                    this->material = "brick";
                }
                else if(this->type == "Pasture land"){
                    this->material = "wool";
                }
                else if(this->type == "Agricultural land"){
                    this->material = "oat";
                }
                else if(this->type == "Mountains"){
                    this->material = "iron";
                }
                else if(this->type == "Desert"){
                    this->material = " ";
                }
            }

            Land(string type, int number){
                this->number = number;
                this->type = type;
                if(this->type == "Forest"){
                    this->material = "wood";
                }
                else if(this->type == "Hills"){
                    this->material = "brick";
                }
                else if(this->type == "Pasture land"){
                    this->material = "wool";
                }
                else if(this->type == "Agricultural land"){
                    this->material = "oat";
                }
                else if(this->type == "Mountains"){
                    this->material = "iron";
                }
                else if(this->type == "Desert"){
                    this->material = " ";
                }
            }

            //getters
            int getNumber();
            string getType();
            string getMaterial();

            //setter
            void setNumber(int number);

            //neighbors function

            /*
            * return the number of neighbors the land has.
            */
            int numOfNeighbors();
            /*
            * simple getter
            */
            vector<Land> getNeighbors();
            /*
            * this function get a Land and check if this land is its neighbor.
            * if this is the case return true and return false else.
            * note : assuming there are no lands from the same type with the same 
            * number.
            */
            bool isNeighbor(Land other);

    };
}

#endif // LAND_HPP