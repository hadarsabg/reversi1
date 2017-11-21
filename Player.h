//
// hadar sabag id 312497126
//

#ifndef EX2NEW_PLAYER_H
#define EX2NEW_PLAYER_H


#include <iostream>
#include <vector>
#include "BoardCell.h"


using namespace std;

class Player {
public:
    //constructor
    Player(char symbol);
    //destructor
    ~Player();
    /**
    * prints possible moves for player,
    * scan player input,
    * return the cell the player choose
    * @param possibleMoves
    * @return a pointer to a cell the player choose
    */
    virtual BoardCell* playOneTurn(vector <BoardCell*>& possibleMoves)= 0;
    /**
     * return player symbol
     * @return this.symbol
     */
    char getSymbol() const;

private:
    char symbol;

};


#endif //EX2NEW_PLAYER_H
