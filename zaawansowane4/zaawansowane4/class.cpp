#include "class.h"
#include <iostream>
#include <ostream>
#include <ctime>
#include <cstdlib>
using namespace std;

matrix::matrix(void)
{
	mac = nullptr;
	dlug = nullptr;
}

matrix& matrix::kolumna(int x, int* t)
{
	for (int i = 0; i < *dlug; i++)
	{
		mac[i][x] = t[i];
	}
	return *this;
}

matrix& matrix::wiersz(int y, int* t)
{
	for (int i = 0; i < *dlug; i++)
	{
		mac[y][i] = t[i];
	}
	return *this;
}