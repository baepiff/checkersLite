#ifndef CHECKERS_UTIL_H
#define CHECKERS_UTIL_H

#pragma once
#include <vector>
#include "Board.h"

using std::vector;

class CheckersUtil
{
public:
	CheckersUtil(void);
	~CheckersUtil(void);
	static vector<Square*> getMovablePieces(enum PIECE_COLOR color);
	static vector<Square*> getKillPieces(enum PIECE_COLOR color);
	static vector<Square*> getKillTargetPieces(Square* from);
	static vector<Square*> getEmptySquares(Square* from);
private:
	static bool canKill(Square* from, Square* to);
	static void addKillPiece(Square* from, vector<Square*>* list, enum PIECE_COLOR color);
	static bool addKillPiece(int row, int column, Square* from, vector<Square*>* list);
	static void addMovablePiece(Square* from, vector<Square*>* list, enum PIECE_COLOR color);
	static bool addMovablePiece(int row, int column, Square* from, vector<Square*>* list);
	static void addKillTargetPieces(Square* from, vector<Square*>* list, enum PIECE_COLOR color);
	static bool addKillTargetPiece(int row, int column, Square* from, vector<Square*>* list);
	static void addEmptySquares(Square* from, vector<Square*>* list, enum PIECE_COLOR color);
	static bool addEmptySquare(int row, int column, vector<Square*>* list);
	static bool isInRange(int row, int column);
};

#endif