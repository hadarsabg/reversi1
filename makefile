a.out: Board.o BoardCell.o Game.o ConsoleGameLogic.o Player.o HumanPlayer.o main.o
	g++ Board.o BoardCell.o Game.o ConsoleGameLogic.o Player.o HumanPlayer.o main.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

BoardCell.o: BoardCell.cpp BoardCell.h
	g++ -c BoardCell.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

ConsoleGameLogic.o: ConsoleGameLogic.cpp ConsoleGameLogic.h
	g++ -c ConsoleGameLogic.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

HUmanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	g++ -c HumanPlayer.cpp

main.o: main.cpp
	g++ -c main.cpp
