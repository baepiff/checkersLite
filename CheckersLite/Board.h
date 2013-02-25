#ifndef BOARD_H
#define BOARD_H

#pragma once
#include <vector>
#include "Type.h"
#include <string>
#include "Square.h"
#include <map>
#include "Enum.h"

using std::vector;
using std::map;
using std::pair;

class Board
{
private:
	static Board* boardInstance;
	vector<vector<Square*>> board;
	map<uint, Square*> notationMap;
	uint whiteCount;
	uint blackCount;
	static const uint BLACK_LIMIT_LINE = 2;
	static const uint WHITE_LIMIT_LINE = 5;
	static const uint INIT_PIECE_COUNT = 12;

public:
	static const uint BOARD_SIZE = 8;
	static const uint NOT_NOTATION_NUM = 0;
	~Board(void);
	static Board* getInstance();
	uint getWhiteCount();
	uint getBlackCount();
	vector<vector<Square*>> getAllSquare();
	void movePiece(uint from, uint to);
	uint killPiece(uint from, uint to);
	bool removePiece(uint position);
	bool setPiece(uint position, Piece* piece);
	map<uint, Square*> getNotationMap();
private:
	Board(void);
	void init();
};

#endif