//
// Created by inbal on 23/11/17.
//

#ifndef UNTITLED1_AIPLAYER_H
#define UNTITLED1_AIPLAYER_H


#include "Player.h"

class AiPlayer: public Player {
public:
    AiPlayer(char symbol);
    BoardCell* playOneTurn(vector<BoardCell *>& possibleMoves);


};


#endif //UNTITLED1_AIPLAYER_H
