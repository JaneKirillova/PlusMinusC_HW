#include <iostream>
#include <cctype>
#include <string>
#include <stdlib.h>
#include "StdioBoardView.h"

StdioBoardView::StdioBoardView(Board& board) : _board(board) {}

void StdioBoardView::showBoard() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << _board._field[i][j];
		}
		std::cout << "\n";
	}
}

bool StdioBoardView::checkInput() {
	x = -2; y = -2;
	int minusCounter = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '-')
			minusCounter++;
		if (!isdigit(input[i]) && input[i] != '-' && input[i] != ' ')
			return false;
		if (minusCounter > 2)
			return false;
	}
	for (int i = 0; i < input.length() - 1; i++) {
		if (input[i] == '0')
			if(input[i+1] == ' ') {
				if (x == -2) x = 0;
			else if (y == -2) y = 0;
			else return false;
			}
			else 
				continue;

		else if (input[i] == '-') {
			if (input[i+1] == '1') {
				i++;
				if (x == -2) x = -1;
				else if (y == -2) y = -1;
				else return false;
			}
			else
				return false;
		}
		else if (isdigit(input[i]) && input[i+1] == ' ') {
			if (x == -2) x = atoi(&input[i]);
			else if (y == -2) y = atoi(&input[i]);
			else return false;
		}
		else if (isdigit(input[i]) && isdigit(input[i+1]))
			return false;

	}
	if (isdigit(input[input.length() - 1]))
		if (y == -2)
			y = atoi(&input[input.length()-1]);
		else
			return false;
	return true;
}

void StdioBoardView::runGame() {
	std::cout <<"\n";
	showBoard();
	std::cout << "O move: ";

	int moveNumber = -1;
	while (std::getline(std::cin, input)) {
		checkInput();
		if(x == -1 && y == -1)
			return;

		Player player;
		char cur_player;
		moveNumber++;
		if (moveNumber % 2 == 0) {
			player = Player::O;
			cur_player = 'O';
		}
		else {
			player = Player::X;
			cur_player = 'X';
		}
		if (_board.canMove(x, y) && checkInput()) {
			_board.move(x, y, player);
			State state = _board.getState();
			std::cout << "\n";
			showBoard();

			switch(state) {
			case State::draw:
				std::cout << "Draw.\n";
				return;
			case State::X_wins:
				std::cout << "X wins!\n";
				return;
			case State::O_wins:
				std::cout << "O wins!\n";
				return;
			case State::gameIsRunning:
				if (moveNumber % 2 == 0)
					std::cout << "X move: ";
				else
					std::cout << "O move: ";
				break;
			}
		}

		else{
			std::cout << "Bad move!\n";
			moveNumber--;
			std::cout << cur_player << " move: ";

		} 

	}

}

void StdioBoardView::runSilentGame() {
	std::cout << "\nO move: ";

	int moveNumber = -1;

	while(std::getline(std::cin, input)){
		checkInput();
		if(x == -1 && y == -1)
			return;

		Player player;
		char cur_player;
		moveNumber++;
		if (moveNumber % 2 == 0) {
			player = Player::O;
			cur_player = 'O';
		}
		else {
			player = Player::X;
			cur_player = 'X';
		}
		if (_board.canMove(x, y)) {
				_board.move(x, y, player);


			State state = _board.getState();

			switch(state) {
			case State::draw:
				std::cout << "\n";
				showBoard();
				std::cout << "Draw\n";
				return;
			case State::X_wins:
				std::cout << "\n";
				showBoard();
				std::cout << "X wins!\n";
				return;
			case State::O_wins:
				std::cout << "\n";
				showBoard();
				std::cout << "\n";
				std::cout << "O wins!\n";
				return;
			case State::gameIsRunning:
				if (moveNumber % 2 == 0)
					std::cout << "X move: ";
				else
					std::cout << "O move: ";
				break;
			}
		}

		else{
			std::cout << "Bad move!\n";
			moveNumber--;
			std::cout << cur_player << " move: ";

		} 

	}

}