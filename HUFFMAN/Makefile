CFLAGS = -g -Iinclude

all: hw_03 test_hw_03

hw_03: obj obj/main.out obj/Huffman.out obj/HuffmanArchiver.out obj/CLI.out
	g++ -o  hw_03 obj/main.out obj/Huffman.out obj/HuffmanArchiver.out obj/CLI.out

test_hw_03: obj obj/TestMain.out obj/TestHuffman.out obj/TestHuffmanArchiver.out
	g++ -o  test_hw_03 obj/TestMain.out obj/TestHuffman.out obj/TestHuffmanArchiver.out obj/Huffman.out obj/HuffmanArchiver.out

obj:
	mkdir -p obj

obj/main.out: src/main.cpp include/Huffman.h include/HuffmanArchiver.h include/CLI.h | obj
	g++ -c -o obj/main.out $(CFLAGS) src/main.cpp

obj/Huffman.out: src/Huffman.cpp include/Huffman.h | obj
	g++ -c -o obj/Huffman.out $(CFLAGS) src/Huffman.cpp

obj/HuffmanArchiver.out: src/HuffmanArchiver.cpp include/HuffmanArchiver.h include/Huffman.h | obj
	g++ -c -o  obj/HuffmanArchiver.out $(CFLAGS) src/HuffmanArchiver.cpp

obj/CLI.out: src/CLI.cpp include/CLI.h | obj
	g++ -c -o obj/CLI.out $(CFLAGS) src/CLI.cpp


obj/TestMain.out: test/TestMain.cpp test/TestHuffman.h | obj
	g++ -c -o obj/TestMain.out $(CFLAGS) test/TestMain.cpp

obj/TestHuffmanArchiver.out: test/TestHuffmanArchiver.cpp test/TestHuffmanArchiver.h include/HuffmanArchiver.h include/Huffman.h | obj
	g++ -c -o obj/TestHuffmanArchiver.out $(CFLAGS) test/TestHuffmanArchiver.cpp

obj/TestHuffman.out: test/TestHuffman.cpp test/TestHuffman.h include/HuffmanArchiver.h include/Huffman.h | obj
	g++ -c -o obj/TestHuffman.out $(CFLAGS) test/TestHuffman.cpp

clean:
	rm  -rf hw_03 obj test_hw_03
