#ifndef ListBiDirectionalClass
#define ListBiDirectionalClass

template <class T>
struct elementBD
{
	const T* str_;
	elementBD<T>* prev_, *next_;

	elementBD(elementBD<T>* previous, const char* str, elementBD<T>* next) {
		prev_ = previous;
		str_ = str;
		next_ = next;
	}

	elementBD(elementBD<T>* previous, T* field, elementBD<T>* next) {
		prev_ = previous;
		str_ = field;	
		next_ = next;
	}
};

template <class T>
class ListBiDirectional
{
private:
	elementBD<T>* phead_;
	elementBD<T>* ptail_;
	int counter_;

public:
	ListBiDirectional() 
	{
		phead_ = nullptr;
		ptail_ = nullptr;
		counter_ = 0;
	}

	ListBiDirectional(T* str)
	{
		phead_ = new elementBD<T>(nullptr, str, nullptr);
		ptail_ = phead_;
		counter_ = 1;
	}

	~ListBiDirectional() 
	{
		std::cout << "~ListBiDirectional()\n";
		deleteAllElements();

	}

	void print() const;

	void print(int index) const
	{
		elementBD<T>* tmp;
		if (index < counter_ / 2 - 1) {
			int counter = 1;
			tmp = phead_;
			while (counter - 1 != index) {
				tmp = tmp->next_;
				++counter;
			}
		}
		else {
			int counter = counter_;
			tmp = ptail_;
			while (counter - 1 != index) {
				tmp = tmp->prev_;
				--counter;
			}
		}
		std::cout << std::endl << tmp->str_ << std::endl;
	}

	void printReverse() const
	{
		elementBD<T>* tmp = ptail_;
		while (tmp != nullptr) {
			std::cout << tmp->str_;
			tmp = tmp->prev_;
		}
		std::cout << std::endl;
	}

	void addHead(T* str)
	{
		elementBD<T>* tmp = tmp = new elementBD<T>(nullptr, str, phead_);
		phead_->prev_ = tmp;
		phead_ = tmp;
		++counter_;
	}

	void addTail(T* str)
	{
		elementBD<T>* tmp = new elementBD<T>(ptail_, str, nullptr);
		ptail_->next_ = tmp;
		ptail_ = tmp;
		++counter_;
	}

	void insert(T* str, int index)
	{
		elementBD<T>* tmp = nullptr, * prev = nullptr, * next = nullptr;
		next = getEl(index);
		prev = next->prev_;
		tmp = new elementBD<T>(prev, str, next);
		prev->next_ = tmp;
		next->prev_ = tmp;
		++counter_;
	}

	void removeEl(int index) {

	}

	void deleteAllElements()
	{
		elementBD<T>* tmp = phead_, * next;
		while (tmp != nullptr) {
			next = tmp->next_;
			delete tmp;
			tmp = next;
		}
	}

	int getCount() const
	{
		return counter_;
	}

	elementBD<T>* getEl(int index)
	{
		elementBD<T>* tmp = nullptr;
		if (index + 1 < counter_ / 2) {
			int counter = 1;
			tmp = phead_;
			while (counter != index + 1) {
				tmp = tmp->next_;
				++counter;
			}
		}
		else {
			int counter = counter_;
			tmp = ptail_;
			while (counter != index + 1) {
				tmp = tmp->prev_;
				--counter;
			}
		}
		return tmp;
	}
};
#endif 