#ifndef DictionaryOfFrequency_Class
#define DictionaryOfFrequency_Class
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
#include <fcntl.h>
#include <io.h>

using namespace std;

class DictionaryOfFrequency
{
private:
	map<string, int> _dictionary;
	int _wordsCounter;
	const char* _DELIMETERS = " ,.?!;:\"\'/=<>`()-_*0123456789";

	int getWordsCounter() const;
	void setWordsCounter(int);
	void incrementWordsCounter();
	void strToLowerCase(string& str);
	void addToDictionary(string str);
	void splitFileToStrAndFillDictionary(FILE*& file);
	void splitStrToWordsAndFillDictionary(char* str);
	friend std::ostream& operator << (std::ostream& out, DictionaryOfFrequency& obj);

public:
	DictionaryOfFrequency();
	~DictionaryOfFrequency();

	void readFileAndFillDictionary(const char* specialWordsFilePath);
	void writeFile();	

	void showWordFrequency();
	void showTheMostCommonWord();
};

std::ostream& operator << (std::ostream& out, DictionaryOfFrequency& obj);
#endif