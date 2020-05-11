#include <iostream>
#include "Human.h"
#include "Flat.h"
#include "House.h"
#include "Reservoir.h"
#include "Arr_Reservoir.h"
#include "String_obi.h"
#include "Arr_int.h"

using namespace std;


int main() {
// Homework 2.1. Course: "OOP in C++".
	/*// Create new flat;
	int len = 3;
	Human** arr = new Human * [len];
	arr[0] = new Human("Boris");
	arr[1] = new Human("Lilith");
	arr[2] = new Human("Oleg");
	String_obi str("Gagarins");
	Flat flat(str, 10, 40, arr, len);
	flat.print();


	// Change all fields
	Flat flat2 = flat;
	int len2 = 2;
	Human** arr2 = new Human * [len];
	arr2[0] = new Human("Goga");
	arr2[1] = new Human("Ellen");
	flat2.setTenants(arr2, len2);
	flat2.setFamilySurname("Polimer");
	flat2.setFlatNumber(25);
	flat2.setFloorNumber(7);
	flat2.print();


	// Create new house
	int arrLen = 10;
	Flat** flats = new Flat*[arrLen];
	for (int i = 0; i < arrLen; ++i) {
		flats[i] = new Flat(i + 1);
	}
	int floorsInHouse = 1;
	String_obi adress = "Rostov, Lenina 1";
	House house(flats, arrLen, floorsInHouse, adress);
	house.print();


	// Change all fields
	House house2 = house;
	int arrLen2 = 5;
	Flat** flats2 = new Flat * [arrLen2];
	flats2[0] = &flat;
	flats2[1] = &flat2;
	for (int i = 2; i < arrLen2; ++i) {
		flats2[i] = new Flat(i + 1);
	}
	int floorsInHouse2 = 10;
	String_obi adress2 = "Rostov, Lenina 2";
	house2.setAdress(adress2);
	house2.setFloorsInHouse(floorsInHouse2);
	house2.setFlats(flats2, arrLen2);
	house2.print();*/
	
// Homework 2.2. Course: "OOP in C++".
	String_obi str("Black");
	Reservoir reservoir1(str, 1, 2, 3, sea);
	//reservoir1.print();

	Reservoir reservoir2 = reservoir1;
	//cout << "is equals reservoirs " << reservoir2.isEqualsReservoirTypes(reservoir1) << endl;
	//cout << "compare reservoirs " << reservoir2.compareReservoirAreaOfWaterSurface(reservoir1) << endl;
	reservoir2.setName("Pacific");
	reservoir2.setLength(10);
	reservoir2.setWidth(10);
	reservoir2.setDepth(10);
	reservoir2.setReservoirType(ocean);
	//reservoir2.print();
	//cout << "is equals " << reservoir2.isEqualsReservoirTypes(reservoir1) << endl;
	//cout << "compare reservoirs " << reservoir2.compareReservoirAreaOfWaterSurface(reservoir1) << endl;

	Reservoir reservoir3;
	//reservoir3.print();
	reservoir3 = reservoir1;
	//reservoir3.print();

	// class Arr_Reservoir
	int length = 2;
	Reservoir** arr = new Reservoir*[length];
	arr[0] = &reservoir1;
	arr[1] = &reservoir2;

	Arr_Reservoir testArr1(arr, length);
	//testArr1.print();

	Arr_Reservoir testArr2 = testArr1;
	testArr2.print();

	testArr2.menu();

// Homework 2.3. Course: "OOP in C++".
	/*String_obi string1("Hello");
	String_obi string2 = "Helga";
	String_obi string3;
	string3 = string1 * string2;
	string3 = string3 + " " + string2 + " " + string1;
	string3 = string3 + string3;
	string3.print();*/

// Classwork overrife operator [] 1. Course: "OOP in C++".
	/*Arr_int arr(5);
	arr[0] = 88;
	arr[1] = 77;
	arr[2] = 66;
	arr[3] = 55;
	arr[4] = 44;

	Arr_int arr2;
	arr2 = arr;
	++arr2;
	cout << arr2;*/
}