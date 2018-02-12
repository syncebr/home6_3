/*Создать массив целых чисел размерностью N и заполнить его случайными числами от -20 до 20. Объявить два массива указателей.
Заполнить первый из них указателями на положительные числа исходного массива, а второй – указателями на отрицательные числа.
Пользуясь массивами указателей, вывести на консоль сначала положительные, а потом отрицательные значения.*/

#include <iostream>
#include <ctime>
using namespace std;

void GenerateArr(int arr[], int size);

int main(void)
{
	setlocale(LC_ALL, "rus");
	const int SIZE = 10;
	srand(time(0));
	int arr[SIZE];
	int *polPtr[SIZE];
	int *negPtr[SIZE];
	cout << " Исходный массив \n";
	GenerateArr(arr, SIZE);
	cout << endl;
	int *ptr = arr;
	int **negativePtr = negPtr;
	int **positivePtr = polPtr;
	int countNeg = 0;
	int countPol = 0;
	while (ptr < arr + SIZE){
		if (*ptr < 0){
			*negativePtr++ = ptr;
			countNeg++;
		}
		if (*ptr > 0){
			*positivePtr++ = ptr;
			countPol++;
		}
		ptr++;
	}
	cout << " Массив положительных \n";
	for (int i = 0; i < countPol; i++)
	{
		cout << " " << *polPtr[i] << "  ";
	}
	cout << endl;
	cout << " Массив отридцательных \n";
	for (int i = 0; i < countNeg; i++)
	{
		cout << " " << *negPtr[i] << "  ";
	}
	cout << endl;
	system("pause");
}

void GenerateArr(int arr[], int size) {
	int *ptr = arr;
	for (int i = 0; i < size; i++, ptr++) {
		*ptr = rand() % 41 - 20;
		cout << " " << *ptr << "  ";
	}
}
