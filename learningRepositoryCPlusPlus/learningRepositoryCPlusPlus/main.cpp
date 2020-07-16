#include <iostream>
#include "Time_obi.h"
#include "funcs.h"


using namespace std;
Time_obi* Time_obi::pointer_ = new Time_obi(666, 666, 666);

union Task1Union {
	int fieldInt;
	char fieldChar[5];
	
	void showInBinary() {
		int i, n;
		if (this->fieldInt > 16777215) {
			n = 31;
		}
		else if (this->fieldInt > 65535) {
			n = 23;
		}
		else if (this->fieldInt > 255) {
			n = 15;
		}
		else {
			n = 7;
		}
		for (int i = n; i >= 0; --i) {
			cout << ((this->fieldInt >> i) & 1);
				if (i % 8 == 0) {
					cout << " ";
				}
		}
	}

	void showInHex() {
		int i, n, tmp = 0, counter = 3;
		this->fieldInt > 16777215 ? n = 31 : 
			this->fieldInt > 65535 ? n = 23 :
				this->fieldInt > 255 ? n = 15 : n = 7;

		for (i = n; i >= 0; --i) {
			tmp += ((this->fieldInt >> i) & 1) * mathPow(2, counter--);
			if (counter < 0) {
				counter = 3;
				switch (tmp) {
				case 15:
					cout << 'F';
					break;
				case 14:
					cout << 'E';
					break;
				case 13:
					cout << 'D';
					break;
				case 12:
					cout << 'C';
					break;
				case 11:
					cout << 'B';
					break;
				case 10:
					cout << 'A';
					break;
				default:
					cout << tmp;
					break;
				}
				tmp = 0;
			}
			if (i % 8 == 0) {
				cout << " ";
			}
		}
	}
};

union task2Union {
	int varSigned;
	unsigned int varUnsigned;
};

union task3Union {
	int varInt;
	bool varBool[5];

	void setInt() {
		cout << "Enter the number, please: ";
		cin >> this->varInt;
	}

	bool isZeroByte(int numberOfByte) {
		for (int i = 7 + 8 * numberOfByte; i >= 8 * numberOfByte; --i) {
			if ((this->varInt >> i) & 1) {
				return false;
			}
		}
		return true;
	}

	int calcZeroBytes() {
		const int BYTES = 4;
		int nonZeroBytes = 0;
		for (int i = 3; i >= 0; --i) {
			if (!isZeroByte(i)) {
				++nonZeroBytes;
			}
		}
		return BYTES - nonZeroBytes;
	}

	void showInfoAboutBytes() {
		for (int i = 3; i >= 0; --i) {
			if (!isZeroByte(i)) {
				cout << "Nonzero byte, ";
			}
			else {
				cout << "Zero byte, ";
			}
		}
	}
};

int main() {
// Hometask 17.1. Course: "C++ Basics".
	Task1Union test1;
	test1.fieldInt = 100000;
	cout << "         int: " << test1.fieldInt << endl;

	cout << "showInBinary: ";
	test1.showInBinary();
	cout << endl;

	cout << "   showInHex: ";
	test1.showInHex();
	cout << endl;

	test1.fieldChar[4] = '\0';
	cout << "       chars: " << test1.fieldChar << endl;

// Hometask 17.2. Course: "C++ Basics".
	task2Union test2;
	test2.varSigned = -1;
	cout << test2.varSigned;
	cout << endl;
	cout << test2.varUnsigned;
	
// Hometask 17.3. Course: "C++ Basics".
	task3Union test3;
	test3.varInt = 65536;
	cout << "There are " << test3.calcZeroBytes() << " zero bytes is the variable\n";
	cout << "There is an information about bytes: ";
	test3.showInfoAboutBytes();
}