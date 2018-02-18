/*Двумерный массив размерностью N строк на M столбцов заполнить случайными целыми числами от -10 до 10.
Сформировать массив указателей на начало каждой строки двумерного массива.
Отсортировать этот массив указателей так, чтобы первые элементы строк оказались в порядке возрастания
(сам двумерный массив не изменяется, меняется только массив указателей).
Вывести строки двумерного массива в полученном порядке.*/

#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>

#include <iostream>
#include <ctime>
#define ROW 6
#define COL 2
using namespace std;
void randArr(int *arr, int sizeArr);
void multiRandArr(int *arr, int row, int col);
void printArr(int *arr, int sizeArr);
void multiPrintArr(int *arr, int row, int col);

int main(void)
{
	//setlocale(LC_ALL, "rus");
	srand(time(0));
	int myArr[ROW][COL] = {};
	multiRandArr(myArr[0], ROW, COL);
	multiPrintArr(myArr[0], ROW, COL);
	cout << endl << endl;

	int *arr[ROW];
	int *rowPtr = myArr[0];

	int i = 0;
	while (rowPtr < myArr[0] + ROW * COL)
	{
		arr[i++] = rowPtr;
		rowPtr += COL;
	}
	//Сортировка методом пузырька
	for (int k = ROW - 1; k > 0; k--)
		for (int i = 0; i < k; i++)
			if (*arr[i] > *arr[i + 1])
			{
				int *tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
	for (int i = 0; i<ROW; i++)
	{
		printArr(arr[i], COL);
		cout << endl;
	}
	//system("pause");
}



void randArr(int *arr, int sizeArr) {
	for (int i = 0; i<sizeArr; i++, arr++)
		*arr = rand() % 21 - 10;
}
void multiRandArr(int *arr, int row, int col) {
	for (int i = 0; i < row; i++, arr += col) {
		randArr(arr, col);
	}
}
void printArr(int *arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, arr++)
		printf("%3d ", *arr);
}
void multiPrintArr(int *arr, int row, int col) {
	for (int i = 0; i < row; i++, arr += col) {
		printArr(arr, col);
		cout << endl;
	}
}
