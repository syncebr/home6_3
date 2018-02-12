/*Двумерный массив размерностью N строк на M столбцов заполнить случайными целыми числами от -10 до 10.
Сформировать массив указателей на начало каждой строки двумерного массива.
Отсортировать этот массив указателей так, чтобы первые элементы строк оказались в порядке возрастания
(сам двумерный массив не изменяется, меняется только массив указателей).
Вывести строки двумерного массива в полученном порядке.*/

#include<iostream>
#include<ctime>

using namespace std;

void GenerateArr(int arr[], int row, int col);
void PrintArr(int arr[], int row, int col);

int main(void) {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int ROW = 5;
	const int COL = 6;
	int arr[ROW][COL];
	GenerateArr(arr[0], ROW, COL);
	PrintArr(arr[0], ROW, COL);
	system("pause");
	return 0;
}

void GenerateArr(int arr[], int row, int col) {
	int *ptr;
	ptr = arr;
	while (ptr < (arr + row*col)) {
		*ptr = rand() % 21 - 10;
		ptr++;
	}
}

void PrintArr(int arr[], int row, int col) {
	int *ptr;
	ptr = arr;
	int counter=0;
	while (ptr < (arr + row*col)) {
		printf("%2d  ",*ptr);
		counter++;
		ptr++;
		if (counter%col == 0) cout << endl;
	}
	cout << endl;
}
