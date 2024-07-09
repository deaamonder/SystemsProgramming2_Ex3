#ifndef ROAD_HPP
#define ROAD_HPP

#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    class Road{
        private:
            string name;


        public:
            Road(string name){
                this->name=name;
            }

            /*
            * name getter
            */
           string getName();
    };
}

#endif // ROAD_HPP