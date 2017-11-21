//
// hadar sabag id 312497126
//

#include "HumanPlayer.h"

BoardCell*  HumanPlayer::playOneTurn(vector<BoardCell *> & possibleMoves) {
    int row, col, index;
    bool isValid = false;
    cout << this->getSymbol() << ": its your move." << endl;
    cout << "your possible moves:";
    for (int i = 0; i < possibleMoves.size(); ++i) {
        cout << " (" << possibleMoves[i]->getCellRow() << "," << possibleMoves[i]->getCellCol() << ")";
    }
    cout<<"\nenter your move: row space col "<<endl;
    while (!isValid) {
        cin >> row >> col;
        cin.clear();
        cin.ignore(100,'\n');
        for (int i = 0; i < possibleMoves.size(); ++i) {
            if (row == possibleMoves[i]->getCellRow() && col == possibleMoves[i]->getCellCol()) {
                isValid = true;
                index = i;
            }
        }
        if (!isValid) {
            cout << "invalid move. try again" << endl;
        }
    }

    return possibleMoves[index];
}

HumanPlayer::HumanPlayer(char symbol) : Player(symbol) {}
