/**
 * @file class.cpp
 * @brief Implementacja klasy matrix.
 */

#include "class.h"
#include <iostream>
#include <ostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Konstruktor domyślny klasy matrix.
 */
matrix::matrix(void)
{
    mac = nullptr;
    dlug = nullptr;
}

/**
 * @brief Konstruktor klasy matrix, który alokuje macierz o rozmiarze n x n.
 * @param n Rozmiar macierzy.
 */
matrix::matrix(int n)
{
    alokuj(n);
    *dlug = n;
}

/**
 * @brief Konstruktor klasy matrix, który alokuje macierz o rozmiarze n x n i wypełnia ją wartościami z tablicy t.
 * @param n Rozmiar macierzy.
 * @param t Tablica wartości do wypełnienia macierzy.
 */
matrix::matrix(int n, int* t)
{
    alokuj(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mac[i][j] = t[(i * n) + j];
        }
    }
    *dlug = n;
}

/**
 * @brief Konstruktor kopiujący klasy matrix.
 * @param m Obiekt matrix, który ma zostać skopiowany.
 */
matrix::matrix(matrix& m)
{
    alokuj(*m.dlug);
    for (int i = 0; i < *m.dlug; i++) {
        for (int j = 0; j < *m.dlug; j++) {
            mac[i][j] = m.mac[i][j];
        }
    }
}

/**
 * @brief Destruktor klasy matrix.
 */
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

/**
 * @brief Alokuje pamięć dla macierzy o rozmiarze n x n.
 * @param n Rozmiar macierzy.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Wstawia wartość do macierzy w określonej pozycji.
 * @param x Wiersz.
 * @param y Kolumna.
 * @param wartosc Wartość do wstawienia.
 * @return Referencja do obiektu matrix.
 */
matrix& matrix::wstaw(int x, int y, int wartosc)
{
    mac[x][y] = wartosc;
    return *this;
}

/**
 * @brief Zwraca wartość z macierzy z określonej pozycji.
 * @param x Wiersz.
 * @param y Kolumna.
 * @return Wartość z macierzy.
 */
int matrix::pokaz(int x, int y)
{
    return mac[x][y];
}

/**
 * @brief Odwraca macierz (transpozycja).
 * @return Referencja do obiektu matrix.
 */
matrix& matrix::dowroc(void)
{
    for (int i = 0; i < *dlug; i++) {
        for (int j = i + 1; j < *dlug; j++) {
            swap(mac[i][j], mac[j][i]);
        }
    }
    return *this;
}

/**
 * @brief Wypełnia macierz losowymi wartościami.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Wypełnia macierz losowymi wartościami w określonej liczbie komórek.
 * @param x Liczba komórek do wypełnienia.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Ustawia wartości na przekątnej macierzy.
 * @param t Tablica wartości do ustawienia na przekątnej.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Ustawia wartości na przekątnej macierzy z przesunięciem.
 * @param k Przesunięcie przekątnej.
 * @param t Tablica wartości do ustawienia na przekątnej.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Ustawia wartości w kolumnie macierzy.
 * @param x Numer kolumny.
 * @param t Tablica wartości do ustawienia w kolumnie.
 * @return Referencja do obiektu matrix.
 */
matrix& matrix::kolumna(int x, int* t)
{
    for (int i = 0; i < *dlug; i++)
    {
        mac[i][x] = t[i];
    }
    return *this;
}

/**
 * @brief Ustawia wartości w wierszu macierzy.
 * @param y Numer wiersza.
 * @param t Tablica wartości do ustawienia w wierszu.
 * @return Referencja do obiektu matrix.
 */
matrix& matrix::wiersz(int y, int* t)
{
    for (int i = 0; i < *dlug; i++)
    {
        mac[y][i] = t[i];
    }
    return *this;
}

/**
 * @brief Ustawia wartości na przekątnej macierzy na 1, a pozostałe na 0.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Ustawia wartości pod przekątną macierzy na 1, a pozostałe na 0.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Ustawia wartości nad przekątną macierzy na 1, a pozostałe na 0.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Ustawia wartości w macierzy w formie szachownicy.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator dodawania macierzy.
 * @param m Macierz do dodania.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator mnożenia macierzy.
 * @param m Macierz do pomnożenia.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator dodawania liczby do macierzy.
 * @param a Liczba do dodania.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator mnożenia macierzy przez liczbę.
 * @param a Liczba do pomnożenia.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator odejmowania liczby od macierzy.
 * @param a Liczba do odjęcia.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator dodawania liczby do macierzy (globalny).
 * @param a Liczba do dodania.
 * @param m Macierz.
 * @return Nowa macierz będąca wynikiem dodawania.
 */
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

/**
 * @brief Operator mnożenia liczby przez macierz (globalny).
 * @param a Liczba do pomnożenia.
 * @param m Macierz.
 * @return Nowa macierz będąca wynikiem mnożenia.
 */
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

/**
 * @brief Operator odejmowania liczby od macierzy (globalny).
 * @param a Liczba do odjęcia.
 * @param m Macierz.
 * @return Nowa macierz będąca wynikiem odejmowania.
 */
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

/**
 * @brief Operator inkrementacji macierzy.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator dekrementacji macierzy.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator dodawania liczby do macierzy.
 * @param a Liczba do dodania.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator odejmowania liczby od macierzy.
 * @param a Liczba do odjęcia.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator mnożenia macierzy przez liczbę.
 * @param a Liczba do pomnożenia.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator dodawania liczby do macierzy.
 * @param value Wartość do dodania.
 * @return Referencja do obiektu matrix.
 */
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

/**
 * @brief Operator wyjścia strumienia dla obiektu matrix.
 * @param o Strumień wyjściowy.
 * @param m Obiekt matrix do wyświetlenia.
 * @return Strumień wyjściowy.
 */
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

/**
 * @brief Operator porównania równości macierzy.
 * @param m Macierz do porównania.
 * @return true jeśli macierze są równe, false w przeciwnym razie.
 */
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

/**
 * @brief Operator porównania większości macierzy.
 * @param m Macierz do porównania.
 * @return true jeśli bieżąca macierz jest większa, false w przeciwnym razie.
 */
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

/**
 * @brief Operator porównania mniejszości macierzy.
 * @param m Macierz do porównania.
 * @return true jeśli bieżąca macierz jest mniejsza, false w przeciwnym razie.
 */
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

