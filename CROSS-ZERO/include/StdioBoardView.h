#ifndef HW02_STDIOBOARDVIEW_H_INCLUDED
#define HW02_STDIOBOARDVIEW_H_INCLUDED

#include <iostream>
#include "Board.h"
#include "StdioBoardView.h"

class StdioBoardView {
private:
	Board& _board;
	int x;
	int y;
	std::string input;

	bool checkInput();

	void showBoard();

public:
	explicit StdioBoardView(Board& board);

	/** Основной цикл игры, от начала до конца. */
	void runGame();

	void runSilentGame();
};

#endif