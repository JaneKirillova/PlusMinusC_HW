#include <sstream>
#include "BoardTest.h"

int Test::failedNum = 0;
int Test::totalNum = 0;

void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
	if (!expr) {
		failedNum++;
		std::cout << "TEST FAILED" << func << "at file: " << filename << ", line: " << lineNum << "\n";
	}
	totalNum++;
}

bool Test::showFinalResult(){
	if (!failedNum) {
		std::cout << "All " << totalNum << " tests have passed!\n";
		return true;
	}
	else {
		std::cout << failedNum << " of " << totalNum << " failed.\n";
		return false;
	}
}