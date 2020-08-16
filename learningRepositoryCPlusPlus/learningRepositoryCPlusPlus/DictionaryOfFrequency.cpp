#include "DictionaryOfFrequency.h"

DictionaryOfFrequency::DictionaryOfFrequency()
{
}

DictionaryOfFrequency::~DictionaryOfFrequency()
{
}

void DictionaryOfFrequency::readFile(const char* specialWordsFilePath)
{
	FILE* sWFile;
	if (fopen_s(&sWFile, specialWordsFilePath, "r")) {
		cout << "Unable to open file";
		return;
	}
	const int maxStringSize = 1600;
	char str[maxStringSize];
	while (fgets(str, maxStringSize, sWFile)) {
		char* context;
		char* wordArr = strtok_s(str, " ,.?!;:\"\'`()-_*", &context);
		string wordString = wordArr;
		transform(wordString.begin(), wordString.end(), wordString.begin(), [](unsigned char c) { return std::tolower(c); });
		//if (wordString.) add split by ôöæùÆ
		pair<string, int> tmp3(wordString, 1);
		auto tmp2 = _dictionary.insert(tmp3);
		if (!tmp2.second) {
			auto tmp4 = _dictionary.find(wordString);
			tmp4->second++;
		}
		while (wordArr = strtok_s(NULL, " ,.?!;:\"\'`()-_*", &context)) {
			wordString = wordArr;
			transform(wordString.begin(), wordString.end(), wordString.begin(), [](unsigned char c) { return std::tolower(c); });
			//if (wordString.)
			pair<string, int> tmp3(wordString, 1);
			tmp2 = _dictionary.insert(tmp3);
			if (!tmp2.second) {
				auto tmp4 = _dictionary.find(wordString);
				tmp4->second++;
			}
		}
	}
	if (fclose(sWFile)) {
		cout << "Unable to close file";
		return;
	}
}

std::ostream& operator<<(std::ostream& out, DictionaryOfFrequency& obj)
{
	for (auto i = obj._dictionary.begin(); i != obj._dictionary.end(); ++i) {
		printf("%20s %i\n", i->first.c_str(), i->second);
	}
	return out;
}
