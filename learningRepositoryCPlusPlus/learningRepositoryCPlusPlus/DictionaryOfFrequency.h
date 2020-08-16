#ifndef DictionaryOfFrequency_Class
#define DictionaryOfFrequency_Class
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

class DictionaryOfFrequency
{
private:
	map<string, int> _dictionary;

	friend std::ostream& operator << (std::ostream& out, DictionaryOfFrequency& obj);
public:
	DictionaryOfFrequency();
	~DictionaryOfFrequency();

	void readFile(const char* specialWordsFilePath);
	void writeFile();	

	void showWordFrequency();
	void showTheMostCommonWord();
};

std::ostream& operator << (std::ostream& out, DictionaryOfFrequency& obj);
#endif