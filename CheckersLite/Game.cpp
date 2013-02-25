#include "stdafx.h"
#include "Game.h"


Game::Game(void) {
	this->currentPlayerColor = PIECE_COLOR::BLACK;
	this->ended = false;
	this->view = ViewFactory::createView(VIEW_TYPE::CONSOLE_VIEW);
	this->io = IOFactory::createIO(IO_TYPE::CONSOLE_IO);
	this->blackPlayer = PlayerFactory::createPlayer(PLAYER_TYPE::COMPUTER, this->view);
	this->whitePlayer = PlayerFactory::createPlayer(PLAYER_TYPE::HUMAN, this->view);
}


Game::~Game(void) {
	delete this->view;
	delete this->io;
	delete this->blackPlayer;
	delete this->whitePlayer;
}

void Game::start() {
	view->draw();
	startGame();
}

void Game::startGame() {
	int count = 0;
	while(ended == false) {
		IPlayer* player = currentPlayerColor == PIECE_COLOR::WHITE ? whitePlayer : blackPlayer;
		bool result = player->play();
		if (!result) break;
		currentPlayerColor = currentPlayerColor == PIECE_COLOR::WHITE ? PIECE_COLOR::BLACK : PIECE_COLOR::WHITE;
		if (gameFinished()) ended = true;
	}
	printResult();
	system("pause");
}

bool Game::gameFinished() {
	if (Board::getInstance()->getBlackCount() == 0 ||
		Board::getInstance()->getBlackCount() == 0 ) {
		return true;
	}
	return false;
}

void Game::end() {
	ended = true;
}

void Game::printResult() {
	uint blackNum = Board::getInstance()->getBlackCount();
	uint whiteNum = Board::getInstance()->getWhiteCount();
	ostringstream message;
	message << "BLACK : " << blackNum << " WHITE : "  << whiteNum << "\n";
	if (blackNum > whiteNum) message << "BLACK PLAYER WIN!!!\n";
	else if (blackNum < whiteNum) message << "WHITE PLAYER WIN!!!\n";
	else message << "THE GAME IS DRAW!!!\n";
	io->showMessage(message.str());
}