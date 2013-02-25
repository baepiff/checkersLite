#ifndef PIECE_H
#define PIECE_H

#pragma once
#include "Enum.h"
class Piece
{
private:
	enum PIECE_COLOR color;
public:
	~Piece(void);
	Piece(enum PIECE_COLOR color);
	enum PIECE_COLOR getColor();
};

#endif