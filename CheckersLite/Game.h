#ifndef GAME_H
#define GAME_H

#pragma once
#include "Board.h"
#include "ViewFactory.h"
#include "IOFactory.h"
#include "PlayerFactory.h"
#include "Type.h"
#include <sstream>

using std::ostringstream;

class Game
{
private:
	PIECE_COLOR currentPlayerColor;
	bool ended;
	IView* view;
	IIO* io;
	IPlayer* whitePlayer;
	IPlayer* blackPlayer;
public:
	Game(void);
	~Game(void);
	void start();
	void end();
private:
	void startGame();
	bool gameFinished();
	void printResult();
};

#endif