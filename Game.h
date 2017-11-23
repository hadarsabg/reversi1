//
// hadar sabag id 312497126
//

#ifndef EX2NEW_GAME_H
#define EX2NEW_GAME_H

#include "ConsoleGameLogic.h"
#include "Player.h"
#include "Board.h"
#include "GameLogic.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"

class Game {
public:
    //constructor
    Game(int playerChoice);
    //destructor
    ~Game();
    //run the game loop and prints the board after each turn
    void run();
    //check witch player is the winner
    void endingStatus ()const;

private:
    Player* blackPlayer;
    Player* whitePlayer;
    Board* board;
    GameLogic* gameLogic;
    int playerChoice;

};



#endif //EX2NEW_GAME_H
