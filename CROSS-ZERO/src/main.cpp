#include <iostream>
#include <string.h>
#include "Board.h"
#include "StdioBoardView.h"

int main(int argc, char *argv[]) {
	Board b;
	StdioBoardView sbv(b);
	if (argc > 1 && strcmp(argv[1],"silent\n"))
		sbv.runSilentGame();
	else
		sbv.runGame();
	return 0;
}