//
// hadar sabag id 312497126
//


#include "BoardCell.h"

BoardCell::BoardCell(int row,int col):row(row),col(col){
    this->cellValue=' ';
}
BoardCell::~BoardCell() {}

char BoardCell::getCellValue() const {
    return this->cellValue;
}
bool BoardCell::isEmpty() const {
    return this->cellValue==' ';

}

void BoardCell::updateCellValue(char symbol) {
    this->cellValue=symbol;
}
void BoardCell::flip() {

    if (!isEmpty()) {
        if (this->getCellValue() == 'X') {
            this->cellValue = 'O';
        } else {
            this->cellValue = 'X';
        }
    }
}

int BoardCell::getCellCol() {
    return this->col;
}
int BoardCell::getCellRow(){
    return this->row;
}

bool BoardCell::operator==( BoardCell &otherCell)  {
    return (getCellCol()==otherCell.getCellCol() && getCellRow()==otherCell.getCellRow());
}
