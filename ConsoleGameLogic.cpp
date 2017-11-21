//
// Created by hadar on 13/11/17.
//

#include "ConsoleGameLogic.h"
ConsoleGameLogic::ConsoleGameLogic(Board *board) : board(board) {}

vector<BoardCell *> ConsoleGameLogic::getPossibleMoves(Player *player) {
        vector < BoardCell* > possibleCells;
        char other;
        if (player->getSymbol() == 'X') {
            other = 'O';
        } else {
            other = 'X';
        }
        for (int i = 0; i < board->getSize(); ++i) {
            for (int j = 0; j < board->getSize(); ++j) {
                if (board->getCellAt(i,j)->getCellValue() == player->getSymbol()) {

                    //check up-left direction
                    int currRow = i - 1, currCol = j - 1;
                    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
                        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue() == other) {
                            currRow--;
                            currCol--;
                        }
                        if (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->isEmpty()) {
                            possibleCells.push_back(this->board->getCellAt(currRow,currCol));
                        }
                    }
                    //check up direction
                    currRow = i - 1, currCol = j;
                    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
                        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue() == other) {
                            currRow--;
                        }
                        if (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->isEmpty()) {
                            possibleCells.push_back(this->board->getCellAt(currRow,currCol));
                        }
                    }
                    //check up-right direction
                    currRow = i - 1, currCol = j + 1;
                    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
                        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue() == other){
                            currRow--;
                            currCol++;
                        }
                        if (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->isEmpty()) {
                            possibleCells.push_back(this->board->getCellAt(currRow,currCol));
                        }
                    }

                    //check left direction
                    currRow = i, currCol = j - 1;
                    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
                        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue() == other) {
                            currCol--;
                        }
                        if (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->isEmpty()) {
                            possibleCells.push_back(this->board->getCellAt(currRow,currCol));
                        }
                    }
                    //check right direction
                    currRow = i, currCol = j + 1;
                    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
                        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue() == other) {
                            currCol++;
                        }
                        if (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->isEmpty()) {
                            possibleCells.push_back(this->board->getCellAt(currRow,currCol));
                        }
                    }
                    //check down-left direction
                    currRow = i + 1, currCol = j - 1;
                    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
                        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue() == other) {
                            currRow++;
                            currCol--;
                        }
                        if (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->isEmpty()) {
                            possibleCells.push_back(this->board->getCellAt(currRow,currCol));
                        }
                    }
                    //check down direction
                    currRow = i + 1, currCol = j;
                    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
                        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue() == other) {
                            currRow++;
                        }
                        if (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->isEmpty()) {
                            possibleCells.push_back(this->board->getCellAt(currRow,currCol));
                        }
                    }
                    //check down-right direction
                    currRow = i + 1, currCol = j + 1;
                    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
                        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue() == other) {
                            currRow++;
                            currCol++;
                        }
                        if (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->isEmpty()) {
                            possibleCells.push_back(this->board->getCellAt(currRow,currCol));
                        }
                    }
                }
            }
        }
        for (int k = 0; k <possibleCells.size() ; ++k) {
            for (int i = 0; i <possibleCells.size() ; ++i) {
                if(i!=k) {
                    if (possibleCells[k] == possibleCells[i]) {
                        possibleCells.erase(possibleCells.begin() + i);
                    }
                }

            }

        }
        return possibleCells;
    }

void ConsoleGameLogic::swapCells(BoardCell *boardCell, char symbol) const {

    char other;
    if(symbol=='X') {
        other = 'O';
    } else{ other='X';
    }
    int r=boardCell->getCellRow()-1;
    int c=boardCell->getCellCol()-1;
    this->board->getCellAt(r,c)->updateCellValue(symbol);
    //check up-left direction
    int currRow = r - 1, currCol = c - 1;
    int counter=0;
    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
            counter++;
            currRow--;
            currCol--;
        }
        if(this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==symbol){
            for (int i = 0; i <counter ; ++i) {
                currRow++;
                currCol++;
                this->board->getCellAt(currRow,currCol)->flip();
            }
        }

    }

    //check up direction
    currRow = r - 1, currCol = c;
    counter=0;
    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
            counter++;
            currRow--;
        }
        if(this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==symbol){
            for (int i = 0; i <counter ; ++i) {
                currRow++;
                this->board->getCellAt(currRow,currCol)->flip();
            }
        }

    }

    //check up-right direction
    currRow = r - 1, currCol = c + 1;
    counter=0;
    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
        while (this->board->isValidCell(currRow, currCol) &&
               this->board->getCellAt(currRow, currCol)->getCellValue() == other) {
            counter++;
            currRow--;
            currCol++;
        }
        if (this->board->isValidCell(currRow, currCol) &&
            this->board->getCellAt(currRow, currCol)->getCellValue() == symbol) {
            for (int i = 0; i < counter; ++i) {
                currRow++;
                currCol--;
                this->board->getCellAt(currRow, currCol)->flip();
            }
        }
    }
    //check left direction
    currRow = r, currCol = c - 1;
    counter=0;
    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
        while (this->board->isValidCell(currRow, currCol) &&
               this->board->getCellAt(currRow, currCol)->getCellValue() == other) {
            counter++;
            currCol--;
        }
        if (this->board->isValidCell(currRow, currCol) &&
            this->board->getCellAt(currRow, currCol)->getCellValue() == symbol) {
            for (int i = 0; i < counter; ++i) {
                currCol++;
                this->board->getCellAt(currRow, currCol)->flip();
            }
        }
    }
    //check right direction
    currRow = r, currCol = c + 1;
    counter=0;
    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
            counter++;
            currCol++;
        }
        if(this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==symbol){
            for (int i = 0; i <counter ; ++i) {
                currCol--;
                this->board->getCellAt(currRow,currCol)->flip();
            }
        }
    }
    //check down-left direction
    currRow = r + 1, currCol = c - 1;
    counter=0;
    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
            counter++;
            currRow++;
            currCol--;
        }
        if(this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==symbol){
            for (int i = 0; i <counter ; ++i) {
                currRow--;
                currCol++;
                this->board->getCellAt(currRow,currCol)->flip();
            }
        }
    }
    //check down direction
    currRow = r + 1, currCol = c;
    counter=0;
    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
            counter++;
            currRow++;
        }
        if(this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==symbol){
            for (int i = 0; i <counter ; ++i) {
                currRow--;
                this->board->getCellAt(currRow,currCol)->flip();
            }
        }
    }
    //check down-right direction
    currRow = r + 1, currCol = c + 1;
    counter=0;
    if (this->board->isValidCell(currRow,currCol)&& this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
        while (this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==other) {
            counter++;
            currRow++;
            currCol++;
        }
        if(this->board->isValidCell(currRow, currCol) && this->board->getCellAt(currRow,currCol)->getCellValue()==symbol){
            for (int i = 0; i <counter ; ++i) {
                currRow--;
                currCol--;
                this->board->getCellAt(currRow,currCol)->flip();
            }
        }
    }

}




