#include "stdafx.h"
#include "PlayerFactory.h"


PlayerFactory::PlayerFactory(void)
{
}


PlayerFactory::~PlayerFactory(void)
{
}

IPlayer* PlayerFactory::createPlayer(enum PLAYER_TYPE type, IView* view) {
	IPlayer* player;
	switch (type) {
	case PLAYER_TYPE::COMPUTER:
		player = new ComputerPlayer(view);
		break;
	case PLAYER_TYPE::HUMAN:
		player = new HumanPlayer(view);
		break;
	default:
		player = new ComputerPlayer(view);
		break;
	}
	return player;
}
