#include <iostream>
#include <cstdlib>

// 1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: 
//    для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов. 
//    Вызывайте эти 3-и функции из main для работы с массивом.


void inicArray(float* array, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 100 + (-50);
	}
}



void printArray(float array[], int size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << array[i] << " ";
}

void checkk(float* array, int size)
{
	int poloj = 0;
	int minus = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] < 0)
		{
			minus++;
		}
		else
		{
			poloj++;
		}
	}
	std::cout << "Otricatelnih chisel:" << minus << "\n" << "Polozitelnih chisel:" << poloj;
}