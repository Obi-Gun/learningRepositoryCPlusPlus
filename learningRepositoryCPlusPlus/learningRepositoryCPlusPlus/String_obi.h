#ifndef String_obiClass
#define String_obiClass

class String_obi
{
private:
	char* string_;

public:
	String_obi();
	String_obi(int length);
	String_obi(const char* string);
	String_obi(String_obi& string_obi);
	~String_obi();

	String_obi operator*(const String_obi& string);
	void print() const;
};
#endif