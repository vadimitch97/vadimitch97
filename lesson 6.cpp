#include <iostream>
#include <fstream>


// 1.Выделить в памяти динамический одномерный массив типа int.Размер массива запросить у пользователя.Инициализировать его числами 
//степенями двойки : 1, 2, 4, 8, 16, 32, 64, 128 ... Вывести массив на экран.Не забыть освободить память. = ) Разбить программу на функции.


bool printArray(int ptrArr[], int n)
{

    for (size_t i = 1; i < n; i *= i)
    {
        std::cout << ptrArr[i] << " ";
    }
    std::cout << "\n";
    return true;
}

// 2. Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
//Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.

bool printArray2(int length, int width)
{

    int** ptrArr2;

    ptrArr2 = new int* [length];
    for (size_t i = 0; i < length; i++)
    {
        ptrArr2[i] = new int[width];
    }

    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            ptrArr2[i][j] == rand();
            std::cout << ptrArr2[i][j] << " ";
        }
    }
    std::cout << "\n";

    for (size_t i = 0; i < length; i++)
    {
        delete[] ptrArr2[i];
    }
    delete[] ptrArr2;
    ptrArr2 = nullptr;
}




int main()
{
// 1задание
    int* ptrArr;
    int n;
    std::cout << "Enter size: ";
    std::cin >> n;

    if (n > 0)
    {
        ptrArr = new (std::nothrow) int[n];

        if (ptrArr != nullptr)
        {
            if (printArray (ptrArr, n))
            {
                std::cout  << "sucsess\n";

                delete[] ptrArr;
                ptrArr = nullptr;
            }
        }
        else
        {
            std::cout << "Error\n";
        }
    }
    
    // 2 задание
    
    const size_t length = 4;
    const size_t width = 4;
    if (printArray2 (length, width))
    {
        std::cout << "sucsess\n";
    }

    // 3. Написать программу, которая создаст два текстовых файла (*.txt), 
    //примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.

    const size_t size = 10;
    int array[size] = { 10, 10, 10, 10,  10,  10,  10,  10,  10,  10, };

    std::ofstream fout("data.txt");

    int i = 0;
    for (int element : array)
    {
        fout << i++ << element << "+ 5 simbols)\n";
    }
    fout.close();
    
    std::ofstream fout("data1.txt");

    int i = 0;
    for (int element : array)
    {
        fout << i++ << element << "+ 5 simbols)\n";
    }
    fout.close();
}


