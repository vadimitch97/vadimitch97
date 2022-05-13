#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
using namespace std;

//====================================================================================================================================================================

enum TCell : char {
	CROSS = 'X',
	ZERO = 'O',
	EMPTY = '_'

};

enum TProgress {
	IN_PROGRESS,
	WON_HUMAN,
	WON_AI,
	DRAW

};

struct TCoord {
	size_t y{ 0U };
	size_t x{ 0U };

};

#pragma pack(push, 1)
struct TGame
{
	const size_t SIZE = 3;
	TCell** ppField = nullptr;
	TProgress progress = IN_PROGRESS;
	size_t turn{ 0U }; // четные ходит человек, не четные пк
	TCell human;
	TCell ai;
};
#pragma pack(pop)

//====================================================================================================================================================================

inline void clearScr()
{
	system("cls"); //win
	
}

int32_t __fastcall getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

void __fastcall initGame(TGame& g)
{
	g.ppField = new TCell * [g.SIZE]; //столбец указателей
	for (size_t i = 0; i < g.SIZE; i++)
	{
		g.ppField[i] = new TCell[g.SIZE]; //строки игрового поля
	}
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			g.ppField[y][x] = EMPTY; //записываем символ пустоты при инициализации
		}
	}

	if (getRandomNum(0, 1000) > 500)
	{
		//первый ходит человек
		g.human = CROSS;
		g.ai = ZERO;
		g.turn = 0;
	}
	else
	{
		//первый ходит ПК
		g.human = CROSS;
		g.ai = ZERO;
		g.turn = 1;
	}
}

void __fastcall deinitGame(TGame& g)
{
	for (size_t i = 0; i < g.SIZE; i++)
	{
		delete[] g.ppField[i]; //строки игрового поля
	}
	delete[] g.ppField; //столбец указателей
	g.ppField = nullptr;
}

void __fastcall printGame(TGame& g)
{
	cout << "     ";
	for (size_t x = 0; x < g.SIZE; x++)
		cout << x + 1 << "   ";

	cout << endl;

	for (size_t y = 0; y < g.SIZE; y++)
	{
		cout << " " << y + 1 << " | ";
		for (size_t x = 0; x < g.SIZE; x++)
		{
			cout << g.ppField[y][x] << " | ";
		}
		cout << endl;
	}

	cout << endl << " Human: " << g.human << endl << " Computer: " << g.ai << endl;
}

TProgress __fastcall getWon(TGame& g) //выйгрыш пк или человека
{
	//проверка строк
	for (size_t y = 0; y < g.SIZE; y++)
	{
		if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
		{
			if (g.ppField[y][0] == g.human)
				return WON_HUMAN;

			if (g.ppField[y][0] == g.ai)
				return WON_AI;
		}
	}

	//проверка столбцов
	for (size_t x = 0; x < g.SIZE; x++)
	{
		if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
		{
			if (g.ppField[0][x] == g.human)
				return WON_HUMAN;

			if (g.ppField[0][x] == g.ai)
				return WON_AI;
		}
	}

	//проверка диагонали
	if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
	{
		if (g.ppField[1][1] == g.human)
			return WON_HUMAN;

		if (g.ppField[1][1] == g.ai)
			return WON_AI;
	}
	if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[0][2] == g.ppField[1][1])
	{
		if (g.ppField[1][1] == g.human)
			return WON_HUMAN;

		if (g.ppField[1][1] == g.ai)
			return WON_AI;
	}

	//проверка на ничью
	bool draw = true;
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMPTY)
			{
				draw = false;
				break;
			}
		}
		if (!draw)
			return DRAW;

		return IN_PROGRESS;

	}

}

TCoord __fastcall getHumanCoord(TGame& g)//ходит человек
{
	TCoord c;
	do
	{
		cout << "Enter x (1 ...3): ";
		cin >> c.x;
		cout << "Enter y (1 ...3): ";
		cin >> c.y;
		c.x--;
		c.y--;

	} while (c.x > 2 || c.y >2 || g.ppField[c.y][c.x] !=EMPTY);

	return c;
}

TCoord __fastcall getAICoord(TGame& g)//ходит ПК
{
	// 1. Проверка выйгрыша
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMPTY)
			{
				g.ppField[y][x] = g.ai;
				if (getWon(g) == WON_AI)
				{
					g.ppField[y][x] = EMPTY;
					return { y, x };
				}
				g.ppField[y][x] = EMPTY;
			}
		}
	}

	// 2. Проверка проигрыша
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMPTY)
			{
				g.ppField[y][x] = g.human;
				if (getWon(g) == WON_HUMAN)
				{
					g.ppField[y][x] = EMPTY;
					return { y, x };
				}
				g.ppField[y][x] = EMPTY;
			}
		}
	}
	// 3. По приоритетам + рандом

	//центр
	if (g.ppField[1][1] == EMPTY)
		return { 1, 1 };


	// углы
	TCoord buf[4];
	size_t num{ 0 };
	if (g.ppField[0][0] == EMPTY)
	{
		buf[num] = { 0, 0 };
		num++;
	}
	if (g.ppField[2][2] == EMPTY)
	{
		buf[num] = { 2, 2 };
		num++;
	}
	if (g.ppField[0][2] == EMPTY)
	{
		buf[num] = { 0, 2 };
		num++;
	}
	if (g.ppField[2][0] == EMPTY)
	{
		buf[num] = { 2, 0 };
		num++;
	}
	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num; //0 .. num-1
		return buf[index]; //возвращаем случайный угол
	}

	// не углы
	if (g.ppField[0][1] == EMPTY)
	{
		buf[num] = { 0, 1 };
		num++;
	}
	if (g.ppField[2][1] == EMPTY)
	{
		buf[num] = { 2, 1 };
		num++;
	}
	if (g.ppField[1][0] == EMPTY)
	{
		buf[num] = { 1, 0 };
		num++;
	}
	if (g.ppField[1][2] == EMPTY)
	{
		buf[num] = { 1, 2 };
		num++;
	}
	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num; //0 .. num-1
		return buf[index]; //возвращаем случайный не угол
	}

	return { 1, 1 };
}

void __fastcall congrats(TGame& g)
{
	if (g.progress == WON_HUMAN)
		cout << " Human won! =)" << endl;
	else if (g.progress == WON_AI)
		cout << " PC won! =(" << endl;
	else if (g.progress == DRAW)
		cout << " Draw! *_*" << endl;

}

//====================================================================================================================================================================

int main()
{
	TGame g;
	initGame(g);

	clearScr();
	printGame(g);

	do
	{
		if (g.turn % 2 == 0)
		{
			//ходит человек
			TCoord c = getHumanCoord(g);
			g.ppField[c.y][c.x] = g.human;

		}
		else
		{
			//ходит ПК
			TCoord c = getAICoord(g);
			g.ppField[c.y][c.x] = g.ai;

		}

		clearScr();
		printGame(g);
		g.turn++;
		g.progress = getWon(g); //выйгрыш пк или человека


	} while (g.progress == IN_PROGRESS);

	congrats(g);
	deinitGame(g);
	return 0;
}


