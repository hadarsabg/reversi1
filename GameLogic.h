//
// hadar sabag id 312497126
//

#ifndef EX2NEW_GAMELOGIC_H
#define EX2NEW_GAMELOGIC_H

#include "BoardCell.h"
#include "Board.h"



class GameLogic{
public:
    /**
    *return a list of board cells witch are possible moves for the given player
    * @param player
    * @return vector of board cells
    */
    virtual vector <BoardCell*> getPossibleMoves(Player *player)=0;
    /**
     * swap all cells between board cell to another cell that
     * has the same value as symbol
     * @param boardCell
     * @param symbol
     */
    virtual void swapCells(BoardCell* boardCell, char symbol) const =0;
    //destructor
    ~GameLogic() {};


};


#endif //EX2NEW_GAMELOGIC_H
