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
	if (str == "\n") 
		return;
	incrementWordsCounter();
	strToLowerCase(str);
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
	addToDictionary(wordString);
	while (wordArr = strtok_s(NULL, _DELIMETERS, &context)) {
		wordString = wordArr;
		addToDictionary(wordString);
	}
}

void DictionaryOfFrequency::findTheMostCommonWord()
{
	auto max = _dictionary.begin();
	for (auto word = _dictionary.begin(); word != _dictionary.end(); ++word)
	{
		if (word->second > max->second) {
			max = word;
		}
	}
	_mostCommonWord = max->first;
	_mostCommonWordCounter = max->second;
}

DictionaryOfFrequency::DictionaryOfFrequency()
{
	setWordsCounter(0);
}

DictionaryOfFrequency::~DictionaryOfFrequency()
{
}

void DictionaryOfFrequency::readFileAndFillDictionary(const char* filePath)
{
	FILE* sWFile;
	if (fopen_s(&sWFile, filePath, "r")) {
		cout << "Unable to open file";
		return;
	}
	splitFileToStrAndFillDictionary(sWFile);
	if (fclose(sWFile)) {
		cout << "Unable to close file";
		return;
	}
	findTheMostCommonWord();
}

void DictionaryOfFrequency::writeFile(const char* filePath)
{
	FILE* file;
	if (fopen_s(&file, filePath, "w")) {
		cout << "Unable to open file";
		return;
	}
	int newStrCounter = 0;
	_strDictionary << "\n_________________________________________________________________________";
	_strDictionary << "\n_________________There are " << getWordsCounter() << "words in the text_______________________";
	_strDictionary << "\n_________The word \"" << getMostCommonWord() << "\" was met in the text " << getMostCommonWordCounter() << " times_________________";
	_strDictionary << "\n_________________________________________________________________________\n";
	for (auto i = _dictionary.begin(); i != _dictionary.end(); ++i, ++newStrCounter) {
		_strDictionary << i->first << " " << i->second << "    ";
		if (newStrCounter % 7 == 0) {
			_strDictionary << "\n";
		}
	}
	fputs(_strDictionary.str().c_str(), file);
	if (fclose(file)) {
		cout << "Unable to close file";
		return;
	}
}

string DictionaryOfFrequency::getMostCommonWord() const
{
	return _mostCommonWord;
}

int DictionaryOfFrequency::getMostCommonWordCounter() const
{
	return _mostCommonWordCounter;
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
	printf("\n_________________The word %s was met in the text %i times_______________________\n", obj.getMostCommonWord().c_str(), obj.getMostCommonWordCounter());
	printf("\n________________________________________________________________________________");
	return out;
}
