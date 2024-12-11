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

matrix::matrix(int n)
{
	alokuj(n);
	*dlug = n;
}

matrix::matrix(int n, int* t)
{
	alokuj(n);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mac[i][j] = t[(i*n) + j];
		}
	}
	*dlug = n;
}

matrix::matrix(matrix& m)
{
	alokuj(*m.dlug);

	for (int i = 0; i < *m.dlug; i++) {
		for (int j = 0; j < *m.dlug; j++) {
			mac[i][j] = m.mac[i][j];
		}
	}
}

matrix::~matrix(void)
{
	if (mac != nullptr)
	{
		for (int i = 0; i < *dlug; i++)
		{
			delete[] mac[i];
		}
		delete[] mac;
	}
}

