#include "stdafx.h"
#include "Position.h"


Position::Position(const uint row, const uint column) {
	this->row = row;
	this->column = column;
}


Position::~Position(void)
{
}

uint Position::getRow() const {
	return row;
}

uint Position::getColumn() const {
	return column;
}