#include "DictionaryOfFrequency.h"

int DictionaryOfFrequency::getWordsCounter() const
{
	return _wordsCounter;
}

void DictionaryOfFrequency::setWordsCounter(int number)
{
	_wordsCounter = number;
}

void DictionaryOfFrequency::incrementWordsCounter()
{
	++_wordsCounter;
}

void DictionaryOfFrequency::strToLowerCase(string& str)
{
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
}

void DictionaryOfFrequency::addToDictionary(string str)
{
	// add check \n
	incrementWordsCounter();
	pair<string, int> tmp3(str, 1);
	auto tmp2 = _dictionary.insert(tmp3);
	if (!tmp2.second) {
		auto tmp4 = _dictionary.find(str);
		tmp4->second++;
	}
}

void DictionaryOfFrequency::splitFileToStrAndFillDictionary(FILE*& file)
{
	const int maxStringSize = 1600;
	char str[maxStringSize];
	while (fgets(str, maxStringSize, file)) {
		splitStrToWordsAndFillDictionary(str);
	}
}

void DictionaryOfFrequency::splitStrToWordsAndFillDictionary(char* str)
{
	char* context;
	char* wordArr = strtok_s(str, _DELIMETERS, &context);
	string wordString = wordArr;
	strToLowerCase(wordString);
	for (auto letter = wordString.begin(); letter != wordString.end(); ++letter) {
		//if (*letter == )
		//wordString.
	}
	addToDictionary(wordString);
	while (wordArr = strtok_s(NULL, _DELIMETERS, &context)) {
		wordString = wordArr;
		strToLowerCase(wordString);
		//if (wordString.) //add split by ôöæùÆ
		addToDictionary(wordString);
	}
}

DictionaryOfFrequency::DictionaryOfFrequency()
{
	setWordsCounter(0);
}

DictionaryOfFrequency::~DictionaryOfFrequency()
{
}

void DictionaryOfFrequency::readFileAndFillDictionary(const char* specialWordsFilePath)
{
	FILE* sWFile;
	if (fopen_s(&sWFile, specialWordsFilePath, "r")) {
		cout << "Unable to open file";
		return;
	}
	splitFileToStrAndFillDictionary(sWFile);
	if (fclose(sWFile)) {
		cout << "Unable to close file";
		return;
	}
}

std::ostream& operator<<(std::ostream& out, DictionaryOfFrequency& obj)
{
	int i = 0;
	for (auto pairStrInt = obj._dictionary.begin(); pairStrInt != obj._dictionary.end(); ++pairStrInt, ++i) {
		printf("%20s %i ", pairStrInt->first.c_str(), pairStrInt->second);
		if (i % 7 == 0) {
			out << endl;
		}
	}
	printf("\n________________________________________________________________________________");
	printf("\n_________________There are %10i words in the text_______________________\n", obj.getWordsCounter());
	return out;
}
