﻿
#include <iostream>
#include <clocale>
using namespace std;

//1) Написать программу, проверяющую что сумма двух(введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), если да – вывести строку "true", 
//в противном случае – "false";

int a;
int b;

//2. Написать программу, выводящую на экран строку “true”, если две целочисленные константы, объявленные в её начале либо
//обе равны десяти сами по себе, либо их сумма равна десяти. Иначе "false".

const int z = 5;
const int k = 5;

//3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. Например: "Your numbers: 1 3 5 7 9 11 13 …". Для решения используйте любой С++ цикл

// 4. Со звёздочкой. Написать программу, проверяющую, является ли некоторое число - простым.Простое число — это целое положительное число, которое делится без остатка
//только на единицу и себя само.
int number;
int check;




int main()
{
    setlocale(LC_ALL, "Russia");

    // первое задание
    cout << "1 number\n";

    cin >> a;

    cout << "2 number\n";

    cin >> b;

    int c = a + b;

    if (c <= 10 && c >= 20)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
    



    //второе задание
    int m = z + k;

    if (m == 10)
    {
        cout << "True\n";
    }
    else if (z == 10 && k == 10)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }



    //третье задание
    for (int i = 1; i < 50; i+=2)
    {
        cout << i << " ";
    }
    
    cout << endl;



    //четвёртое число
    cout << "enter a number to check\n";

    cin >> number;

    check = number % number;

    if (check == 0 && number >= 0)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }





    return 0;
}

