//
// Created by inbal on 23/11/17.
//

#include "AiPlayer.h"
#include "Board.h"
#include "GameLogic.h"

AiPlayer::AiPlayer(char symbol) : Player(symbol) {}



BoardCell *AiPlayer::playOneTurn(vector<BoardCell*> &possibleMoves, Board &b , GameLogic logic) {



    for (int i = 0; i < possibleMoves.size(); ++i) {
        Board imaginarryBoard = b;
        imaginarryBoard.getCellAt(possibleMoves[i]->getCellRow() , possibleMoves[i]->getCellCol());
        //imaginary board.upside.



        if (row == possibleMoves[i]->getCellRow() && col == possibleMoves[i]->getCellCol()) {
        }
    }




    return NULL;
}

