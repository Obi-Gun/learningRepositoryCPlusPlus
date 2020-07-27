#include "CalcStr.h"

bool CalcStr::isOpenBracket(string str)
{
	if ((int)str.find('(') != -1) {
		return true;
	}
	return false;
}

bool CalcStr::isSum(string str)
{
	if ((int)str.find('+') != -1) {
		return true;
	}
	return false;
}

bool CalcStr::isSub(string str)
{
	if ((int)str.find('-') != -1) {
		return true;
	}
	return false;
}

bool CalcStr::isMult(string str)
{
	if ((int)str.find('*') != -1) {
		return true;
	}
	return false;
}

bool CalcStr::isDiv(string str)
{
	if ((int)str.find('/') != -1) {
		return true;
	}
	return false;
}

string CalcStr::unbracked(string str)
{
	if (isOpenBracket(str)) {
		int l = str.find('(');
		int r = str.rfind(')');
		string tmp = str.substr(l + 1, r - l - 1);
		return unbracked(tmp);
	}

	return str;
}
