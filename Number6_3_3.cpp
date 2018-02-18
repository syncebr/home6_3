/*Создать массив указателей на строки, содержащие мужские и женские имена
 * (имена задать литералами в программе). Создать массив указателей на указатели, которые ссылаются
 * на мужские имена в первом массиве. Аналогично создать массив указателей на указатели на женские имена.
 * Пользуясь указателями, распечатать общий список имен, список мужских и список женских имен.  */



#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

int main(void)
{
	//setlocale(LC_ALL, "rus");
	//инициализация массива указателей
	char *name[] = { "Александр", "Максим", "Виктория", "Василий", "Григорий", "Александра","Евгения", "Ольга", "Анастасия", "Светлана", "Олег", "Иван" };

	char **male[] = { name, name +  1, name + 3, name + 4, name + 10,name +11 };
	char **female[] = { name + 2, name + 5, name + 6, name + 7, name + 8, name + 9};


	printf("Список всех имен:\n");
	char **namePtr;
	namePtr = name;
	for (int i = 0; i<12; i++, namePtr++)
		printf("%s\n", *namePtr);

	printf("\nСписок мужских имен:\n");
	char ***ptr;
	ptr = male;
	for (int i = 0; i<5; i++, ptr++)
		printf("%s\n", **ptr);

	printf("\nСписок женских имен:\n");
	ptr = female;
	for (int i = 0; i<7; i++, ptr++)
		printf("%s\n", **ptr);

	//system("pause");
}
