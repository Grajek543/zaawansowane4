#include "class.h"
#include <iostream>
#include <ostream>
using namespace std;

matrix::matrix(void)
{
	mac = NULL;
}

matrix::matrix(int n)
{
	alokuj(n);
}

matrix::matrix(int n, int* t)
{
	alokuj(n);
	for (int i = 0; i < n; i++)
	{
		mac[i][0] = t[i];
	}
}

matrix::matrix(matrix& m)
{
	alokuj(m.mac[0][0]);
	for (int i = 0; i < m.mac[0][0]; i++)
	{
		for (int j = 0; j < m.mac[0][0]; j++)
		{
			mac[i][j] = m.mac[i][j];
		}
	}
}

matrix::~matrix(void)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			delete[] mac[i];
		}
		delete[] mac;
	}
}

matrix& matrix::alokuj(int n)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			delete[] mac[i];
		}
		delete[] mac;
	}
	mac = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mac[i] = new int[n];
	}
	mac[0][0] = n;
	return *this;
}

matrix& matrix::wstaw(int x, int y, int wartosc)
{
	if (mac != NULL)
	{
		mac[x][y] = wartosc;
	}
	return *this;
}

matrix& matrix::dowroc(void)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j] = -mac[i][j];
			}
		}
	}
	return *this;
}

matrix& matrix::losuj(void)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j] = rand() % 100;
			}
		}
	}
	return *this;
}

matrix& matrix::losuj(int x)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j] = rand() % x;
			}
		}
	}
	return *this;
}

matrix& matrix::diagonalna(int* t)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if (i == j)
				{
					mac[i][j] = t[i];
				}
				else
				{
					mac[i][j] = 0;
				}
			}
		}
	}
	return *this;
}

matrix& matrix::diagonalna_k(int k, int* t)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if (i == j + k)
				{
					mac[i][j] = t[i];
				}
				else
				{
					mac[i][j] = 0;
				}
			}
		}
	}
	return *this;
}

matrix& matrix::kolumna(int x, int* t)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			mac[i][x] = t[i];
		}
	}
	return *this;
}

matrix& matrix::wiersz(int y, int* t)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			mac[y][i] = t[i];
		}
	}
	return *this;
}

matrix& matrix::przekatna(void)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if (i == j)
				{
					mac[i][j] = 1;
				}
				else
				{
					mac[i][j] = 0;
				}
			}
		}
	}
	return *this;
}

matrix& matrix::pod_przekatna(void)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if (i > j)
				{
					mac[i][j] = 1;
				}
				else
				{
					mac[i][j] = 0;
				}
			}
		}
	}
	return *this;
}

matrix& matrix::nad_przekatna(void)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if (i < j)
				{
					mac[i][j] = 1;
				}
				else
				{
					mac[i][j] = 0;
				}
			}
		}
	}
	return *this;
}

matrix& matrix::szachownica(void)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if ((i + j) % 2 == 0)
				{
					mac[i][j] = 1;
				}
				else
				{
					mac[i][j] = 0;
				}
			}
		}
	}
	return *this;
}

matrix& matrix::operator+(matrix& m)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j] += m.mac[i][j];
			}
		}
	}
	return *this;
}

matrix& matrix::operator*(matrix& m)
{
	if (mac != NULL)
	{
		matrix temp(mac[0][0]);
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				for (int k = 0; k < mac[0][0]; k++)
				{
					temp.mac[i][j] += mac[i][k] * m.mac[k][j];
				}
			}
		}
		*this = temp;
	}
	return *this;
}

matrix& matrix::operator+(int a)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j] += a;
			}
		}
	}
	return *this;
}

matrix& matrix::operator*(int a)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j] *= a;
			}
		}
	}
	return *this;
}

matrix& matrix::operator-(int a)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j] -= a;
			}
		}
	}
	return *this;
}
matrix operator+(int a, matrix& m)
{
	if (m.mac != NULL)
	{
		for (int i = 0; i < m.mac[0][0]; i++)
		{
			for (int j = 0; j < m.mac[0][0]; j++)
			{
				m.mac[i][j] += a;
			}
		}
	}
	return m;
}
matrix operator*(int a, matrix& m)
{
	if (m.mac != NULL)
	{
		for (int i = 0; i < m.mac[0][0]; i++)
		{
			for (int j = 0; j < m.mac[0][0]; j++)
			{
				m.mac[i][j] *= a;
			}
		}
	}
	return m;
}
matrix operator-(int a, matrix& m)
{
	if (m.mac != NULL)
	{
		for (int i = 0; i < m.mac[0][0]; i++)
		{
			for (int j = 0; j < m.mac[0][0]; j++)
			{
				m.mac[i][j] = a - m.mac[i][j];
			}
		}
	}
	return m;
}
matrix& matrix::operator++(int)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j]++;
			}
		}
	}
	return *this;
}
matrix& matrix::operator--(int)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j]--;
			}
		}
	}
	return *this;
}
matrix& matrix::operator+=(int a)
{
	if (mac != NULL)
	{
		*this = *this + a;
	}
	return *this;
}
matrix& matrix::operator-=(int a)
{
	if (mac != NULL)
	{
		*this = *this - a;
	}
	return *this;
}
matrix& matrix::operator*=(int a)
{
	if (mac != NULL)
	{
		*this = *this * a;
	}
	return *this;
}
matrix& matrix::operator()(double value)
{
	if (mac != NULL)
	{
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				mac[i][j] = value;
			}
		}
	}
	return *this;
}
ostream& operator<<(ostream& o, matrix& m)
{
	if (m.mac != NULL)
	{
		for (int i = 0; i < m.mac[0][0]; i++)
		{
			for (int j = 0; j < m.mac[0][0]; j++)
			{
				o << m.mac[i][j] << " ";
			}
			o << endl;
		}
	}
	return o;
}
bool matrix::operator==(const matrix& m)
{
	if (mac != NULL && m.mac != NULL)
	{
		if (mac[0][0] != m.mac[0][0])
		{
			return false;
		}
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if (mac[i][j] != m.mac[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
bool matrix::operator>(const matrix& m)
{
	if (mac != NULL && m.mac != NULL)
	{
		if (mac[0][0] != m.mac[0][0])
		{
			return false;
		}
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if (mac[i][j] <= m.mac[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
bool matrix::operator<(const matrix& m)
{
	if (mac != NULL && m.mac != NULL)
	{
		if (mac[0][0] != m.mac[0][0])
		{
			return false;
		}
		for (int i = 0; i < mac[0][0]; i++)
		{
			for (int j = 0; j < mac[0][0]; j++)
			{
				if (mac[i][j] >= m.mac[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
