cmake_minimum_required(VERSION 3.8)
project(untitled1)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Game.h Game.cpp Board.cpp Board.h BoardCell.cpp BoardCell.h GameLogic.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h ConsoleGameLogic.cpp ConsoleGameLogic.h AiPlayer.cpp AiPlayer.h)
add_executable(untitled1 ${SOURCE_FILES})