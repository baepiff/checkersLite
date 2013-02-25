#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#pragma once
#include "ComputerPlayer.h"
#include "HumanPlayer.h"

class PlayerFactory
{
public:
	PlayerFactory(void);
	~PlayerFactory(void);
	static IPlayer* createPlayer(enum PLAYER_TYPE type, IView* view);
};

enum PLAYER_TYPE {
	HUMAN,
	COMPUTER
};
#endif