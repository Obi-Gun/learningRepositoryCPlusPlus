#ifndef ReservoirClass
#define ReservoirClass

#include "String_obi.h";

class Reservoir
{
private:
	static enum reservoirType { ocean, sea, swimmingPool, pond };
	String_obi name_;
	int length_;
	int width_;
	int depth_;
	reservoirType type_;
	
public:
	Reservoir();
	Reservoir(String_obi name);
	Reservoir(const char* name);
	Reservoir(int length, int width, int depth);
	Reservoir(const char* name, int length, int width, int depth, reservoirType type);
	Reservoir(String_obi name, int length, int width, int depth, reservoirType type);
	Reservoir(Reservoir& reservoir);
	~Reservoir();

	void setName();
	void setLength();
	void setWidth();
	void setDepth();
	void setReservoirType();

	String_obi getName() const;
	int getLength() const;
	int getWidth() const;
	int getDepth() const;
	String_obi getReservoirType() const;

	int calcVolume() const;
	int calcAreaOfWaterSurface() const;
	bool isEqualsReservoirTypes(const Reservoir& reservoir) const;
	int compareReservoirAreaOfWaterSurface(const Reservoir& reservoir) const;
};
#endif // !ReservoirClass