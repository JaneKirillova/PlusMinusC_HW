#include <sstream>
#include <cstdio>
#include "BoardTest.h"

void BoardTest::testMove1() {
	bool rightBoard;
	Board b;
	b.move(4, 5, Player::X);
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if (i == 4 && j == 5)
				rightBoard = b._field[i][j] == 'X';
			else
				rightBoard = b._field[i][j] == '.';
		}
	}
	DO_CHECK(rightBoard);
}

void BoardTest::testMove2() {
	bool rightBoard;
	Board b;
	b.move(8, 1, Player::O);
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if (i == 8 && j == 1)
				rightBoard = b._field[i][j] == 'O';
			else
				rightBoard = b._field[i][j] == '.';
		}
	}
	DO_CHECK(rightBoard);
}

void BoardTest::testMove3() {
	Board b;
	b.move(5, 5, Player::O);
	b.move(1, 2, Player::X);
	b.move(5, 5, Player::X);
	b.move(1, 2, Player::O);
	DO_CHECK(b._field[5][5] == 'O');
	DO_CHECK(b._field[1][2] == 'X');

}

void BoardTest::testCanMove1() {
	Board b;
	bool rightCanMove;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			rightCanMove = b.canMove(i, j);
		}
	}
	DO_CHECK(rightCanMove);
	DO_CHECK(!b.canMove(-2, -5));
	DO_CHECK(!b.canMove(10, 13));
}

void BoardTest::testCanMove2() {
	Board b;
	b.move(0, 0, Player::X);
	DO_CHECK(!b.canMove(0, 0));
}
	
void BoardTest::testCanMove3() {
	Board b;
	b.move(0, 0, Player::X);
	DO_CHECK(!b.canMove(0, 0));
	DO_CHECK(b.canMove(1, 1));
}

void BoardTest::testNoEmptyField1() {
	Board b;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			b.move(i, j, Player::X);
		}
	}
	DO_CHECK(b.noEmptyField());
}

void BoardTest::testNoEmptyField2() {
	Board b;
	b.move(0, 0, Player::O);
	b.move(0, 1, Player::X);
	b.move(1, 0, Player::O);
	b.move(4, 5, Player::X);
	b.move(5, 5, Player::O);
	DO_CHECK(!b.noEmptyField());
}

void BoardTest::testNoEmptyField3() {
	Board b;
	for (int i = 0; i < 10; i++) {
		b.move(0, i, Player::X);
		b.move(9, i, Player::O);
		b.move(i, 0, Player::X);
		b.move(i, 9, Player::O);
	}
	DO_CHECK(!b.noEmptyField());
}

void BoardTest::testXWin1() {
	Board b;
	b.move(0, 0, Player::X);
	b.move(0, 1, Player::X);
	b.move(0, 2, Player::X);
	b.move(0, 3, Player::X);
	b.move(0, 4, Player::X);
	DO_CHECK(b.getState() == State::X_wins);
}

void BoardTest::testXWin2() {
	Board b;
	b.move(2, 4, Player::X);
	b.move(3, 5, Player::X);
	b.move(4, 6, Player::X);
	b.move(5, 7, Player::X);
	b.move(6, 8, Player::X);
	DO_CHECK(b.getState() == State::X_wins);
}

void BoardTest::testOWin1() {
	Board b;
	b.move(0, 0, Player::O);
	b.move(0, 1, Player::O);
	b.move(0, 2, Player::O);
	b.move(0, 3, Player::O);
	b.move(0, 4, Player::O);
	DO_CHECK(b.getState() == State::O_wins);
}

void BoardTest::testOWin2() {
	Board b;
	b.move(7, 5, Player::O);
	b.move(6, 6, Player::O);
	b.move(5, 7, Player::O);
	b.move(4, 8, Player::O);
	b.move(3, 9, Player::O);
	DO_CHECK(b.getState() == State::O_wins);
}

void BoardTest::testStateRunningGame() {
	Board b;
	b.move(0, 0, Player::O);
	b.move(9, 9, Player::X);
	b.move(4, 5, Player::O);
	b.move(2, 8, Player::X);
	DO_CHECK(b.getState() == State::gameIsRunning);
}


void BoardTest::testDraw1() {
	Board b;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i % 2 == 1) {
				if (j % 4 == 0 || j % 4 == 1)
					b.move(i, j, Player::O);
				else
					b.move(i, j, Player::X);
			}
			else {
				if (j % 4 == 0 || j % 4 == 1)
					b.move(i, j, Player::X);
				else
					b.move(i, j, Player::O);
			}
		}
	}
	DO_CHECK(b.getState() == State::draw);
}


void BoardTest::testDraw2() {
	Board b;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j % 2 == 1) {
				if (i % 4 == 0 || i % 4 == 1)
					b.move(i, j, Player::O);
				else
					b.move(i, j, Player::X);
			}
			else {
				if (i % 4 == 0 || i % 4 == 1)
					b.move(i, j, Player::X);
				else
					b.move(i, j, Player::O);
			}
		}
	}
	DO_CHECK(b.getState() == State::draw);
}


void BoardTest::runAllTests() {
	testMove1();
	testMove2();
	testMove3();
	testCanMove1();
	testCanMove2();
	testCanMove3();
	testNoEmptyField1();
	testNoEmptyField2();
	testNoEmptyField3();
	testXWin1();
	testXWin2();
	testOWin1();
	testOWin2();
	testStateRunningGame();
	testDraw1();
	testDraw2();
}