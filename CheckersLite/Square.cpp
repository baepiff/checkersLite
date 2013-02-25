#include "stdafx.h"
#include "Square.h"

Square::~Square(void)
{
	delete this->position;
	delete this->piece;
}

Square::Square(const uint notationNum, const Position* position, Piece* piece) {
	this->notationNum = notationNum;
	this->position = position;
	this->piece = piece;
	setSquareView();
}

SQUAREVIEW Square::getSquareView() {
	return squareView;
}

uint Square::getNotationNum() {
	return notationNum;
}

void Square::setPiece(Piece* piece) {
	this->piece = piece;
	setSquareView();
}

Piece* Square::getPiece() {
	return this->piece;
}

void Square::removePiece() {
	this->piece = NULL;
	setSquareView();
}

void Square::setSquareView() {
	if (!piece) {
		squareView = SQUAREVIEW::EMPTY;
	} else {
		switch (piece->getColor()) {
			case PIECE_COLOR::BLACK:
				squareView = SQUAREVIEW::BLACK_PLAYER;
				break;
			case PIECE_COLOR::WHITE:
				squareView = SQUAREVIEW::WHITE_PLAYER;
				break;
		default:
			;
		}
	}
}

const Position* Square::getPosition() {
	return position;
}