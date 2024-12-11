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

matrix& matrix::alokuj(int n)
{
	if (mac != nullptr) {
		if (*dlug < n) {
			for (int i = 0; i < *dlug; i++) {
				delete[] mac[i];
			}
			delete[] mac;
			delete dlug;
		}
	}

	mac = new int* [n];
	for (int i = 0; i < n; i++) {
		mac[i] = new int[n];
	}

	dlug = new int(n);

	*dlug = n;
	return *this;
}

matrix& matrix::wstaw(int x, int y, int wartosc)
{
	mac[x][y] = wartosc;
	return *this;
}

int matrix::pokaz(int x, int y)
{
	return mac[x][y];
}

matrix& matrix::dowroc(void)
{
	for (int i = 0; i < *dlug; i++) {
		for (int j = i + 1; j < *dlug; j++) {
			swap(mac[i][j], mac[j][i]);
		}
	}
	return *this;
}

