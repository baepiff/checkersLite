#include "stdafx.h"
#include "ConsoleView.h"

using std::cout;
using std::endl;
using std::vector;


ConsoleView::ConsoleView(void)
{
}


ConsoleView::~ConsoleView(void)
{
}

void ConsoleView::draw() {
	clear();
	vector<vector<Square*>> board = Board::getInstance()->getAllSquare();
	for (vector<Square*> row : board) {
		for (Square* square : row) {
			cout << (char)square->getSquareView();
			if (square->getNotationNum() > Board::NOT_NOTATION_NUM) cout << square->getNotationNum();
		}
		cout << endl;
	}
}

void ConsoleView::clear() {
	system("cls");
}