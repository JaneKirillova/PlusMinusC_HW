#include <iostream>
#include <fstream>
#include "Huffman.h"
#include "HuffmanArchiver.h"
#include "CLI.h"

int main(int argc, char** argv) {
	std::string file_in;
	std::string file_out;
	char option;
	try {
		CLI cli(argc, argv);
		option = cli.getOption();
		file_in = cli.getFile_in();
		file_out = cli.getFile_out();
		std::ifstream fin(file_in);
		std::ofstream fout;
		fout.open(file_out);
		HuffmanArchiver ha;
		if (option == 'c')
			ha.compress(fin, fout);
		else
			ha.extract(fin, fout);
	} catch(InputException& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}