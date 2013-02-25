#include "stdafx.h"
#include "Piece.h"


Piece::~Piece(void)
{
}

Piece::Piece(PIECE_COLOR color) {
	this->color = color;
}

PIECE_COLOR Piece::getColor() {
	return color;
}