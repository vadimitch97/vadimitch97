#include <iostream>

// 1.Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.


bool printArray(double arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	return true;
}

// 2.Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, 
//заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.


bool swapPrintArray(int arr1[], int size_1)
{
	int j;
	for (size_t j = 0; j < size_1; j++)
	{
		if (arr1[j] == 0)
		{
			arr1[j] = 1;
			std::cout << arr1[j] << " ";
		}
		else
		{
			arr1[j] = 0;
			std::cout << arr1[j] << " ";
		}
	}
	std::cout << "\n";
	return true;
}

// 3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.


bool PrintArrayar(int arr2[], int size_2)
{
	int i;
	for (size_t i = 0; i < size_2; i++)
	{
		if (true)
		{

		}
	}
}


int main()
{
	// задание 1///////////////////////////////////////

	const int mysize = 3;
	double myarr[] = { 35.6, 42.3, 11.2 };

	if (printArray(myarr, mysize))
	{
		std::cout << "success\n";
	}
	

	//////Задание 2//////////////

	const int mysyze_1 = 10;
	int myarr1[] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

	if (swapPrintArray(myarr1, mysyze_1))
	{
		std::cout << "succes\n";
	}
	




}

