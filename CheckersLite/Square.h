#ifndef SQUARE_H
#define SQUARE_H

#pragma once
#include "Position.h"
#include "Piece.h"

class Square
{
private:
	SQUAREVIEW squareView;
	uint notationNum;
	const Position* position;
	Piece* piece;
public:
	~Square(void);
	Square(const uint notationNum, const Position* position, Piece* piece);
	SQUAREVIEW getSquareView();
	uint getNotationNum();
	void setPiece(Piece* piece);
	Piece* getPiece();
	void removePiece();
	bool enablePut();
	const Position* getPosition();
private:
	void setSquareView();
};

#endif
