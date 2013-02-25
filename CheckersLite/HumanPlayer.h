#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#pragma once
#include "IPlayer.h"
#include "IOFactory.h"
#include "CheckersUtil.h"
#include <sstream>

class HumanPlayer : public IPlayer
{
private:
	IIO* io;
public:
	HumanPlayer(IView* view);
	~HumanPlayer(void);
	bool play();
private:
	bool checkSelection(uint notationNum, vector<Square*> list);
	void printSelectMessage(vector<Square*> list, const string& msg);
	void performKillAfterKill(uint afterKillNotaionNum);
};

#endif