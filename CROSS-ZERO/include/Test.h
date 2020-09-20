#ifndef HW02_TEST_H_INCLUDED
#define HW02_TEST_H_INCLUDED


#include <sstream>
#include <cstdio>
#include "BoardTest.h"
#include "Board.h"

class Test {
protected:
	static int failedNum; // количество тестов, которые сломались
	static int totalNum;  // общее количество тестов

	/** Проверяет условие (expr) на верность в конце теста.
		В одном тесте может быть не более одного `check`.
		Сообщает об результате пользователю, в случае неудачи подробно сообщает об источнике. */
	static void check(bool expr, const char *func, const char  *filename, size_t lineNum); 

public:
	Test() {};
	/** Вызывается один раз в конце автотестов, выводит общую статистику по
		пройденным тестам на экран. Возвращает `true` если и только если
		все тесты успешно пройдены. */
	static bool showFinalResult();
	
	/** Запускает все тесты в конкретном наборе тестов */
	virtual void runAllTests() = 0; 
};


#endif