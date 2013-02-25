#include "stdafx.h"
#include "CheckersUtil.h"


CheckersUtil::CheckersUtil(void)
{
}


CheckersUtil::~CheckersUtil(void)
{
}

vector<Square*> CheckersUtil::getMovablePieces(enum PIECE_COLOR color) {
	vector<Square*> list;
	map<uint, Square*> notationMap = Board::getInstance()->getNotationMap();
	for (map<uint, Square*>::iterator itr = notationMap.begin(); itr != notationMap.end(); itr++) {
		Square* square = itr->second;
		if (square->getPiece() != NULL && square->getPiece()->getColor() == color) {
			addMovablePiece(square, &list, color);
		}
	}
	return list;
}

vector<Square*> CheckersUtil::getKillPieces(enum PIECE_COLOR color) {
	vector<Square*> list;
	map<uint, Square*> notationMap = Board::getInstance()->getNotationMap();
	for (map<uint, Square*>::iterator itr = notationMap.begin(); itr != notationMap.end(); itr++) {
		Square* square = itr->second;
		if (square->getPiece() != NULL && square->getPiece()->getColor() == color) {
			addKillPiece(square, &list, color);
		}
	}
	return list;
}

vector<Square*> CheckersUtil::getKillTargetPieces(Square* from) {
	vector<Square*> list;
	addKillTargetPieces(from, &list, from->getPiece()->getColor());
	return list;
}

void CheckersUtil::addKillTargetPieces(Square* from, vector<Square*>* list, enum PIECE_COLOR color) {
	vector<vector<Square*>> board = Board::getInstance()->getAllSquare();
	Square* to;
	uint row = from->getPosition()->getRow();
	uint column = from->getPosition()->getColumn();
	if (color == PIECE_COLOR::BLACK) {
		addKillTargetPiece(row + 1, column + 1, from, list);
		addKillTargetPiece(row + 1, column - 1, from, list);
	} else {
		addKillTargetPiece(row - 1, column + 1, from, list);
		addKillTargetPiece(row - 1, column - 1, from, list);
	}
}

bool CheckersUtil::addKillTargetPiece(int row, int column, Square* from, vector<Square*>* list) {
	if (isInRange(row, column)) {
		Square* to = Board::getInstance()->getAllSquare()[row][column];
		if (canKill(from, to)) {
			list->push_back(to);
			return true;
		}
	}
	return false;
}

vector<Square*> CheckersUtil::getEmptySquares(Square* from) {
	vector<Square*> list;
	addEmptySquares(from, &list, from->getPiece()->getColor());
	return list;
}

void CheckersUtil::addEmptySquares(Square* from, vector<Square*>* list, enum PIECE_COLOR color) {
	vector<vector<Square*>> board = Board::getInstance()->getAllSquare();
	Square* to;
	uint row = from->getPosition()->getRow();
	uint column = from->getPosition()->getColumn();
	if (color == PIECE_COLOR::BLACK) {
		addEmptySquare(row + 1, column + 1, list);
		addEmptySquare(row + 1, column - 1, list);
	} else {
		addEmptySquare(row - 1, column + 1, list);
		addEmptySquare(row - 1, column - 1, list);
	}
}

bool CheckersUtil::addEmptySquare(int row, int column, vector<Square*>* list) {
	if (isInRange(row, column)) {
		Square* to = Board::getInstance()->getAllSquare()[row][column];
		if (!to->getPiece()) {
			list->push_back(to);
			return true;
		}
	}
	return false;
}

bool CheckersUtil::canKill(Square* from, Square* to) {
	uint max = Board::BOARD_SIZE - 1;
	Piece* piece = from->getPiece();
	Piece* targetPiece = to->getPiece();
	if (piece == NULL || targetPiece == NULL) {
		return false;
	}
	if (piece->getColor() == targetPiece->getColor()) {
		return false;
	}

	int columnMovement = to->getPosition()->getColumn() - from->getPosition()->getColumn();
	int rowMovement = to->getPosition()->getRow() - from->getPosition()->getRow();
	uint jumpColumn = columnMovement + (columnMovement > 0 ? 1 : -1) + from->getPosition()->getColumn();
	uint jumpRow = rowMovement + (rowMovement > 0 ? 1 : -1) + from->getPosition()->getRow();
	if (jumpColumn > max || jumpRow > max) {
		return false;
	}

	return !Board::getInstance()->getAllSquare()[jumpRow][jumpColumn]->getPiece();
}

void CheckersUtil::addKillPiece(Square* from, vector<Square*>* list, enum PIECE_COLOR color) {
	uint row = from->getPosition()->getRow();
	uint column = from->getPosition()->getColumn();
	if (color == PIECE_COLOR::BLACK) {
		bool added = addKillPiece(row + 1, column + 1, from, list);
		if (added) return;
		addKillPiece(row + 1, column - 1, from, list);
	} else {
		bool added = addKillPiece(row - 1, column + 1, from, list);
		if (added) return;
		addKillPiece(row - 1, column - 1, from, list);
	}
}

bool CheckersUtil::addKillPiece(int row, int column, Square* from, vector<Square*>* list) {
	if (isInRange(row, column)) {
		Square* to = Board::getInstance()->getAllSquare()[row][column];
		if (canKill(from, to)) {
			list->push_back(from);
			return true;
		}
	}
	return false;
}

void CheckersUtil::addMovablePiece(Square* from, vector<Square*>* list, enum PIECE_COLOR color) {
	vector<vector<Square*>> board = Board::getInstance()->getAllSquare();
	Square* to;
	uint row = from->getPosition()->getRow();
	uint column = from->getPosition()->getColumn();
	if (color == PIECE_COLOR::BLACK) {
		bool added = addMovablePiece(row + 1, column + 1, from, list);
		if (added) return;
		addMovablePiece(row + 1, column - 1, from, list);
	} else {
		bool added = addMovablePiece(row - 1, column + 1, from, list);
		if (added) return;
		addMovablePiece(row - 1, column - 1, from, list);
	}
}

bool CheckersUtil::addMovablePiece(int row, int column, Square* from, vector<Square*>* list) {
	if (isInRange(row, column)) {
		Square* to = Board::getInstance()->getAllSquare()[row][column];
		if (!to->getPiece()) {
			list->push_back(from);
			return true;
		}
	}
	return false;
}

bool CheckersUtil::isInRange(int row, int column) {
	if (row < 0 || row > (Board::BOARD_SIZE - 1)) return false;
	if (column < 0 || column > (Board::BOARD_SIZE - 1)) return false;
	return true;
}
