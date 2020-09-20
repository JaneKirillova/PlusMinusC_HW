#ifndef HW03_CLI_H_INCLUDED
#define HW03_CLI_H_INCLUDED

#include <iostream>
#include <vector>

class InputException : public std::exception {
public:
	InputException(const char* what);
	const char* what() const noexcept override;
private:
	const char* _what;
};


class CLI {
private:
	int argc_;
	char** argv_;
	std::vector<std::string> inp;
	
public:
	CLI(int argc, char** argv);
	char getOption();
	std::string getFile_in();
	std::string getFile_out();
};

#endif