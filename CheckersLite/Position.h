#ifndef POSITION_H
#define POSITION_H

#pragma once
#include "Type.h"

class Position
{
private:
	uint row;
	uint column;
public:
	~Position(void);
	Position(const uint row, const uint column);
	uint getRow() const;
	uint getColumn() const;
};

#endif