#ifndef String_SmartPointerClass
#define String_SmartPointerClass

#include "String_obi.h"

class String_SmartPointer
{
private:
	String_obi* p_;
	int counterCopies_;

public:
	String_SmartPointer(String_obi* pointer = nullptr);
	String_SmartPointer(String_SmartPointer& obj);
	~String_SmartPointer();
	
	operator String_obi* ();
	String_obi* operator-> ();
	String_SmartPointer operator++ ();
	String_SmartPointer operator++ (int);
	String_SmartPointer operator= (const String_SmartPointer& obj);

};
#endif // !String_SmartPointerClass