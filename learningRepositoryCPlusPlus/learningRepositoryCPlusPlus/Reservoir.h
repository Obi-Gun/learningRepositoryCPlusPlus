#ifndef ReservoirClass
#define ReservoirClass

#include "String_obi.h";
#include "funcs.h" // added for use enum reservoirType type_;

class Reservoir
{
private:
	String_obi name_;
	int length_;
	int width_;
	int depth_;
	enum reservoirType type_;
	
public:
	Reservoir();
	Reservoir(String_obi name);
	Reservoir(const char* name);
	Reservoir(int length, int width, int depth);
	Reservoir(String_obi name, int length, int width, int depth, reservoirType type);
	Reservoir(const char* name, int length, int width, int depth, reservoirType type);
	Reservoir(Reservoir& reservoir);
	~Reservoir();

	void setName(String_obi name);
	void setName(const char* name);
	void setLength(int length);
	void setWidth(int width);
	void setDepth(int depth);
	void setReservoirType(reservoirType type);

	String_obi getName() const;
	int getLength() const;
	int getWidth() const;
	int getDepth() const;
	String_obi getReservoirType() const;

	void print() const;
	int calcVolume() const;
	int calcAreaOfWaterSurface() const;
	bool isEqualsReservoirTypes(const Reservoir& reservoir) const;
	int compareReservoirAreaOfWaterSurface(const Reservoir& reservoir) const;
	Reservoir operator= (const Reservoir& input);
};
#endif // !ReservoirClass