//
// hadar sabag id 312497126
// Inbal Zelinger 311247340
//

#include "Board.h"

using namespace std;

Board::Board(int size) : size(size) {

    this->board = new BoardCell** [size];
    //initiate a 2d array with BoardCells objects
    for (int i = 0; i <this->size; ++i) {
        this->board[i] = new BoardCell *[size];
        for (int j = 0; j < this->size; ++j) {
            this->board[i][j] = new BoardCell(i + 1, j + 1);
        }
    }

    //init players start position
    this->board[this->size/2-1][this->size/2-1]->updateCellValue('O');
    this->board[this->size/2][this->size/2]->updateCellValue('O');
    this->board[this->size/2-1][this->size/2]->updateCellValue('X');
    this->board[this->size/2][this->size/2-1]->updateCellValue('X');
}





Board::Board(const Board &boardToCopy) {
    this->size = boardToCopy.size;
    this->board = new BoardCell** [this->size];

    for(int i = 0; i < this->size; ++i) {
        this->board[i] = new BoardCell *[size];
        for (int j = 0; j < this->size; ++j) {
            this->board[i][j] = new BoardCell(i + 1, j + 1);
        }
    }
    for(int i = 0; i < this->size; i++) {
        for(int j = 0; j < this->size ; j++) {
            this->board[i][j] = boardToCopy.board[i][j];
        }
    }
}






Board::~Board() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            delete board[i][j];
        }
    }
    for (int i = 0; i < this->size; i++) {
        delete[] this->board[i];
    }
    delete[] board;
}


bool Board::isValidCell(int row,int col)const {
    return (row>=0 && row<this->size && col>=0 &&col<this->size);
}



int Board::getSize() {
    return this->size;
}

BoardCell * Board::getCellAt(int row, int col)const {
    return this->board[row][col];
}

ostream &operator<<(ostream &out, const Board &board) {
    out<<" ";
    for (int k = 1; k <=board.size ; ++k) {
        out <<"| "<<k<<" ";
    }
    out << "|" << endl;
    for (int i = 0; i <board.size-1; ++i){
        out<<"-----";
    }
    out<<"--"<<endl;
    for (int i = 0; i <board.size; ++i) {
        for (int j = 0; j < board.size; ++j) {
            if(j==0) {
                out << i+1;
            }
            out << "| " << board.getCellAt(i,j)->getCellValue()<< " ";
        }
        out << "|" << endl;
        for (int i = 0; i <board.size-1; ++i){
            out<<"-----";
        }
        out<<"--"<<endl;
    }
    return out;
}












