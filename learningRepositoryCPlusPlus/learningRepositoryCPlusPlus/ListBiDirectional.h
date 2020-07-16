#ifndef ListBiDirectionalClass
#define ListBiDirectionalClass

template <class T>
struct elementBD
{
	const T* str_;
	elementBD<T>* prev_, *next_;

	elementBD(elementBD<T>* previous, T* field, elementBD<T>* next);
};

template <class T>
class ListBiDirectional
{
private:
	elementBD<T>* phead_;
	elementBD<T>* ptail_;
	int counter_;

public:
	ListBiDirectional();
	ListBiDirectional(T* str);
	~ListBiDirectional();

	void print() const;
	void print(int index) const;
	void printReverse() const;

	void addHead(T* str);
	void addTail(T* str);
	void insert(T* str, int index);

	//void removeEl(int index);
	void deleteAllElements();

	int getCount() const;
	elementBD<T>* getEl(int index);
};
#endif 