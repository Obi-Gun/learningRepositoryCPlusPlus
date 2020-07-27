#ifndef CalcStr_Guardian
#define CalcStr_Guardian
#include <iostream>
#include <string>     // std::string, std::stoi
using namespace std;

class CalcStr
{
public:
	bool isOpenBracket(string str);
	bool isSum(string str);
	bool isSub(string str);
	bool isMult(string str);
	bool isDiv(string str);

	string unbracked(string str);

	/*string separate(string str) {
		string tmp;
		if ((int)isMult(str) != -1 || (int)isDiv(str) != -1) {
			/*int plus = str.find('+');
			int minus = str.find('-');
			int mult = str.find('*');
			int div = str.find('/');
			if (mult < div) {
				tmp = str.substr(0, r - l - 1);
			}
			else {

			}


			int l = str.find('(');
				int r = str.rfind(')');
				string tmp = str.substr(l + 1, r - l - 1);
				return unbracked(tmp);
		}

		return str;
	}*/

	/*string unoperated(string str) {
		bool isSum_ = (int)isSum(str) != -1;
		bool isSub_ = (int)isSub(str) != -1;
		bool isMult_ = (int)isMult(str) != -1;
		bool isDiv_ = (int)isDiv(str) != -1;
		int indFirstMult = isMult_ ? (int)str.find('*') : -1;
		int indFirstDiv = isDiv_ ? (int)str.find('/') : -1;
		if (isMult_ || isDiv_) {
			bool isSum_2 = (int)isSum(str) != -1;
			bool isSub_2 = (int)isSub(str) != -1;
		}
		else if (isSum_ || isSub_) {

		}
		else {

		}

		return str;
	}*/

	string CalculateSumSub(string str)
	{
		bool isSum_ = (int)isSum(str) != -1;
		bool isSub_ = (int)isSub(str) != -1;
		int res = 0;
		int indFirstPlus = (int)str.find('+');
		int indFirstMinus = (int)str.find('-');
		if (isSum_ || isSub_) {

			/*			std::string::size_type sz;
			int i_dec = stoi(str, &sz);*/
			return str;
		}
		return str;

	}

	
};
#endif // !CalcStr_Guardian