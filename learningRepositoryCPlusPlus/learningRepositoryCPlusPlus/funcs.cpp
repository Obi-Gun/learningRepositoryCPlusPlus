#include "funcs.h"

//   ===================================================
//   |            My own small library                 |
//   |    I`ve tryed to follow this codeStyle          |
//   |      https://habr.com/ru/post/172091/           |
//   ===================================================


bool isEqualsChar(char el, char el2)
{
	return el == el2;
}

int countDigits(char* source)
{
	return countSymbolsInArr1isFromArr2(source, "0123456789");
}

int countLetters(char* source)
{
	return countSymbolsInArr1isFromArr2(source, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

int countWords(char* sourceArr)
{
	int counter = 0;
	char* context;
	char* p = strtok_s(sourceArr, " ", &context);
	if (p != 0) {
		++counter;
	}
	while (p = strtok_s(NULL, " ", &context)) {
		++counter;
	}
	return counter;
}

int countSymbolsInArr1isFromArr2(char* source, const char* symbolsToFind)
{
	char* currentPointer = source;
	int counter = 0;
	while (char* c = strpbrk(currentPointer, symbolsToFind)) {
		++counter;
		currentPointer = c + 1;
	}
	return counter;
}

int strLength(char** arr, int rows)
{
	int minStrLen = strlen(arr[0]);
	for (int i = 1; i < rows; ++i) {
		if (minStrLen > strlen(arr[i])) minStrLen = strlen(arr[i]);
	}
	return minStrLen;
}

void fillRandomValuesToTheArray(int** arr, int lenRow, int lenCol, int minValue, int maxValue)
{
	if (maxValue < minValue) {
		swap(maxValue, minValue);
	}
	for (int i = 0; i < lenRow; ++i) {
		for (int j = 0; j < lenCol; ++j) {
			arr[i][j] = minValue + rand() % (maxValue + 1 - minValue);
		}
	}
}

void fillRandomValuesToTheArray(int** arr, int lenRow, int lenCol)
{
	for (int i = 0; i < lenRow; ++i) {
		for (int j = 0; j < lenCol; ++j) {
			arr[i][j] = rand();
		}
	}
}

void fillRandomValuesToTheArray(double** arr, int lenRow, int lenCol)
{
	for (int i = 0; i < lenRow; ++i) {
		for (int j = 0; j < lenCol; ++j) {
			arr[i][j] = rand();
		}
	}
}

void fillRandomValuesToTheArray(char** arr, int lenRow, int lenCol, char minValue, char maxValue)
{
	if (maxValue < minValue) {
		swap(maxValue, minValue);
	}
	for (int i = 0; i < lenRow; ++i) {
		for (int j = 0; j < lenCol; ++j) {
			arr[i][j] = minValue + rand() % (maxValue + 1 - minValue);
		}
	}
}

int fillRandomValue(int minValue, int maxValue)
{
	srand(time(NULL));
	if (maxValue < minValue) {
		swap(maxValue, minValue);
	}
	return minValue + rand() % (maxValue + 1 - minValue);
}

int fillRandom4DigitValue()
{
	int num = rand() % 10;
	num += rand() % 10 * 10;
	num += rand() % 10 * 100;
	num += 1000 + rand() % 9 * 1000;
	return num;
}

void shakeValuesInArr(int* arr, int length)
{
	int* arr2;
	reserveArr(length, arr2);
	fillRandomValuesToTheArray(arr2, length, 0, length - 1);
	for (int i = 0; i < length; ++i) {
		swap(arr + i, arr + arr2[i]);
	}
	removeArr(arr2);
}

void printArr(int** arr, int rows, int columns, int setMinimumWidth, bool showIndexes)
{
	setMinimumWidth = setMinimumWidth < 0 ? 0 : setMinimumWidth;
	cout << "\nArray values:" << endl;
	for (int i = 0; i < rows; ++i) {
		cout << " ";
		for (int j = 0; j < columns; ++j) {
			if (showIndexes) {
				cout << "   arr[" << i << "][" << j << "]= " << setw(setMinimumWidth) << arr[i][j];
			}
			else {
				cout << setw(setMinimumWidth) << arr[i][j] << "  ";
			}
		}
		cout << endl << endl;
	}
}

void printArr(double** arr, int rows, int columns, int setMinimumWidth, bool showIndexes)
{
	setMinimumWidth = setMinimumWidth < 0 ? 0 : setMinimumWidth;
	cout << "\nArray values:" << endl;
	for (int i = 0; i < rows; ++i) {
		cout << " ";
		for (int j = 0; j < columns; ++j) {
			if (showIndexes) {
				cout << "   arr[" << i << "][" << j << "]= " << setw(setMinimumWidth) << arr[i][j];
			}
			else {
				cout << setw(setMinimumWidth) << arr[i][j] << "  ";
			}
		}
		cout << endl << endl;
	}
}

void printArr(char** arr, int rows, int columns, int setMinimumWidth, bool showIndexes)
{
	setMinimumWidth = setMinimumWidth < 0 ? 0 : setMinimumWidth;
	cout << "\nArray values:" << endl;
	for (int i = 0; i < rows; ++i) {
		cout << " ";
		for (int j = 0; j < columns; ++j) {
			if (showIndexes) {
				cout << "   arr[" << i << "][" << j << "]= " << setw(setMinimumWidth) << arr[i][j];
			}
			else {
				cout << setw(setMinimumWidth) << arr[i][j] << "  ";
			}
		}
		cout << endl << endl;
	}
}

void printArr(char*** arr, int rows, int columns, int strLength, int setMinimumWidth, bool showIndexes)
{
	setMinimumWidth = setMinimumWidth < 0 ? 0 : setMinimumWidth;
	cout << "\nPhonebook:" << endl;
	for (int i = 0; i < columns; ++i) {
		cout << " ";
		for (int j = 0; j < rows; ++j) {
			if (showIndexes) {
				cout << "   arr[" << j << "][" << i << "]= " << setw(setMinimumWidth) << arr[j][i];
			}
			else {
				cout << setw(setMinimumWidth) << arr[j][i] << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void swapArr(char*& pFirst, char*& pSecond)
{
	char* tmp = pFirst;
	pFirst = pSecond;
	pSecond = tmp;
}

void insertionSort(int arr[], int LEN)
{
	for (int i = 0; i < (LEN - 1); ++i) {
		int val = arr[i + 1];
		int ind = i + 1;
		while (ind > 0 && arr[ind] < arr[ind - 1]) {
			swap(arr[ind - 1], arr[ind]);
			ind--;
		}
		arr[ind] = val;
	}
}

void insertionSort(int** arr, int rows, int columns)
{
	for (int i = 0; i < rows; ++i) {
		insertionSort(arr[i], columns);
	}
}

void insertionSort(double arr[], int LEN)
{
	for (int i = 0; i < (LEN - 1); ++i) {
		double val = arr[i + 1];
		int ind = i + 1;
		while (ind > 0 && arr[ind] < arr[ind - 1]) {
			swap(arr[ind - 1], arr[ind]);
			ind--;
		}
		arr[ind] = val;
	}
}

void insertionSort(double** arr, int rows, int columns)
{
	for (int i = 0; i < rows; ++i) {
		insertionSort(arr[i], columns);
	}
}

void insertionSort(char arr[], int LEN)
{
	for (int i = 0; i < (LEN - 1); ++i) {
		char val = arr[i + 1];
		int ind = i + 1;
		while (ind > 0 && arr[ind] < arr[ind - 1]) {
			swap(arr[ind - 1], arr[ind]);
			ind--;
		}
		arr[ind] = val;
	}
}

void insertionSort(char** arr, int rows, int columns)
{
	for (int i = 0; i < rows; ++i) {
		insertionSort(arr[i], columns);
	}
}

void bobbleSort(int arr[], int length)
{
	for (int i = 0; i < length; ++i) {
		for (int j = (length - 1); j > i; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

void sortArr(int* arr, int length, bool isInAscendingOrder)
{
	if (isInAscendingOrder) quickSort(arr, length - 1);
	else quickSortDescendingOrder(arr, length - 1);
}

void bobbleSortStr(char** arr, int rows, int iSL)
{
	for (int i = 0; i < rows; ++i) {
		for (int j = (rows - 1); j > i; --j) {
			if (arr[j][iSL] < arr[j - 1][iSL]) {
				swapArr(arr[j], arr[j - 1]);
			}
		}
	}
}

void sortStr(char** arr, int rows, int iSL)
{ // iSL = index Of Sorted Letter
	if (iSL >= strLength(arr, rows)) return;
	bobbleSortStr(arr, rows, iSL);
	int counter = 1, f;
	for (f = 1; f < rows; ++f) {
		if (arr[f][iSL] == arr[f - 1][iSL]) {
			++counter;
		}
		else if (counter > 1) {
			sortStr(arr + f - counter, counter, iSL + 1);
			counter = 1;
		}
	}
	if (counter > 1) {
		sortStr(arr + f - counter, counter, iSL + 1);
		counter = 1;
	}
}

int maxValue(int* pa, int* pd)
{
	return *pa < *pd ? *pd : *pa;
}

int minValue(int* pa, int* pd)
{
	return *pa > * pd ? *pd : *pa;
}

int maxValueDiagonal(int** squareMatrix, int length)
{
	int tmp = squareMatrix[0][0];
	for (int i = 1; i < length; ++i) {
		if (squareMatrix[i][i] > tmp) tmp = squareMatrix[i][i];
	}
	return tmp;
}

double maxValueDiagonal(double** squareMatrix, int length)
{
	double tmp = squareMatrix[0][0];
	for (int i = 1; i < length; ++i) {
		if (squareMatrix[i][i] > tmp) tmp = squareMatrix[i][i];
	}
	return tmp;
}

char maxValueDiagonal(char** squareMatrix, int length)
{
	char tmp = squareMatrix[0][0];
	for (int i = 1; i < length; ++i) {
		if (squareMatrix[i][i] > tmp) tmp = squareMatrix[i][i];
	}
	return tmp;
}

int minValueDiagonal(int** squareMatrix, int length)
{
	int tmp = squareMatrix[0][0];
	for (int i = 1; i < length; ++i) {
		if (squareMatrix[i][i] < tmp) tmp = squareMatrix[i][i];
	}
	return tmp;
}

double minValueDiagonal(double** squareMatrix, int length)
{
	double tmp = squareMatrix[0][0];
	for (int i = 1; i < length; ++i) {
		if (squareMatrix[i][i] < tmp) tmp = squareMatrix[i][i];
	}
	return tmp;
}

char minValueDiagonal(char** squareMatrix, int length)
{
	char tmp = squareMatrix[0][0];
	for (int i = 1; i < length; ++i) {
		if (squareMatrix[i][i] < tmp) tmp = squareMatrix[i][i];
	}
	return tmp;
}

int maxCommonDivisor(int A, int B)
{
	for (int i = 2; i <= A && i <= B; ++i) {
		if (isDivisor(A, i) && isDivisor(B, i)) {
			return i * maxCommonDivisor(A / i, B / i);
		}
	}
	return 1;
}

void maxValArrInd(int* arr, int length, int& maxVal, int& indexMaxVal)
{
	maxVal = *arr;
	indexMaxVal = 0;
	for (int i = 1; i < length; ++i) {
		if (maxVal < *(arr + i)) {
			maxVal = *(arr + i);
			indexMaxVal = i;
		}
	}
}

void maxValArrInd(double* arr, int length, double& maxVal, int& indexMaxVal)
{
	maxVal = *arr;
	indexMaxVal = 0;
	for (int i = 1; i < length; ++i) {
		if (maxVal < *(arr + i)) {
			maxVal = *(arr + i);
			indexMaxVal = i;
		}
	}
}

void maxValArrInd(char* arr, int length, char& maxVal, int& indexMaxVal)
{
	maxVal = *arr;
	indexMaxVal = 0;
	for (int i = 1; i < length; ++i) {
		if (maxVal < *(arr + i)) {
			maxVal = *(arr + i);
			indexMaxVal = i;
		}
	}
}

void minValArrInd(int* arr, int length, int& minVal, int& indexMinVal)
{
	minVal = *arr;
	indexMinVal = 0;
	for (int i = 1; i < length; ++i) {
		if (minVal > *(arr + i)) {
			minVal = *(arr + i);
			indexMinVal = i;
		}
	}
}

void minValArrInd(double* arr, int length, double& minVal, int& indexMinVal)
{
	minVal = *arr;
	indexMinVal = 0;
	for (int i = 1; i < length; ++i) {
		if (minVal > * (arr + i)) {
			minVal = *(arr + i);
			indexMinVal = i;
		}
	}
}

void minValArrInd(char* arr, int length, char& minVal, int& indexMinVal)
{
	minVal = *arr;
	indexMinVal = 0;
	for (int i = 1; i < length; ++i) {
		if (minVal > * (arr + i)) {
			minVal = *(arr + i);
			indexMinVal = i;
		}
	}
}

int* reserveArr(int length) // _old   (delete later)
{
	return new int[length];
}

void reserveArr(int length, int*& arr) // _new
{
	arr = new int[length];
}

char* reserveArrChar(int length)
{
	return new char[length];
}

void reserveArr(int length, int**& arr)
{
	arr = new int* [length];
}

void reserveArr(int rows, int columns, int**& arr)
{
	arr = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		arr[i] = reserveArr(columns);
	}
}

void reserveArr(int length, double*& arr) // _new
{
	arr = new double[length];
}

void reserveArr(int rows, int columns, double**& arr)
{
	arr = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		reserveArr(columns, arr[i]);
	}
}

void reserveArr(int length, char*& arr)
{
	arr = new char[length];
}

void reserveArr(int length, char**& arr)
{
	arr = new char* [length];
}

void reserveArr(int length, char***& arr)
{
	arr = new char** [length];
}

void reserveArr(int rows, int columns, char**& arr)
{
	reserveArr(rows, arr);
	for (int i = 0; i < rows; ++i) {
		reserveArr(columns, arr[i]);
	}
}

void reserveArr(int rows, int columns, int strLen, char***& arr)
{
	reserveArr(rows, arr);
	for (int i = 0; i < rows; ++i) {
		reserveArr(rows, columns, arr[i]);
	}
}


void addElToArr(int*& arr, int& length, int newEl, int indexNewEl)
{
	int* newArr = reserveArr(++length);
	copyArray(arr, indexNewEl, newArr);
	*(newArr + indexNewEl) = newEl;
	copyArray(arr + indexNewEl, length - indexNewEl - 1, newArr + indexNewEl + 1);
	removeArr(arr);
	arr = newArr;
}


void addElToArrToSpecialPlace(char*& arr, int length, char newEl, int indexNewEl)
{
	char* newArr = reserveArrChar(length);
	copyArray(arr, indexNewEl, newArr);
	*(newArr + indexNewEl) = newEl;
	copyArray(arr + indexNewEl, length - indexNewEl - 1, newArr + indexNewEl + 1);
	*(newArr + length - 1) = '\0';
	removeArr(arr);
	arr = newArr;
}

void addColumnToArr(int**& arr, int rows, int& columns, int* newColumn, int indexNewColumn)
{
	for (int i = 0; i < rows; ++i) {
		int length = columns;
		addElToArr(arr[i], length, newColumn[i], indexNewColumn);
	}
	++columns;
}

void removeElFromArr(int*& arr, int& length, int indexRemEl)
{
	int* newArr = reserveArr(--length);
	copyArray(arr, indexRemEl, newArr);
	copyArray(arr + indexRemEl + 1, length - indexRemEl, newArr + indexRemEl);
	delete[] arr;
	arr = newArr;
}

void removeColumnFromArr(int**& arr, int rows, int& columns, int indexRemColumn)
{
	for (int i = 0; i < rows; ++i) {
		removeElFromArr(arr[i], columns, indexRemColumn);
		++columns;
	}
	--columns;
}

void deleteLastElFromArr(int*& arr, int& length)
{
	int* newArr = reserveArr(--length);
	copyArray(arr, length, newArr);
	delete[] arr;
	arr = newArr;
}

void deleteLastElFromArr(char*& arr, int& length)
{
	char* newArr = reserveArrChar(--length);
	copyArray(arr, length, newArr);
	delete[] arr;
	arr = newArr;
}

void removeArr(int* arr)
{
	delete[] arr;
}

void removeArr(int** arr)
{
	delete[] arr;
}

void removeArr(int** arr, int lengthRows)
{
	while (lengthRows > 0) {
		removeArr(arr[--lengthRows]);
	}
	removeArr(arr);
}

void removeArr(char* arr)
{
	delete[] arr;
}

void removeArr(char** arr)
{
	delete[] arr;
}

void removeArr(char** arr, int lengthRows)
{
	for (int i = 0; i < lengthRows; ++i) {
		removeArr(arr[i]);
	}
	removeArr(arr);
}

int** multiplyMatrix(int** arrA, int** arrB, int aM, int K, int bN)
{
	//int** multiplyMatrix(int** arrA, int aRow, int aCol, int** arrb, int bRow, int bCol)
	int** newArr;
	reserveArr(aM, bN, newArr);
	for (int i = 0; i < aM; ++i) {
		for (int j = 0; j < bN; ++j) {
			newArr[i][j] = 0;
			for (int k = 0; k < K; ++k) {
				newArr[i][j] += arrA[i][k] * arrB[k][j];
			}
		}
	}
	return newArr;
}

int* deletePrimeNumbers(int* arr, int length, int& lengthNewArr)
{
	lengthNewArr = length; // non-prime numbers counter
	int* tmpArr = reserveArr(length);
	copyArray(arr, length, tmpArr);
	for (int i = 0; i < lengthNewArr; ++i) {
		if (isPrimeNumber(*(tmpArr + i)) == true) {
			shiftArrElLeft_old(tmpArr, i--, --lengthNewArr);
		}
	}
	int* newArr = reserveArr(lengthNewArr);
	copyArray(tmpArr, lengthNewArr, newArr);
	removeArr(tmpArr);
	return newArr;
}

//int** sumMatrix(int** arrA, int aRow, int aCol, int** arrB, int bRow, int bCol)
/*{
	int** arrC;
	int cRow = aRow > bRow ? aRow : bRow;
	int cCol = aCol > bCol ? aCol : bCol;
	reserveArr(cRow, cCol, arrC);
	for (int i = 0; i < cRow; ++i) {
		for (int j = 0; j < cCol; ++j) {
			if ()
			arrC[i][j] = arrA[i][j] + arrB[i][j];
		}
	}
	return arrC;
}*/

void transposeMatrix(int**& arrSource, int& rows, int& columns)
{
	int** arrNew;
	int rowsNew = columns;
	int columnsNew = rows;
	reserveArr(rowsNew, columnsNew, arrNew);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			arrNew[j][i] = arrSource[i][j];
		}
	}
	rows = rowsNew;
	columns = columnsNew;
	removeArr(arrSource);// rewrite delete
	arrSource = arrNew;
}

void shiftArrElRight_old(int* arr, int indexOfFirstElement, int indexOfSecondElement)
{
	for (int i = indexOfSecondElement; i != indexOfFirstElement; --i) {
		swap((arr + i - 1), (arr + i));
	}
}

void shiftArrElLeft_old(int* arr, int indexOfFirstElement, int indexOfSecondElement)
{
	for (int i = indexOfFirstElement; i != indexOfSecondElement; ++i) {
		swap((arr + i), (arr + i + 1));
	}
}

void shiftArrElLeft(int*& arr, int length, int times)
{
	int* newArr = reserveArr(length);
	copyArray(arr + times, length - times, newArr);
	copyArray(arr, times, newArr + length - times);
	delete[] arr;
	arr = newArr;
}

void shiftArrElRight(int*& arr, int length, int times)
{
	int* newArr = reserveArr(length);
	copyArray(arr, length - times, newArr + times);
	copyArray(arr + length - times, times, newArr);
	delete[] arr;
	arr = newArr;
}

void shiftColumnsLeft(int** arr, int rows, int columns, int times)
{
	for (int i = 0; i < rows; ++i) {
		shiftArrElLeft(arr[i], columns, times);
	}
}

void shiftColumnsRight(int** arr, int rows, int columns, int times)
{
	for (int i = 0; i < rows; ++i) {
		shiftArrElRight(arr[i], columns, times);
	}
}

void shiftArrRowsUp(int**& arr, int length, int times)
{
	int** newArr;
	reserveArr(length, newArr);
	copyArray(arr + times, length - times, newArr);
	copyArray(arr, times, newArr + length - times);
	delete[] arr;
	arr = newArr;
}

void shiftArrRowsDown(int**& arr, int length, int times)
{
	int** newArr;
	reserveArr(length, newArr);
	copyArray(arr, length - times, newArr + times);
	copyArray(arr + length - times, times, newArr);
	delete[] arr;
	arr = newArr;
}

void shiftArrValues(int**& arr, int rows, int columns, bool shiftHigher, int verticalSteps, bool shiftRight, int horizontalSteps)
{
	verticalSteps = verticalSteps < 0 ? 0 : verticalSteps;
	horizontalSteps = horizontalSteps < 0 ? 0 : horizontalSteps;

	verticalSteps = verticalSteps >= rows ? (verticalSteps % rows) : verticalSteps;
	horizontalSteps = horizontalSteps >= columns ? (horizontalSteps % columns) : horizontalSteps;

	shiftHigher ? shiftArrRowsUp(arr, rows, verticalSteps) : shiftArrRowsDown(arr, rows, verticalSteps);
	shiftRight ? shiftColumnsRight(arr, rows, columns, horizontalSteps) : shiftColumnsLeft(arr, rows, columns, horizontalSteps);
}

void copyArray(int* arr, int lengthOfShortestArray, int* arrCopy)
{
	for (int i = 0; i < lengthOfShortestArray; ++i) {
		*(arrCopy + i) = *(arr + i);
	}
}

void copyArray(int** arr, int lengthOfShortestArray, int** arrCopy)
{
	for (int i = 0; i < lengthOfShortestArray; ++i) {
		arrCopy[i] = arr[i];
	}
}

void copyArray(char* arrSource, int length, char* arrDest)
{
	for (int i = 0; i < length; ++i) {
		*(arrDest + i) = *(arrSource + i);
	}
}

void copyArray(int* arrSource, int length, char* arrDest)
{
	for (int i = 0; i < length; ++i) {
		*(arrDest + i) = *(arrSource + i) + 48;
	}
}

int sumArrValues(int* curEl, int* endEl)
{
	if (curEl == endEl) {
		return *endEl;
	}
	return *curEl + sumArrValues((curEl + 1), endEl);
}

double calcAverage(int* arr, int length)
{
	return (double)sumArrValues(arr, arr + length - 1) / length;
}

void calcNumbers(int* arr, int length, int& negCounter, int& zerosCounter, int& posCounter)
{
	for (int i = 0; i < length; ++i) {
		if (arr[i] > 0) posCounter++;
		else if (arr[i] == 0) zerosCounter++;
		else                  negCounter++;
	}
}

void separateArrValues(int* arr, int length, int*& arrNeg, int& lenNeg, int*& arrZero, int& lenZero, int*& arrPos, int& lenPos)
{
	for (int i = 0; i < length; ++i) {
		if (*(arr + i) > 0) {
			addElToArr(arrPos, lenPos, *(arr + i));
		}
		else if (*(arr + i) < 0) {
			addElToArr(arrNeg, lenNeg, *(arr + i));
		}
		else {
			addElToArr(arrZero, lenZero, *(arr + i));
		}
	}
}

void separateUniqElFromArr1ExceptArr2ElToNewArr(int* arr, int length, int* excludeArr, int lengthExclude, int*& arrNew, int& lengthNew)
{
	for (int i = 0; i < length; ++i) {
		if (isUniqNumber(*(arr + i), excludeArr, lengthExclude) && isUniqNumber(*(arr + i), arrNew, lengthNew)) {
			addElToArr(arrNew, lengthNew, *(arr + i));
		}
	}
}

int mathSumValFromRange(int a, int b)
{
	if (a > b) {
		swap(a, b);
	}
	int sum = 0;
	for (int i = a + 1; i < b; ++i) {
		sum += i;
	}
	return sum;
}

int* findPerfectNumbersFromRange(int firstIndex, int lastIndex, int& length)
{
	int* arr = reserveArr(length);
	for (int i = firstIndex; i <= lastIndex; ++i) {
		if (isPerfectNumber(i) == true) {
			addElToArr(arr, length, i);
		}
	}
	return arr;
}

bool isUniqNumber(int number, int* arr, int length)
{
	for (int i = 0; i < length; ++i) {
		if (number == *(arr + i)) {
			return false;
		}
	}
	return true;
}

bool isPerfectNumber(int a)
{
	if (a < 0) {
		a *= -1;
	}
	int sum = 0;
	for (int i = 1; i < a; ++i) {
		if (isDivisor(a, i) == true) {
			sum += i;
		}
	}
	return sum == a;
}

bool isDivisor(int a, int divisor)
{
	return a % divisor == 0;
}

int countDigits(int inp)
{
	for (int i = 9; i >= 0; --i) {
		if (inp / (int)pow(10, i) != 0) return i + 1;
	}
	return 0;
}

void separateDigits(int inp, int*& output, int& length)
{
	length = countDigits(inp);
	reserveArr(length, output);
	for (int i = length; i > 0; --i) {
		output[length - i] = inp % (int)pow(10, i) / (int)pow(10, i - 1);
	}
}

bool isNumberHappy(int number)
{
	if (number <= 1000000 && number >= 100000) {
		int d1 = number % 1000000 / 100000;
		int d2 = number % 100000 / 10000;
		int d3 = number % 10000 / 1000;
		int d4 = number % 1000 / 100;
		int d5 = number % 100 / 10;
		int d6 = number % 10 / 1;
		if ((d1 + d2 + d3) == (d4 + d5 + d6)) {
			return true;
		}
	}
	else {
		cout << "U have entered not 6-digit number. Please, try again.\n";
	}
	return false;
}

bool isPrimeNumber(int number)
{
	if (number < 2) {
		return false;
	}
	for (int i = 2; i < number; ++i) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int searchIndexOfKeyEl(int* arr, int length, int searchedEl)
{ // linear search
	for (int i = 0; i < length; ++i) {
		if (*(arr + i) == searchedEl) {
			return i;
		}
	}
	return -1;
}

int searchIndexOfKeyElBinar(int* arr, int length, int searchedEl)
{ // binar search
	if (searchedEl >= *(arr) && searchedEl <= *(arr + length - 1)) {
		int lBorderInd = 0;          // array`s left border index
		int rBorderInd = length;     // array`s right border index
		int mid;                     // array`s middle element index
		for (int i = 0; i < length; ++i) {
			mid = lBorderInd + (rBorderInd - lBorderInd) / 2;
			if (searchedEl == *(arr + mid)) {
				return mid;
			}
			else if (searchedEl < *(arr + mid)) {
				rBorderInd = mid;
			}
			else if (searchedEl > * (arr + mid)) {
				lBorderInd = mid;
			}
		}
	}
	return -1;
}

int convertBinarySystemNumberToDecimal(int input)
{
	if (input == 0) {
		return 0;
	}
	int digitCounter = 10;
	int* arr;
	for (int i = 1000000000; i > 0; i /= 10) {
		if (input / i != 0) {
			arr = reserveArr(digitCounter);
			for (int i = 0; i < digitCounter; ++i) {
				*(arr + i) = input % (int)mathPow(10, digitCounter - i) / (int)mathPow(10, digitCounter - i - 1);
			}
			int rslt = 0;
			for (int i = 0; i < digitCounter; ++i) {
				rslt += *(arr + i) * mathPow(2, digitCounter - 1 - i);
			}
			return rslt;
		}
		else {
			digitCounter--;
		}
	}
	return -1;
}

int convertBinarySystemNumberToDecimal(long long int input) {
	if (input == 0) {
		return 0;
	}
	int digitCounter = 19;
	int* arr;
	for (long long int i = 1000000000000000000; i > 0; i /= 10) {
		if (input / i != 0) {
			arr = reserveArr(digitCounter);
			for (int j = 0; j < digitCounter; ++j) {
				int tmp = input % mathPow(10, digitCounter - j) / mathPow(10, digitCounter - j - 1);
				*(arr + j) = tmp;
			}
			int rslt = 0;
			for (int k = 0; k < digitCounter; ++k) {
				rslt += *(arr + k) * mathPow(2, digitCounter - 1 - k);
			}
			return rslt;
		}
		else {
			digitCounter--;
		}
	}
	return -1;
}

void findName(char*** arr, int columns, char* strName, int setMinimumWidth)
{
	const int rowName = 0; // name row
	const int rowPNum = 1; // phone number row
	cout << setw(setMinimumWidth) << "Names" << setw(setMinimumWidth) << "Phone numbers" << endl;
	for (int i = 0; i < columns; ++i) {
		if (strstr(arr[rowName][i], strName)) {
			cout << setw(setMinimumWidth) << arr[rowName][i] << setw(setMinimumWidth) << arr[rowPNum][i] << endl;
		}
	}
	cout << "The end of search results\n\n";
}

void findPhone(char*** arr, int columns, char* strPhoneNumber, int setMinimumWidth)
{
	const int rowName = 0; // name row
	const int rowPNum = 1; // phone number row
	cout << setw(setMinimumWidth) << "Names" << setw(setMinimumWidth) << "Phone numbers" << endl;
	for (int i = 0; i < columns; ++i) {
		if (strstr(arr[rowPNum][i], strPhoneNumber)) {
			cout << setw(setMinimumWidth) << arr[rowPNum][i] << setw(setMinimumWidth) << arr[rowName][i] << endl;
		}
	}
	cout << "The end of search results\n\n";
}

void enterStr(char*** arr, int row, int column, int strLength)
{
	cin.getline(arr[row][column], strLength);
}

void addContact(char*** arr, int column, int strLength)
{
	const int rowName = 0; // name row
	const int rowPNum = 1; // phone number row
	cout << "Enter the name, please: --> ";
	enterStr(arr, rowName, column, strLength);
	cout << "Enter the phone number, please: --> ";
	enterStr(arr, rowPNum, column, strLength);
}

void addContact(char*** arr, int column, int strLength, char* name, char* pNumber)
{
	if (strlen(name) > strLength) {
		char* nameNew;
		reserveArr(strLength, nameNew);
		copyArray(name, strLength, nameNew);
		name = nameNew;
	}
	if (strlen(pNumber) > strLength) {
		char* pNumberNew;
		reserveArr(strLength, pNumberNew);
		copyArray(pNumber, strLength, pNumberNew);
		pNumber = pNumberNew;
	}
	const int rowName = 0; // name row
	const int rowPNum = 1; // phone number row
	arr[rowName][column] = name;
	arr[rowPNum][column] = pNumber;

}

fraction sum(fraction A, fraction B)
{
	if (A.denominator != B.denominator) {
		int tmp = A.denominator * B.denominator;
		A.numerator *= (tmp / A.denominator);
		A.denominator = tmp;
		B.numerator *= (tmp / B.denominator);
		B.denominator = tmp;
	}
	fraction res = { A.numerator + B.numerator, A.denominator };
	return res;
}

fraction substr(fraction A, fraction B)
{
	if (A.denominator != B.denominator) {
		int tmp = A.denominator * B.denominator;
		A.numerator *= (tmp / A.denominator);
		A.denominator = tmp;
		B.numerator *= (tmp / B.denominator);
		B.denominator = tmp;
	}
	fraction res = { A.numerator - B.numerator, A.denominator };
	return res;
}

fraction multipy(fraction A, fraction B)
{
	fraction res = { A.numerator * B.numerator, A.denominator * B.denominator };
	return res;
}

fraction divide(fraction A, fraction B)
{
	fraction res = { A.numerator * B.denominator, A.denominator * B.numerator };
	return res;
}

void reduceFraction(fraction& A)
{
	for (int i = minValue(&A.numerator, &A.denominator); i > 0; --i) {
		if (isDivisor(A.numerator, i) && isDivisor(A.denominator, i)) {
			A.numerator /= i;
			A.denominator /= i;
			break;
		}
	}
}

void printFraction(fraction A)
{
	cout << A.numerator << endl;
	cout << "---" << endl;
	cout << A.denominator << endl;
}

double distance(point A, point B)
{
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

void moveFig(rectangle& fig, int moveX, int moveY)
{
	fig.x += moveX;
	fig.y += moveY;
}

void scaleHeight(rectangle& fig, double multiplier)
{
	fig.height *= multiplier;
}

void scaleLength(rectangle& fig, double multiplier)
{
	fig.length *= multiplier;
}

void drawFig(rectangle fig)
{
	char lu = 201, ld = 200;
	char ru = 187, rd = 188;
	char hor = 205;
	char vert = 186;
	fig.length *= 1.4; // it is for correct drawing in console
	// TOP
	cout << lu;
	for (int j = 0; j < fig.length; ++j) {
		cout << hor;
	}
	cout << ru << endl;
	// MIDDLE
	for (int i = 1; i < fig.height - 1; ++i) {
		cout << vert;
		for (int j = 0; j < fig.length; ++j) {
			cout << ' ';
		}
		cout << vert << endl;
	}
	// BOTTOM
	cout << ld;
	for (int j = 0; j < fig.length; ++j) {
		cout << hor;
	}
	cout << rd << endl;
}

void printFig(rectangle fig)
{
	cout << " coordinate x = " << fig.x << endl;
	cout << " coordinate y = " << fig.y << endl;
	cout << " height = " << fig.height << endl;
	cout << " length = " << fig.length << endl;
}

bool isLeapYear(int year)
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0)   return true;
	return false;
}

int calcDays(int day1, int month1, int year1, int day2, int month2, int year2)
{
	if (year1 > year2) {
		swap(day1, day2);
		swap(month1, month2);
		swap(year1, year2);
	}
	int daysInMonth[] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	int daysCounter1 = day1 + daysInMonth[month1] + (month1 > 2 ? isLeapYear(year1) : 0);

	int daysCounter2 = day2 + daysInMonth[month2] + (month2 > 2 ? isLeapYear(year2) : 0);
	for (int i = year1; i < year2; ++i) {
		daysCounter2 += 365 + isLeapYear(i);
	}
	return daysCounter2 - daysCounter1;
}

int compareArr(int* arr1, int length, int* arr2)
{
	int counter = 0;
	for (int i = 0; i < length; ++i) {
		if (arr1[i] == arr2[i]) ++counter;
	}
	return counter;
}

int compareArr(char* arr1, char* arr2)
{
	int counter = 0;
	for (int i = 0; arr1[i] != '\0'; ++i) {
		if (arr1[i] == arr2[i]) ++counter;
	}
	return counter;
}

char* convertIntToCharArr(int number)
{
	int* arr, length;
	separateDigits(number, arr, length);
	char* charArr;
	reserveArr(length + 1, charArr);
	charArr[length] = '\0';
	copyArray(arr, length, charArr);
	removeArr(arr);
	return charArr;
}

void game_BullsAndCows()
{
	int progNumber = fillRandom4DigitValue();
	char* progCharArr = convertIntToCharArr(progNumber);
	int userNumber, cows, counterIterations = 0;
	do {
		cout << "\nEnter the number, please: ";
		cin >> userNumber;
		while (userNumber < 1000 || userNumber > 9999) {
			cout << "\nYou`ve entered non-4 digit number, please try again: ";
			cin >> userNumber;
		}
		char* userCharArr = convertIntToCharArr(userNumber);
		++counterIterations;
		cout << "There are " << countSymbolsInArr1isFromArr2(progCharArr, userCharArr) << " bulls\n";
		cows = compareArr(progCharArr, userCharArr);
		cout << "There are " << cows << " cows.\n";
	} while (cows != 4);
	cout << "\nIt takes " << counterIterations << " iterations to find the right number.\n";
}

void process()
{
#define CHAR

#if defined(INTEGER) || defined(DOUBLE) || defined(CHAR)
	int length = 10;
	#if defined(INTEGER)
		int* arr;
		int minVal, minValInd, maxVal, maxValInd;
	#elif defined(DOUBLE)
		double* arr;
		double minVal, maxVal;
		int maxValInd, minValInd;
	#elif defined(CHAR)
		char* arr;
		char minVal, maxVal;
		int maxValInd, minValInd;
	#endif
	reserveArr(length, arr);
	fillRandomValuesToTheArray(arr, length);
	printArr(arr, length);
	quickSort(arr, length - 1);
	minValArrInd(arr, length, minVal, minValInd);
	maxValArrInd(arr, length, maxVal, maxValInd);
	printArr(arr, length);
	cout << "minVal = " << minVal;
#endif
}

int countStringsInFile(char* filepth) {
	FILE* file;
	if (fopen_s(&file, filepth, "r")) {
		cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char str[maxStringSize];
	int strCounter = 0;
	while (char* str2 = fgets(str, maxStringSize, file)) {
		++strCounter;
	}
	if (fclose(file)) {
		cout << "Unable to close file";
		return -2;
	}
	return strCounter;
}

int countCharsInFile(char* filepth) {
	FILE* file;
	if (fopen_s(&file, filepth, "r")) {
		cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char str[maxStringSize];
	int counter = 0;
	while (char* str2 = fgets(str, maxStringSize, file)) {
		counter += strlen(str2);
	}
	if (fclose(file)) {
		cout << "Unable to close file";
		return -2;
	}
	return counter;
}

void writeStringsToFile(const char* filepath, const char* strings[], int stringsSize)
{
	FILE* file;
	if (fopen_s(&file, filepath, "w")) {
		cout << "Unable to open file";
		return;
	}

	for (int i = 0; i < stringsSize; ++i) {
		fputs(strings[i], file);
		fputs("\n", file);
	}

	if (fclose(file)) {
		cout << "Unable to close file";
		return;
	}
}

void changeCharInFile(const char* sourcefilepath, const char* destfilepath, char sCh, char dCh)
{
	FILE* sourcefile;
	if (fopen_s(&sourcefile, sourcefilepath, "r")) {
		cout << "Unable to open sourcefile";
		return;
	}
	FILE* destfile;
	if (fopen_s(&destfile, destfilepath, "w")) {
		cout << "Unable to open destfile";
		return;
	}

	const int maxStringSize = 1024;
	char str[maxStringSize];

	while (fgets(str, maxStringSize, sourcefile)) {
		while (char* p = strchr(str, sCh)) {
			*p = dCh;
		}
		fputs(str, destfile);
	}

	if (fclose(sourcefile)) {
		cout << "Unable to close file";
		return;
	}
	if (fclose(destfile)) {
		cout << "Unable to close file";
		return;
	}
}

int countWordsFile(const char* filepath, char searchedChar)
{
	FILE* file;
	if (fopen_s(&file, filepath, "r")) {
		cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char str[maxStringSize];
	int counter = 0;
	while (fgets(str, maxStringSize, file)) {
		char* context;
		char* word = strtok_s(str, " ", &context);
		while (word) {
			if (word[0] == searchedChar) {
				++counter;
			}
			word = strtok_s(NULL, " ", &context);
		}
	}
	if (fclose(file)) {
		cout << "Unable to close file";
		return -2;
	}
	return counter;
}

int countWordsFile(const char* filepath)
{
	FILE* file;
	if (fopen_s(&file, filepath, "r")) {
		cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char str[maxStringSize];
	int counter = 0;
	while (fgets(str, maxStringSize, file)) {
		char* context;
		char* word = strtok_s(str, " ", &context);
		while (word) {
			++counter;
			word = strtok_s(NULL, " ", &context);
		}
	}
	if (fclose(file)) {
		cout << "Unable to close file";
		return -2;
	}
	return counter;
}

void copyStingsFromFileToFile(const char* sourceFilepath, const char* destFilepath)
{
	FILE* sourceFile;
	if (fopen_s(&sourceFile, sourceFilepath, "r")) {
		cout << "Unable to open file";
		return;
	}
	FILE* destFile;
	if (fopen_s(&destFile, destFilepath, "w")) {
		cout << "Unable to open file";
		return;
	}

	const int maxStringSize = 1024;
	char str[maxStringSize];
	while (fgets(str, maxStringSize, sourceFile)) {
		fputs(str, destFile);
	}

	if (fclose(sourceFile)) {
		cout << "Unable to close file";
		return;
	}
	if (fclose(destFile)) {
		cout << "Unable to close file";
		return;
	}
}

void copyStingsFromFileToFileReverse(const char* sourceFilepath, const char* destFilepath)
{
	FILE* sourceFile;
	if (fopen_s(&sourceFile, sourceFilepath, "r")) {
		cout << "Unable to open file";
		return;
	}
	FILE* destFile;
	if (fopen_s(&destFile, destFilepath, "w")) {
		cout << "Unable to open file";
		return;
	}
	const int maxStringSize = 1024;
	int strCounter = countStringsInFile((char*)sourceFilepath);
	char** arr;
	reserveArr(strCounter, maxStringSize, arr);
	int i = 0;
	while (fgets(arr[i++], maxStringSize, sourceFile));
	for (int i = 0; i < strCounter; ++i) {
		fputs(arr[strCounter - 1 - i], destFile);
		if (!i) fputs("\n", destFile);
	}
	removeArr(arr);
	if (fclose(sourceFile)) {
		cout << "Unable to close file";
		return;
	}
	if (fclose(destFile)) {
		cout << "Unable to close file";
		return;
	}
}

int replaceWordsToFile(const char* filepath, const char* destFilepath, int wordLength)
{
	FILE* file;
	if (fopen_s(&file, filepath, "r")) {
		cout << "Unable to open file";
		return -1;
	}
	FILE* destFile;
	if (fopen_s(&destFile, destFilepath, "w")) {
		cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char str[maxStringSize];

	while (fgets(str, maxStringSize, file)) {
		char* context;
		char* word = strtok_s(str, " ", &context);
		while (word) {
			if (strlen(word) > wordLength) {
				fputs(word, destFile);
				fputs(" ", destFile);
			}
			word = strtok_s(NULL, " ", &context);
		}
		fputs("\n", destFile);
	}

	if (fclose(file)) {
		cout << "Unable to close file";
		return -2;
	}
	if (fclose(destFile)) {
		cout << "Unable to close file";
		return -2;
	}
	return 0;
}

int insertStringToFile(const char* filepath)
{
	int strCounter = countStringsInFile((char*)filepath);
	FILE* file;
	if (fopen_s(&file, filepath, "r+")) {
		cout << "Unable to open file";
		return -1;
	}
	const int maxStringSize = 1024;
	char** arr;
	reserveArr(strCounter + 1, maxStringSize, arr);
	int i = 0;
	int strWithoutSpacesIndex;
	while (fgets(arr[i], maxStringSize, file)) {
		if (!strchr(arr[i], ' ')) {
			strWithoutSpacesIndex = i;
		}
		++i;
	}
	arr[strCounter] = (char*)"------\n";
	for (int i = strCounter; i > strWithoutSpacesIndex + 1; --i) {
		swap(arr + i, arr + i - 1);
	}

	fseek(file, 0, 0);

	for (int i = 0; i <= strCounter; ++i) {
		fputs(arr[i], file);
	}

	printArr(arr, strCounter + 1);
	removeArr(arr);
	if (fclose(file)) {
		cout << "Unable to close file";
		return -2;
	}
	return 0;
}