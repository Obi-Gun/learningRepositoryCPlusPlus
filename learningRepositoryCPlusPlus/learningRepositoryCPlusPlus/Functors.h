#ifndef Functors
#define Functors

class minValueObi
{
private:
	int _memory;
	bool _isFirstIteration = true;
	int minVal(int a, int b) { return a < b ? a : b; }

public:
	void operator() (int value) {
		if (_isFirstIteration) {
			_memory = value;
			_isFirstIteration = false;
			return;
		}
		_memory = minVal(_memory, value);
	}
	int operator() () {
		return _memory;
	}
};

class maxValueObi
{
private:
	int _memory;
	bool _isFirstIteration = true;

public:
	void operator() (int value) {
		if (_isFirstIteration) {
			_memory = value;
			_isFirstIteration = false;
			return;
		}
		_memory = _memory > value ? _memory : value;
	}
	int operator() () {
		return _memory;
	}
};


#endif // !Functors