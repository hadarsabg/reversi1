//
// hadar Sabag id 312497126
//

#include "Game.h"


Game::Game(int playerChoice):playerChoice(playerChoice),board(new Board(8)),gameLogic(new ConsoleGameLogic(this->board)){
    this->blackPlayer = new HumanPlayer('X');
    if(this->playerChoice==1) {
        this->whitePlayer = new HumanPlayer('O');
    }
    if(this->playerChoice==2){
        this->whitePlayer = new AiPlayer('O');
    }
};
Game::~Game() {
    delete board;
    delete blackPlayer;
    delete whitePlayer;
    delete gameLogic;
}
void Game::run() {
    vector<BoardCell*> blackMoves =this->gameLogic->getPossibleMoves(blackPlayer);
    vector <BoardCell*> whiteMoves=this->gameLogic->getPossibleMoves(whitePlayer);


    while (!(whiteMoves.empty() && blackMoves.empty())) {

        blackMoves = this->gameLogic->getPossibleMoves(blackPlayer);
        if (!blackMoves.empty()) {
            cout << *board << endl;
            this->gameLogic->swapCells(this->blackPlayer->playOneTurn(blackMoves), blackPlayer->getSymbol());

        } else {
            if (whiteMoves.empty()) {
                break;
            }
            else {
                cout << "no possible moves for " << blackPlayer->getSymbol() << endl;
            }

        }

        whiteMoves = this->gameLogic->getPossibleMoves(whitePlayer);
        if (!whiteMoves.empty()) {
            cout << *board << endl;
            this->gameLogic->swapCells(this->whitePlayer->playOneTurn(whiteMoves), whitePlayer->getSymbol());
        } else {
            if (blackMoves.empty()) {
                break;
            }
            else {
                cout << "no possible moves for " << whitePlayer->getSymbol() << endl;
            }
        }
        if (blackMoves.empty() && whiteMoves.empty()) {
                break;
            }
    }
    cout<<*board<<endl;
}

void Game::endingStatus() const {

    int blackCounter = 0;
    int whiteCounter = 0;
    for (int i = 0; i < this->board->getSize(); ++i) {
        for (int j = 0; j < this->board->getSize(); ++j) {
            if (this->board->getCellAt(i, j)->getCellValue() == blackPlayer->getSymbol()) {
                blackCounter++;
            }
            if (this->board->getCellAt(i, j)->getCellValue() == whitePlayer->getSymbol()) {
                whiteCounter++;
            }
        }
    }
    if (blackCounter > whiteCounter) {
        cout << blackPlayer->getSymbol() << " you are the winner!" << endl;
    }
    if (whiteCounter > blackCounter) {
        cout << whitePlayer->getSymbol() << " you are the winner!" << endl;
    }
    if(whiteCounter==blackCounter){
        cout << "it's a tie!" << endl;
    }
}
