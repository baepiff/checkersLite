#include "stdafx.h"
#include "Board.h"

Board* Board::boardInstance = NULL;

Board::Board(void) {
	this->blackCount = INIT_PIECE_COUNT;
	this->whiteCount = INIT_PIECE_COUNT;
	for (uint row = 0; row < BOARD_SIZE; row++) {
		board.push_back(vector<Square*>());
		for (uint column = 0; column < BOARD_SIZE; column++) {
			board[row].push_back(NULL);
		}
	}
	init();
}


Board::~Board(void) {
	for (uint row = 0; row < BOARD_SIZE; row++) {
		for (uint column = 0; column < BOARD_SIZE; column++) {
			Square* squre = board[row][column];
			if (squre != NULL) {
				delete squre;
			}
		}
	}
}


void Board::init() {
	uint notationNum = 1;
	for (uint row = 0; row < BOARD_SIZE; row++) {
		for (uint column = 0; column < BOARD_SIZE; column++) {
			Position* position = new Position(row, column);
			bool isNotation = (row + column) % 2 == 1 ? true : false;
			Piece* piece = NULL;
			if (row <= BLACK_LIMIT_LINE && isNotation) {
				piece = new Piece(PIECE_COLOR::BLACK);
			} else if (row >= WHITE_LIMIT_LINE && isNotation) {
				piece = new Piece(PIECE_COLOR::WHITE);
			}
			if (isNotation) {
				board[row][column] = new Square(notationNum, position, piece);
				notationMap.insert(pair<uint, Square*>(notationNum, board[row][column]));
				notationNum++;
			} else {
				board[row][column] = new Square(NOT_NOTATION_NUM, position, piece);
			}
		}
	}
}

Board* Board::getInstance() {
	if (boardInstance == NULL) boardInstance = new Board();
	return boardInstance;
}

uint Board::getBlackCount() {
	return this->blackCount;
}
uint Board::getWhiteCount() {
	return this->whiteCount;
}

vector<vector<Square*>> Board::getAllSquare() {
	return this->board;
}

void Board::movePiece(uint from, uint to) {
	if (notationMap.find(from) == notationMap.end() ||
		notationMap.find(to) == notationMap.end()) {
		return;
	}
	Piece* tempPiece = notationMap.find(from)->second->getPiece();
	notationMap.find(from)->second->removePiece();
	setPiece(to, tempPiece);
}

uint Board::killPiece(uint from, uint to) {
	if (notationMap.find(from) == notationMap.end() ||
		notationMap.find(to) == notationMap.end()) {
		return 0;
	}
	//cacluate position after jump
	Square* fromSquare = notationMap.find(from)->second;
	Square* toSquare = notationMap.find(to)->second;
	int rowDifference = toSquare->getPosition()->getRow() - fromSquare->getPosition()->getRow();
	int columnDifference = toSquare->getPosition()->getColumn() - fromSquare->getPosition()->getColumn();
	uint goalPosition = board[toSquare->getPosition()->getRow() + rowDifference][toSquare->getPosition()->getColumn() + columnDifference]->getNotationNum();

	Piece* tempPiece = fromSquare->getPiece();
	notationMap.find(from)->second->removePiece();
	removePiece(to);
	setPiece(goalPosition, tempPiece);
	return goalPosition;
}

bool Board::setPiece(uint position, Piece* piece) {
	if (notationMap.find(position) == notationMap.end()) {
		return false;
	}
	notationMap.find(position)->second->setPiece(piece);
	return true;
}
bool Board::removePiece(uint position) {
	if (notationMap.find(position) == notationMap.end()) {
		return false;
	}
	Square* square = notationMap.find(position)->second;
	if (PIECE_COLOR::BLACK == square->getPiece()->getColor()) blackCount--;
	else whiteCount--;
	square->removePiece();
	return true;
}

map<uint, Square*> Board::getNotationMap() {
	return notationMap;
}