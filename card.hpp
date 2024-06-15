#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    class Card{
        protected:
            bool isAvailable;
            const string price = "1 iron 1 wool 1 oat";

        public:
            Card(bool isA){
                this->isAvailable = isA;
            }

            string getPrice(){
                return this->price;
            }

            void setAvilabilty(bool A){
                this->isAvailable = A;
            }
    };

    class promotionCard : public Card {
        private:
            string type;
        public:
            promotionCard(string type) : Card(true){
                this->type = type;
            }
    };

    class knightCard : public Card{
        private:
            static int numOfCard; // there are only 3 cards from this type.
        
        public:
            knightCard() : Card(true){
                if(numOfCard < 3){
                    numOfCard++; // each time I "build" a new card the number of the
                                //cards created should become bigger.
                }
                else{
                    cerr << "cant 'build' the card " << endl;
                    return;
                }
            }
        
    };

    class armyCard : public Card{
        public:
            armyCard() : Card(true){}
    };

    class winCard : public Card{
        public:
            winCard() : Card(true){}     
    };
}