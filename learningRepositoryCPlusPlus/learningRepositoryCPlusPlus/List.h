#ifndef ListClass
#define ListClass

struct element
{
	const char* str_;
	element* next_;

	element(const char* str, element* next) {
		this->str_ = str;
		this->next_ = next;
	}
};

class List
{
private:
	element* phead_;
	element* ptail_;

public:
	List();
	List(const char* str);
	//~List();

	void print() const;
	void add(const char* str);
	//void remove();
	//void destroyAllElements();
};
#endif // !List