#include "stdafx.h"
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(IView* view) {
	this->color = PIECE_COLOR::BLACK;
	this->view = view;
}


ComputerPlayer::~ComputerPlayer(void) {
	delete this->view;
}

bool ComputerPlayer::play() {
	while(true) {
		vector<Square*> list = CheckersUtil::getKillPieces(PIECE_COLOR::BLACK);
		if (list.size() == 0) {
			//move piece
			list = CheckersUtil::getMovablePieces(PIECE_COLOR::BLACK);
			if (list.size() == 0) {
				view->draw();
				return false;
			} else {
				Square* from = list[random(list.size())];
				list = CheckersUtil::getEmptySquares(from);
				if (list.size() == 0) {
					view->draw();
					return false;
				}
				Board::getInstance()->movePiece(from->getNotationNum(), list[random(list.size())]->getNotationNum());
				view->draw();
				return true;
			}
		} else {
			//kill WHITE piece
			Square* from = list[random(list.size())];
			list = CheckersUtil::getKillTargetPieces(from);
			uint afterKill = Board::getInstance()->killPiece(from->getNotationNum(), list[random(list.size())]->getNotationNum());
			view->draw();
			performKillAfterKill(afterKill);
			return true;
		}
	}
}

uint ComputerPlayer::random(uint max) {
	return rand() % (int)max;
}

void ComputerPlayer::performKillAfterKill(uint afterKillNotationNum) {
	map<uint, Square*> notationMap = Board::getInstance()->getNotationMap();
	if (notationMap.find(afterKillNotationNum) != notationMap.end()) {
		vector<Square*> list = CheckersUtil::getKillTargetPieces(notationMap.find(afterKillNotationNum)->second);
		if (list.size() > 0 ) {
			uint newAfterKillNotationNum = Board::getInstance()->killPiece(afterKillNotationNum, list[random(list.size())]->getNotationNum());
			view->draw();
			performKillAfterKill(newAfterKillNotationNum);
		}
	}
}