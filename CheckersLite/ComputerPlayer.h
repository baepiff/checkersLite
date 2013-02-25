#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#pragma once
#include "IPlayer.h"
#include "CheckersUtil.h"

class ComputerPlayer : public IPlayer
{
public:
	ComputerPlayer(IView* view);
	ComputerPlayer(void);
	~ComputerPlayer(void);
	bool play();
private:
	uint random(uint max);
	void performKillAfterKill(uint afterKillNotaionNum);
};

#endif