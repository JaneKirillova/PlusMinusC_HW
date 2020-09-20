#ifndef HW02_BOARDTEST_H_INCLUDED
#define HW02_BOARDTEST_H_INCLUDED


#include <sstream>
#include <cstdio>
#include "BoardTest.h"
#include "Test.h"
#include "Board.h"

#define DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__)

class BoardTest : public Test {
private:
	void testMove1();

	void testMove2();

	void testMove3();

	void testCanMove1();
	
	void testCanMove2();

	void testCanMove3();

	void testNoEmptyField1();

	void testNoEmptyField2();

	void testNoEmptyField3();

	void testOWin1();

	void testXWin1();

	void testOWin2();

	void testXWin2();

	void testStateRunningGame();

	void testDraw1();

	void testDraw2();
	
public:
	void runAllTests() override;
};


#endif