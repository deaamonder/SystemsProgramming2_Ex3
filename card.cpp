#include "card.hpp"

namespace ariel {
    int knightCard::numOfCard = 0;

    knightCard::knightCard() : Card(true){
        if(numOfCard < 3){
            ++numOfCard; // each time I "build" a new card the number of the
                        //cards created should become bigger.
        }
        else{
            cerr << "cant 'build' the card " << endl;
            return;
        }
    }
}
