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

matrix& matrix::przekatna(void)
{
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			if (i != j)
			{
				mac[i][j] = 0;
			}
			else {
				mac[i][j] = 1;
			}
		}
	}
	return *this;
}

matrix& matrix::pod_przekatna(void)
{
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			if (i > j)
			{
				mac[i][j] = 1;
			}
			else {
				mac[i][j] = 0;
			}
		}
	}
	return *this;
}

matrix& matrix::nad_przekatna(void)
{
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			if (i < j)
			{
				mac[i][j] = 1;
			}
			else {
				mac[i][j] = 0;
			}
		}
	}
	return *this;
}

matrix& matrix::szachownica(void)
{
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			if ((i + j) % 2 != 0)
			{
				mac[i][j] = 1;
			}
			else {
				mac[i][j] = 0;
			}
		}
	}
	return *this;
}

matrix& matrix::operator+(matrix& m)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] + m.mac[i][j];
		}
	}
	*this = *temp;
	return *this;
}

matrix& matrix::operator*(matrix& m)
{
	if (*dlug != *m.dlug)
	{
		cout << "Macierze posiadaja rozne dlugosci" << endl;
		return *this;
	}
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = 0;
			for (int k = 0; k < *dlug; k++)
			{
				temp->mac[i][j] += (mac[i][j] * m.mac[i][k]);
			}
		}
	}
	*this = *temp;
	return *this;
}