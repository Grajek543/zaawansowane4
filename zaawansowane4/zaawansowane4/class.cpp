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

