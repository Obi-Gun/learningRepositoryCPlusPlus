#ifndef DictionaryOfFrequency_Class
#define DictionaryOfFrequency_Class
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

class DictionaryOfFrequency
{
private:
	map<string, int> _dictionary;
	int _wordsCounter;
	const char* _DELIMETERS = " ,.?!;:\"\'/=<>`()-_*0123456789";
	ostringstream _strDictionary;
	string _mostCommonWord;
	int _mostCommonWordCounter;

	int getWordsCounter() const;
	void setWordsCounter(int);
	void incrementWordsCounter();
	void strToLowerCase(string& str);
	void addToDictionary(string str);
	void splitFileToStrAndFillDictionary(FILE*& file);
	void splitStrToWordsAndFillDictionary(char* str);
	friend std::ostream& operator << (std::ostream& out, DictionaryOfFrequency& obj);
	void findTheMostCommonWord();

public:
	DictionaryOfFrequency();
	~DictionaryOfFrequency();

	void readFileAndFillDictionary(const char* filePath);
	void writeFile(const char* filePath);
	string getMostCommonWord() const;
	int getMostCommonWordCounter() const;
};

std::ostream& operator << (std::ostream& out, DictionaryOfFrequency& obj);
#endif