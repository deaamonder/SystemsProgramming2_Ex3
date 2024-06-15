#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "player.hpp"

using namespace std;

namespace ariel{
    void Player::placeSettelment(vector<string> places, vector<int> placesNum, Board board){
        //the length of places and placesNum must be the same
        if(places.size()!=placesNum.size()){
            cerr << "the length must be the same" << endl;
            exit(1);
        }
        vector<Land> lands = board.getLands();
        vector<int> placesIndex = {0};
        int count = 0;
        //check if we can place a settelment
        for(int i=0; i<places.size(); i++){
            for(int j =0; j<lands.size(); j++){
                if(lands[j].getType() == places[i] && lands[j].getNumber() == placesNum[i]){
                    count++;
                    placesIndex.push_back(j);
                }
            }
        }
        //if the places with thier numbers exist
        if(count == places.size()){
            bool neighbors = true;
            //check if they are neighbors
            for(int i=0; i<placesIndex.size()-1; i++){
                for(int j =i; j<placesIndex.size(); j++){
                    if(!lands[i].isNeighbor(lands[j])){
                        neighbors = false;
                    }
                }
            }
            //if all are neighbors place the settelment
            vector<Land> landsAround;
            for(int i=0; i<places.size(); i++){
                Land temp(places[i],placesNum[i]);
                landsAround.push_back(temp);
            }
            Settelment s(this->Name+"'s settelmant",landsAround);
            if(neighbors){
                this->setSettelment(s);
            }
        }
        cout << "cant add the settelmant" << endl;
    }

    void Player::placeRoad(vector<string> places, vector<int> placesNum, Board board){

    }

    int Player::rollDice(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(2,12);
        int dice_res = distrib(gen);
        return dice_res;
    }

    void Player::endTurn(){
        if(this->isHisTurn){
            this->isHisTurn = false;
        }
    }

    void Player::trade(Player other, string myThing, string othersThing, int myThingC, int otherThingC){
        if(this->matterials.empty() || other.getMatterials().empty()){
            cerr << "trade cant be placed" << endl;
            return;
        }
        vector<string> otherMat = other.getMatterials();
        //check if i have the thing i want to trade 
        bool myThingFound = false;
        int countMyThing = 0;
        for(int i=0; i<this->matterials.size(); i++){
            if(this->matterials[i] == myThing){
                countMyThing++;
            }
            if(countMyThing >= myThingC){
                myThingFound = true;
            }
        }
        //check if the other player have the thing i want to trade
        bool otherThingFound = false;
        int otherThingCount = 0;
        for(int i=0; i<otherMat.size(); i++){
            if(otherMat[i] == othersThing){
                otherThingCount++;
            }
            if(otherThingCount >= otherThingC){
                otherThingFound = true;
            }
        }

        if(!myThingFound || !otherThingFound){
            cerr << "trade cant be placed , one of the traders dont have the requird matterial" << 
                "or dont have enough matterials" << endl;
            return;
        }
        
        //if we got here place the trade
        int numOfTradesPlaced = 0;
        for(int i=0; i<this->matterials.size(); i++){
            if(this->matterials[i] == myThing && numOfTradesPlaced < myThingC){
                for(int j =0; j<otherMat.size(); j++){
                    if(otherMat[j] == othersThing && numOfTradesPlaced < myThingC){
                        swapElements(this->matterials, otherMat, i, j);
                        numOfTradesPlaced++;
                    }
                }
            }
        } 
    }

    /*
    * helper function that gets two arrays and two indexes and swap
    * between the first array element at the first index and the second array 
    * element at the second index .
    */
    void swapElements(vector<string>& firstArr, vector<string>& secondArr, int firstIndex, int secondIndex){
        if(firstIndex > firstArr.size() || secondIndex > secondArr.size()){
            cerr << "cant swap elements" << endl;
            return;
        }
        string temp = firstArr[firstIndex];
        firstArr[firstIndex] = secondArr[secondIndex];
        secondArr[secondIndex] = temp;
    }

    void Player::buyDevelopmentCard(){
        //check if the player got the requred materials to buy the card.
        bool hasWool = false, hasOat=false, hasIron=false;
        int ironPlace,oatPlace,woolPlace;
        for(int i=0; i<this->matterials.size(); i++){
            if(this->matterials[i] == "iron"){
                hasIron = true;
                ironPlace = i;
            }
            if(this->matterials[i] == "wool"){
                hasWool = true;
                oatPlace = i;
            }
            if(this->matterials[i] == "oat"){
                hasOat = true;
                woolPlace = i;
            }
            if(hasIron && hasOat && hasWool){
                break;
            }
        }
        if(!hasOat || !hasWool || !hasIron){
            cerr << "player dont have all the required matterials to buy the card" << endl;
            return;
        }
        //if we got here it mean that the player can buy the card
        promotionCard pCard1("monopol");
        promotionCard pCard2("road builder");
        promotionCard pCard3("good year");
        int type;
        cout << "choose number between 1-3 representing the type of card you want to buy " << endl;
        cin >> type;
        if(type < 1 || type > 3){
            cerr << "incorrect number entered, number must be between 1-3" << endl;
            return;
        }
        if(type == 1){
            string whichCard;
            cout << "which promotion card do you want ?" << endl;
            cin >> whichCard;
            if(whichCard == "monopol"){
                this->cardsOwned.push_back(pCard1);
                pCard1.setAvilabilty(false);
                this->matterials.erase(this->matterials.begin() + ironPlace);
                this->matterials.erase(this->matterials.begin() + woolPlace);
                this->matterials.erase(this->matterials.begin() + oatPlace);
            }
            else if(whichCard == "road builder"){
                this->cardsOwned.push_back(pCard2);
                pCard1.setAvilabilty(false);
                this->matterials.erase(this->matterials.begin() + ironPlace);
                this->matterials.erase(this->matterials.begin() + woolPlace);
                this->matterials.erase(this->matterials.begin() + oatPlace);
            }
            else if(whichCard == "good year"){
                this->cardsOwned.push_back(pCard3);
                pCard1.setAvilabilty(false);
                this->matterials.erase(this->matterials.begin() + ironPlace);
                this->matterials.erase(this->matterials.begin() + woolPlace);
                this->matterials.erase(this->matterials.begin() + oatPlace);
            }
        }
        else if(type == 2){
            knightCard kCard();
            this->cardsOwned.push_back(kCard);
            if(this->numOfKnightsCard == 3){
                armyCard army();
                this->cardsOwned.push_back(army);
                this->points = this->points + 2;
            }
        }
        else if(type == 3){
            winCard wCard();
            this->cardsOwned.push_back(wCard);
            this->points++;
        }
    }

    void Player::printPoints(){
        cout << this->points << endl;
    }
}