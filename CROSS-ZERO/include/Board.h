#ifndef HW02_BOARD_H_INCLUDED
#define HW02_BOARD_H_INCLUDED


#include <iostream>
#include "Board.h"

enum class Player {
	O, X
};

enum class State {
	gameIsRunning,
	draw,
	X_wins,
	O_wins
};


class Board {
public:
	char _field[10][10];
	
	Board();

	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;

	bool noEmptyField();

	/** Проверить ход на корректность, если бы он был следующим. */
	bool canMove(int x, int y);

	/** Сделать ход. UB, если он некорректен. */
	void move(int x, int y, Player player);

	/** Состояние игры: игра идёт, игра кончилась с одним из результатов: ничья, победа одной из сторон. */
	State getState();
	
	// Можно добавлять методы при необходимости.
};


#endif