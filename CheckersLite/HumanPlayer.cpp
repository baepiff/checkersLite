#include "stdafx.h"
#include "HumanPlayer.h"

using std::ostringstream;

HumanPlayer::HumanPlayer(IView* view) {
	this->color = PIECE_COLOR::WHITE;
	this->io = IOFactory::createIO(IO_TYPE::CONSOLE_IO);
	this->view = view;
}

HumanPlayer::~HumanPlayer(void) {
	delete this->io;
	delete this->view;
}

bool HumanPlayer::play() {
	while(true) {
		vector<Square*> list = CheckersUtil::getKillPieces(PIECE_COLOR::WHITE);
		if (list.size() == 0) {
			//move piece
			list = CheckersUtil::getMovablePieces(PIECE_COLOR::WHITE);
			if (list.size() == 0) {
				view->draw();
				return false;
			} else {
				//choose a piece to move
				printSelectMessage(list, "Select a notation number of the piece that you want to move : ");
				uint from = io->selectNotation();
				if (!checkSelection(from, list)) {
					continue;
				}

				//choose a target square
				map<uint, Square*> notationMap = Board::getInstance()->getNotationMap();
				list = CheckersUtil::getEmptySquares(notationMap.find(from)->second);
				if (list.size() == 0) {
					view->draw();
					return false;
				}
				printSelectMessage(list, "Select a notation number of empty square : ");
				uint to = io->selectNotation();
				if (!checkSelection(to, list)) {
					continue;
				}

				Board::getInstance()->movePiece(from, to);
				view->draw();
				return true;
			}
		} else {
			//choose a piece to move
			printSelectMessage(list, "Select a notation number of the piece to kill : ");
			uint from = io->selectNotation();
			if (!checkSelection(from, list)) {
				continue;
			}
			//choose a target piece
			map<uint, Square*> notationMap = Board::getInstance()->getNotationMap();
			list = CheckersUtil::getKillTargetPieces(notationMap.find(from)->second);
			printSelectMessage(list, "Select a notation number of the target piece : ");
			uint to = io->selectNotation();
			if (!checkSelection(to, list)) {
				continue;
			}
			uint afterKill = Board::getInstance()->killPiece(from, to);
			view->draw();
			performKillAfterKill(afterKill);
			return true;
		}
	}
}

bool HumanPlayer::checkSelection(uint notationNum, vector<Square*> list) {
	for (vector<Square*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
		if (notationNum == (*itr)->getNotationNum()) return true;
	}
	io->showMessage("Please select a notation number in the list.\n");
	return false;
}

void HumanPlayer::printSelectMessage(vector<Square*> list, const string& msg) {
	ostringstream message;
	message << msg;
	for (vector<Square*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
		message << (*itr)->getNotationNum() << ", ";
	}
	message << "\n";
	io->showMessage(message.str());
}

void HumanPlayer::performKillAfterKill(uint afterKillNotationNum) {
	map<uint, Square*> notationMap = Board::getInstance()->getNotationMap();
	if (notationMap.find(afterKillNotationNum) != notationMap.end()) {
		vector<Square*> list = CheckersUtil::getKillTargetPieces(notationMap.find(afterKillNotationNum)->second);
		if (list.size() > 0 ) {
			printSelectMessage(list, "Select a notation number of the target piece : ");
			uint to = io->selectNotation();
			if (checkSelection(to, list)) {
				uint newAfterKillNotationNum = Board::getInstance()->killPiece(afterKillNotationNum, to);
				view->draw();
				performKillAfterKill(newAfterKillNotationNum);
			} else {
				view->draw();
				performKillAfterKill(afterKillNotationNum);
			}
		}
	}
}