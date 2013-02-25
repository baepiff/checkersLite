#ifndef ENUM_H
#define ENUM_H

enum GAME_STATUS {
	NOT_ENDED = 0,
	WHITE_WIN = 1,
	BLACK_WIN = 2,
	DRAW = 3
};

enum PIECE_COLOR {
	BLACK = 0,
	WHITE = 1
};

enum SQUAREVIEW {
	EMPTY = '.',
	BLACK_PLAYER = 'X',
	WHITE_PLAYER = 'O'
};

#endif