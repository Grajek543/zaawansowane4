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

matrix operator*(int a, matrix& m)
{
	matrix* temp = new matrix(*m.dlug);
	for (int i = 0; i < *m.dlug; i++)
	{
		for (int j = 0; j < *m.dlug; j++)
		{
			temp->mac[i][j] = a * m.mac[i][j];
		}
	}
	return *temp;
}

matrix operator-(int a, matrix& m)
{
	matrix* temp = new matrix(*m.dlug);
	for (int i = 0; i < *m.dlug; i++)
	{
		for (int j = 0; j < *m.dlug; j++)
		{
			temp->mac[i][j] = a - m.mac[i][j];
		}
	}
	return *temp;
}

matrix& matrix::operator++(int)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] + 1;
		}
	}
	*this = *temp;
	return *this;
}

matrix& matrix::operator--(int)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] - 1;
		}
	}
	*this = *temp;
	return *this;
}