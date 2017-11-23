//
// hadar sabag id 312497126
//

#ifndef EX2NEW_BOARD_H
#define EX2NEW_BOARD_H
#include <iostream>
#include "BoardCell.h"
#include "Player.h"
#include <vector>
using namespace std;

class Board {

public:
    /**
     * constructor- initiate a 2d array with BoardCells
     * @param size
     */
    Board( int size);
    //destructor
    ~Board();
    //override out
    friend ostream &operator <<(ostream &out, const Board &board);



    /**
* function name: Board
* copy constuctor.
* @param - .

**/

    Board(const Board &boardToCopy);


    /**
* function name:  operator =
* foperator =.
**/


    Board& operator = (const Board& b);


    /**
     * check if cell is in board
     * @param row
     * @param col
     * @return true if row,col is in the board range,else-return false
     */
    bool isValidCell(int row,int col)const;
    /**
     * return size of board
     * @return this.size
     */
    int getSize();
    /**
     * return the cell in index [row][col]
     * @param row
     * @param col
     * @return board[row][col]
     */
    BoardCell * getCellAt(int row, int col)const;
private :
    int size;
    BoardCell ***board;

};


#endif //EX2NEW_BOARD_H
