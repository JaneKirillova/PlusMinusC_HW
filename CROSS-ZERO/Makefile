CFLAGS = -g -Iinclude 

all: hw_02 test_hw_02

hw_02: obj obj/main.out obj/Board.out obj/StdioBoardView.out 
	g++ -o  hw_02 obj/main.out obj/Board.out obj/StdioBoardView.out

test_hw_02: obj obj/test.out obj/BoardTest.out obj/Board.out obj/Test.out
	g++ -o  test_hw_02 obj/test.out obj/BoardTest.out obj/Board.out obj/Test.out

obj:
	mkdir -p obj

obj/main.out: src/main.cpp include/Board.h include/StdioBoardView.h| obj
	g++ -c -o obj/main.out $(CFLAGS) src/main.cpp

obj/Board.out: src/Board.cpp include/Board.h | obj
	g++ -c -o obj/Board.out $(CFLAGS) src/Board.cpp

obj/StdioBoardView.out: src/StdioBoardView.cpp include/StdioBoardView.h include/Board.h | obj
	g++ -c -o  obj/StdioBoardView.out $(CFLAGS) src/StdioBoardView.cpp 

obj/test.out: test/test.cpp include/BoardTest.h include/Board.h include/Test.h| obj
	g++ -c -o obj/test.out $(CFLAGS) test/test.cpp

obj/Test.out: test/Test.cpp include/Test.h| obj
	g++ -c -o obj/Test.out $(CFLAGS) test/Test.cpp

obj/BoardTest.out: test/BoardTest.cpp include/BoardTest.h include/Board.h include/Test.h| obj
	g++ -c -o obj/BoardTest.out $(CFLAGS) test/BoardTest.cpp

clean:
	rm  -rf hw_02 obj test_hw_02
