//
// hadar sabag id 312497126
//

#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    int playerChoice;
    cout <<"enter 1 for human player"<<endl<<"enter 2 for AI player"<<endl;
    cin >> playerChoice;
    Game game(playerChoice);
    game.run();
    game.endingStatus();

}