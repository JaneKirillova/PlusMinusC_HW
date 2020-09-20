#include <iostream>
#include "BoardTest.h"
#include "Test.h"

int main() {
	BoardTest bt;
	bt.runAllTests();
	if (Test::showFinalResult())
		return 0;
	else
		return 1;
}