#ifndef Arr_ReservoirClass
#define Arr_ReservoirClass

#include "Reservoir.h"

class Arr_Reservoir
{
private:
	int length_;
	Reservoir** arr_;

	void setLength(int length);

	void reCreateArr(int length);
	void addObj(Reservoir& reservoir);
	void removeObj(int index);

public:
	Arr_Reservoir();
	Arr_Reservoir(Reservoir** arr, int length);
	Arr_Reservoir(Arr_Reservoir& input);
	~Arr_Reservoir();

	int getLength() const;

	void menu();
	void print();
	void addObj();
	void removeObj();

};
#endif // !Arr_ReservoirClass