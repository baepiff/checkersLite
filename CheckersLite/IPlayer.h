#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "IIO.h"
#include "Position.h"
#include <vector>
#include <map>
#include "Enum.h"
#include "IView.h"

using std::map;
using std::vector;

class IPlayer
{
protected:
	PIECE_COLOR color;
	IView* view;
public:
	virtual ~IPlayer(void) {};
	virtual bool play() = 0;
};

#endif
