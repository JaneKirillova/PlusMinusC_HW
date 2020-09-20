#include "CLI.h"
#include <algorithm>

InputException::InputException(const char* what) : std::exception(), _what(what) {};
const char* InputException::what() const noexcept {
	return _what; 
}


CLI::CLI(int argc, char** argv) : argc_(argc), argv_(argv) {
	if (argc != 6)
		throw InputException("Invalid input format");
	for (int i = 1; i < argc_; i++) {
		inp.push_back(argv_[i]);
	}
}

char CLI::getOption() {
	char option;
	auto find_c = std::find(inp.begin(), inp.end(), "-c");
	auto find_u = std::find(inp.begin(), inp.end(), "-u");
	if (find_c != inp.end() && find_u == inp.end())
		option = 'c';
	else if (find_u != inp.end() && find_c == inp.end())
		option = 'u';
	else
		throw InputException("Invalid input format");
	return option;
}

std::string CLI::getFile_in() {
	std::string file_in;
	auto pos1 = std::find(inp.begin(), inp.end(), "-f");
	auto pos2 = std::find(inp.begin(), inp.end(), "--file");
	if (pos1 != inp.end() && pos2 == inp.end()) {
		if (pos1 + 1 == inp.end())
			throw InputException("Invalid input format");
		file_in = *(pos1 + 1);
	} else if (pos2 != inp.end() && pos1 == inp.end()) {
		if (pos2 + 1 == inp.end())
			throw InputException("Invalid input format");
		file_in = *(pos2 + 1);
	} else {
		throw InputException("Invalid input format");
	}
	return file_in;
}

std::string CLI::getFile_out() {
	std::string file_out;
	auto pos1 = std::find(inp.begin(), inp.end(), "-o");
	auto pos2 = std::find(inp.begin(), inp.end(), "--output");
	if (pos1 != inp.end() && pos2 == inp.end()) {
		if (pos1 + 1 == inp.end())
			throw InputException("Invalid input format");
		file_out = *(pos1 + 1);
	} else if (pos2 != inp.end() && pos1 == inp.end()) {
		if (pos2 + 1 == inp.end())
			throw InputException("Invalid input format");
		file_out = *(pos2 + 1);
	} else {
		throw InputException("Invalid input format");
	}
	return file_out;
}