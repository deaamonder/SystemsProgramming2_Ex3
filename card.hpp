#ifndef CARD_HPP
#define CARD_HPP

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
            knightCard();
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

#endif // CARD_HPP