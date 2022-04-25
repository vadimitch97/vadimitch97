#include <iostream>
#include <cstdlib>

// 1. �������� ������ �� 2� cpp ������ � ������������� (main.cpp, mylib.cpp, mylib.h) �� ������ ������ mylib �������� 3 �������: 
//    ��� ������������� ������� (���� float), ������ ��� �� ����� � �������� ���������� ������������� � ������������� ���������. 
//    ��������� ��� 3-� ������� �� main ��� ������ � ��������.


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