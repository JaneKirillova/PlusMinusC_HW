#include <iostream>
#include "Board.h"

Board::Board() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			_field[i][j] = '.';
		}
	}
}

bool Board::canMove(int x, int y) {
	bool rightX = 0 <= x && x < 10;
	bool rightY = 0 <= y && y < 10;
	if (!rightX or !rightY)
		return false;
	if (_field[x][y] != '.')
		return false;
	if (noEmptyField())
		return false;
	else
		return true;
}

bool Board::noEmptyField() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (_field[i][j] == '.')
				return false;
		}
	}
	return true;
}

void Board::move(int x, int y, Player player) {
	if (canMove(x, y)) {
		if (player == Player::X)
			_field[x][y] = 'X';
		if (player == Player::O)
			_field[x][y] = 'O';
	}
}

State Board::getState() {
	int counterX = 0;
	int counterO = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (_field[i][j] == 'X')
				counterX++;
			else
				counterX = 0;

			if (_field[i][j] =='O')
				counterO++;
			else 
				counterO = 0;

			if (counterX == 5)
				return State::X_wins;

			if (counterO == 5)
				return State::O_wins;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (_field[j][i] == 'X')
				counterX++;
			else
				counterX = 0;

			if (_field[j][i] =='O')
				counterO++;
			else 
				counterO = 0;	

			if (counterX == 5)
				return State::X_wins;

			if (counterO == 5)
				return State::O_wins;
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (_field[i][j] == 'X'
				&& _field[i + 1][j + 1] == 'X'
				&& _field[i + 2][j + 2] == 'X'
				&& _field[i + 3][j + 3] == 'X'
				&& _field[i + 4][j + 4] == 'X')
					return State::X_wins;

			if (_field[i][j] == 'O'
				&& _field[i + 1][j + 1] == 'O'
				&& _field[i + 2][j + 2] == 'O'
				&& _field[i + 3][j + 3] == 'O'
				&& _field[i + 4][j + 4] == 'O')
					return State::O_wins; 
		}
	}

	for (int i = 4; i < 10; i++) {
		for (int j = 0; j < 6; j++) {
			if (_field[i][j] == 'X'
				&& _field[i - 1][j + 1] == 'X'
				&& _field[i - 2][j + 2] == 'X'
				&& _field[i - 3][j + 3] == 'X'
				&& _field[i - 4][j + 4] == 'X')
					return State::X_wins;

			if (_field[i][j] == 'O'
				&& _field[i - 1][j + 1] == 'O'
				&& _field[i - 2][j + 2] == 'O'
				&& _field[i - 3][j + 3] == 'O'
				&& _field[i - 4][j + 4] == 'O')
					return State::O_wins; 
		}
	}

	if (noEmptyField())
		return State::draw;
	else
		return State::gameIsRunning;
}