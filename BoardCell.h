//
// hadar sabag id 312497126
//

#ifndef EX2NEW_BOARDCELL_H
#define EX2NEW_BOARDCELL_H



class BoardCell {
public:
    /**
     * constructor
     * @param row
     * @param col
     */
    BoardCell(int row,int col);
    //destructor
    ~BoardCell();
    /**
     * return cell row index
     * @return this.row
     */
    int getCellRow();
    /**
     * return cell col index
     * @return this.col
     */
    int getCellCol();
    /**
     * change the cell symbol from x to o and o so x
     */
    void flip();
    /**
     * change cell value to symbol
     * @param symbol
     */
    void updateCellValue(char symbol);
    /**
     * return cell value
     * @return cell vakue
     */
    char getCellValue() const;
    /**
     * check if cell symbol is ' '
     * @return true if cell holds ' ', else-false
     */
    bool isEmpty() const ;
    // override == operator
    bool operator ==(BoardCell& otherCell)  ;


private:
    int row;
    int col;
    char cellValue;

};


#endif //EX2NEW_BOARDCELL_H
