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
	// Alokowanie pamięci dla macierzy i długości
	alokuj(*m.dlug);

	// Kopiowanie zawartości macierzy
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
			// Usuwanie starej macierzy
			for (int i = 0; i < *dlug; i++) {
				delete[] mac[i];
			}
			delete[] mac;
			delete dlug;  // Usuwanie starego wskaźnika długości
		}
	}

	// Alokowanie pamięci na nową macierz
	mac = new int* [n];
	for (int i = 0; i < n; i++) {
		mac[i] = new int[n];
	}

	// Alokowanie pamięci na wskaźnik 'dlug'
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

matrix& matrix::losuj(void)
{
	srand(time(nullptr));

	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			mac[i][j] = rand() % 10;
		}
	}
	return *this;
}

matrix& matrix::losuj(int x)
{
	srand(time(nullptr));
	int t1;
	int t2;
	for (int i = 0; i < x; i++) {
		t1 = rand() % *dlug;
		t2 = rand() % *dlug;
		mac[t1][t2] = rand() % 10;
	}
	return *this;
}

matrix& matrix::diagonalna(int* t)
{
	for (int i = 0; i < *dlug; i++)
	{
		mac[i][i] = t[i];
	}
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			if (i != j)
			{
				mac[i][j] = 0;
			}
		}
	}
	return *this;
}

matrix& matrix::diagonalna_k(int k, int* t)
{
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			mac[i][j] = 0;
		}
	}
	if (k != 0) {
		if (k > 0)
		{
			for (int i = 0; i < *dlug - k; i++)
			{
				mac[i][i + k] = t[i + k];
			}
		}
		else {
			for (int i = 0; i < *dlug; i++)
			{
				mac[i][i + k] = t[i + k];
			}
		}
		
	}
	else {
		diagonalna(t);
	}
	return *this;
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

matrix& matrix::operator+(int a)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] + a;
		}
	}
	*this = *temp;
	return *this;
}

matrix& matrix::operator*(int a)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] * a;
		}
	}
	*this = *temp;
	return *this;
}

matrix& matrix::operator-(int a)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] - a;
		}
	}
	*this = *temp;
	return *this;
}

matrix operator+(int a, matrix& m)
{
	matrix* temp = new matrix(*m.dlug);
	for (int i = 0; i < *m.dlug; i++)
	{
		for (int j = 0; j < *m.dlug; j++)
		{
			temp->mac[i][j] = a + m.mac[i][j];
		}
	}
	return *temp;
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

matrix& matrix::operator+=(int a)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] + a;
		}
	}
	*this = *temp;
	return *this;
}

matrix& matrix::operator-=(int a)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] - a;
		}
	}
	*this = *temp;
	return *this;
}

matrix& matrix::operator*=(int a)
{
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] * a;
		}
	}
	*this = *temp;
	return *this;
}

matrix& matrix::operator()(double value)
{
	int intvalue = (int)value;
	matrix* temp = new matrix(*dlug);
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			temp->mac[i][j] = mac[i][j] + intvalue;
		}
	}
	*this = *temp;
	return *this;
}

ostream& operator<<(ostream& o, matrix& m)
{
	for (int i = 0; i < *m.dlug; i++)
	{
		for (int j = 0; j < *m.dlug; j++)
		{
			o << m.mac[i][j] << " ";
		}
		o << endl;
	}
	return o;
}

bool matrix::operator==(const matrix& m)
{
	if (*dlug != *m.dlug)
	{
		return false;
	}
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			if (mac[i][j] != m.mac[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool matrix::operator>(const matrix& m)
{
	if (*dlug != *m.dlug)
	{
		return false;
	}
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			if (mac[i][j] <= m.mac[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool matrix::operator<(const matrix& m)
{
	if (*dlug != *m.dlug)
	{
		return false;
	}
	for (int i = 0; i < *dlug; i++)
	{
		for (int j = 0; j < *dlug; j++)
		{
			if (mac[i][j] >= m.mac[i][j])
			{
				return false;
			}
		}
	}
	return true;
}