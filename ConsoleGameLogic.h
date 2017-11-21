//
// Created by hadar on 13/11/17.
//

#ifndef EX2NEW_CONSOLEGAMELOGIC_H
#define EX2NEW_CONSOLEGAMELOGIC_H

#include "GameLogic.h"

class ConsoleGameLogic: public GameLogic {
public:
    //constructor
     ConsoleGameLogic(Board *board);
    /**
    *return a list of board cells witch are possible moves for the given player
    * @param player
    * @return vector of board cells
    */
    vector <BoardCell*> getPossibleMoves(Player *player);
    /**
     * swap all cells between board cell to another cell that
     * has the same value as symbol
     * @param boardCell
     * @param symbol
     */
    void swapCells(BoardCell* boardCell, char symbol) const ;
    //destructor
    ~ConsoleGameLogic();

private:
    Board* board;

};




#endif //EX2NEW_CONSOLEGAMELOGIC_H
