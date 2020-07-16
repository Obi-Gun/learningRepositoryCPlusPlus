#ifndef NoteClass
#define NoteClass

class Note
{
private:
	int _counter;
	char* _name;
	//int _id;
	int* _arr;
	int _arrLen;
	//char** _arrCh;

public:
	Note();
	Note(const char* name, int* arr, int arrLen);
	~Note();

	void print();
	void saveToFile();
	void readFromFile();
	void appendObj();
};
#endif