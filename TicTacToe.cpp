

#include <iostream>
#include <clocale>

using namespace std;
    
    //1. Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double).

    short int A = 0;
    int B = 1;
    long long C = 2;
    char D = 3;
    bool E = false;
    float F = 5.1;
    double G = -6.1;

    //4. * Создать структуру(struct) данных «Поле для игры в крестики - нолики» и
    //  снабдить его всеми необходимыми свойствами(подумайте что может понадобиться).

    struct GameMap
    {
        unsigned short int score; //счет
        char shading; // закрашивание ячейки
        char playerName; // имя игрока
        char line; // линия при выйгрыше




    };


main()
{
    setlocale(LC_ALL, "Russia");

    //2. Создать перечисление (enum) с возможными вариантами символов для игры в крестики - нолики.

    enum Marker
    {
        x,
        o,
        v
    };


    //3. Создать массив, способный содержать значения такого перечисления иинициализировать его.

    int Array[3][3] = { 0 };









}

