//
// hadar sabag id 312497126
//

#ifndef EX2NEW_HUMANPLAYER_H
#define EX2NEW_HUMANPLAYER_H

#include "Player.h"
class HumanPlayer: public Player {
public:
    //constructor
    HumanPlayer(char symbol);
    //base class virtual method
    BoardCell* playOneTurn(vector<BoardCell *>& possibleMoves);

};


#endif //EX2NEW_HUMANPLAYER_H
