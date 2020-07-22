#ifndef ComplexNum_Guard
#define ComplexNum_Guard

class ComplexNum
{
private:
	double _a;
	double _b;
	//char sigh = '+';
	const char i = 'i';
	static int _objCounter;

public:
	ComplexNum();
	ComplexNum(double a, double b);
	ComplexNum(ComplexNum& obj);
	~ComplexNum();

	ComplexNum operator+ (const ComplexNum obj);
	ComplexNum operator- (const ComplexNum obj);
	ComplexNum operator* (const ComplexNum obj);
	ComplexNum operator/ (const ComplexNum obj);
	void operator= (const ComplexNum obj);

	void print();

	static int getObjCounter();
	void incrementObjCounter();
	void decrementObjCounter();
};
#endif