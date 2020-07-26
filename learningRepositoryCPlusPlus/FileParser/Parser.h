#ifndef Parser_Guardian
#define Parser_Guardian
#include <iostream>

class Parser
{
private:
	static Parser* _ptr;

	char** _buffer;
	int _rows;

	int countStringsInFile(char* filepth);

	void reserveArr(int length, char*& arr);
	void reserveArr(int length, char**& arr);
	void reserveArr(int rows, int columns, char**& arr);

public:
	Parser();
	~Parser();
	static Parser* getReferance();

	void read(const char* sourceFilepath);
	void filterStrWith(const char*);
	void print();
	void write(const char* destFilepath, bool everyElOnNewStr = true);


};
#endif