#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "board.hpp"
#include "card.hpp"
#include "land.hpp"

using namespace std;

namespace ariel {
    class Catan {
        private:
            Player player1, player2, player3;
            Board gameBoard;
            vector<Land> lands = {Land("Mountains",10),Land("Mountains",8), Land("Mountains",3),
                         Land("Forest",3), Land("Forest",11), Land("Forest",8),
                         Land("Forest",9), Land("Agricultural land",4), Land("Agricultural land",6),
                         Land("Agricultural land",9), Land("Agricultural land",12),
                         Land("Pasture land",2), Land("Pasture land",4), Land("Pasture land",5),
                         Land("Pasture land",11), Land("Hills",6), Land("Hills",10), Land("Hills",5),
                         Land("Desert",NULL)
            };

        public:
            Catan(Player p1, Player p2, Player p3) : player1(p1),player2(p2),player3(p3),gameBoard(lands){
                
            }
            /*
            * this function should randomly choose the starting player , print it
            * and return it.
            */
            Player chooseStartingPlayer();    
            /*
            * simply return the gameBoard.
            */
            Board getBoard();
            /*
            * this function should print the winner and none if there are no winner
            */
            void printWinner();
    };
}