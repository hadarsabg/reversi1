//
// Created by inbal on 23/11/17.
//

#ifndef UNTITLED1_AIPLAYER_H
#define UNTITLED1_AIPLAYER_H


#include "Player.h"
#include "Board.h"
#include "GameLogic.h"

class AiPlayer: public Player {
public:
    AiPlayer(char symbol);
    BoardCell* playOneTurn(vector<BoardCell *>& possibleMoves , Board &b , GameLogic logic);


};


#endif //UNTITLED1_AIPLAYER_H
