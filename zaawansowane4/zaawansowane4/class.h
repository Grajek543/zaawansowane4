#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class matrix {
private:
	int** mac;
public:
	matrix(void);
	matrix(int n);
	matrix(int n, int* t);
	matrix(matrix& m);
	~matrix(void);
	matrix& alokuj(int n);
	matrix& wstaw(int x, int y, int wartosc);
	int pokaz(int x, int y);
	matrix& dowroc(void);
	matrix& losuj(void);
	matrix& losuj(int x);
	matrix& diagonalna(int* t);
	matrix& diagonalna_k(int k, int* t);
	matrix& kolumna(int x, int* t);
	matrix& wiersz(int y, int* t);
	matrix& przekatna(void);
	matrix& pod_przekatna(void);
	matrix& nad_przekatna(void);
	matrix& szachownica(void);
	matrix& operator+(matrix& m);
	matrix& operator*(matrix& m);
	matrix& operator+(int a);
	matrix& operator*(int a);
	matrix& operator-(int a);
	friend matrix operator+(int a, matrix& m);
	friend matrix operator*(int a, matrix& m);
	friend matrix operator-(int a, matrix& m);
	matrix& operator++(int);
	matrix& operator--(int);
	matrix& operator+=(int a);
	matrix& operator-=(int a);
	matrix& operator*=(int a);
	matrix& operator()(double);
	friend ostream& operator<<(ostream& o, matrix& m);
	bool operator==(const matrix& m);
	bool operator>(const matrix& m);
	bool operator<(const matrix& m);
};