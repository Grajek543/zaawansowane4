#pragma once
#include <iostream>
#include <ostream>
using namespace std;

/**
 * @class matrix
 * @brief Klasa reprezentuj¹ca macierz kwadratow¹.
 */
class matrix {
private:
    int* dlug; ///< WskaŸnik na d³ugoœæ macierzy.
    int** mac; ///< WskaŸnik na tablicê wskaŸników reprezentuj¹cych macierz.

public:
    /**
     * @brief Konstruktor domyœlny klasy matrix.
     */
    matrix(void);

    /**
     * @brief Konstruktor klasy matrix, który alokuje macierz o rozmiarze n x n.
     * @param n Rozmiar macierzy.
     */
    matrix(int n);

    /**
     * @brief Konstruktor klasy matrix, który alokuje macierz o rozmiarze n x n i wype³nia j¹ wartoœciami z tablicy t.
     * @param n Rozmiar macierzy.
     * @param t Tablica wartoœci do wype³nienia macierzy.
     */
    matrix(int n, int* t);

    /**
     * @brief Konstruktor kopiuj¹cy klasy matrix.
     * @param m Obiekt matrix, który ma zostaæ skopiowany.
     */
    matrix(matrix& m);

    /**
     * @brief Destruktor klasy matrix.
     */
    ~matrix(void);

    /**
     * @brief Alokuje pamiêæ dla macierzy o rozmiarze n x n.
     * @param n Rozmiar macierzy.
     * @return Referencja do obiektu matrix.
     */
    matrix& alokuj(int n);

    /**
     * @brief Wstawia wartoœæ do macierzy w okreœlonej pozycji.
     * @param x Wiersz.
     * @param y Kolumna.
     * @param wartosc Wartoœæ do wstawienia.
     * @return Referencja do obiektu matrix.
     */
    matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Zwraca wartoœæ z macierzy z okreœlonej pozycji.
     * @param x Wiersz.
     * @param y Kolumna.
     * @return Wartoœæ z macierzy.
     */
    int pokaz(int x, int y);

    /**
     * @brief Odwraca macierz (transpozycja).
     * @return Referencja do obiektu matrix.
     */
    matrix& dowroc(void);

    /**
     * @brief Wype³nia macierz losowymi wartoœciami.
     * @return Referencja do obiektu matrix.
     */
    matrix& losuj(void);

    /**
     * @brief Wype³nia macierz losowymi wartoœciami w okreœlonej liczbie komórek.
     * @param x Liczba komórek do wype³nienia.
     * @return Referencja do obiektu matrix.
     */
    matrix& losuj(int x);

    /**
     * @brief Ustawia wartoœci na przek¹tnej macierzy.
     * @param t Tablica wartoœci do ustawienia na przek¹tnej.
     * @return Referencja do obiektu matrix.
     */
    matrix& diagonalna(int* t);

    /**
     * @brief Ustawia wartoœci na przek¹tnej macierzy z przesuniêciem.
     * @param k Przesuniêcie przek¹tnej.
     * @param t Tablica wartoœci do ustawienia na przek¹tnej.
     * @return Referencja do obiektu matrix.
     */
    matrix& diagonalna_k(int k, int* t);

    /**
     * @brief Ustawia wartoœci w kolumnie macierzy.
     * @param x Numer kolumny.
     * @param t Tablica wartoœci do ustawienia w kolumnie.
     * @return Referencja do obiektu matrix.
     */
    matrix& kolumna(int x, int* t);

    /**
     * @brief Ustawia wartoœci w wierszu macierzy.
     * @param y Numer wiersza.
     * @param t Tablica wartoœci do ustawienia w wierszu.
     * @return Referencja do obiektu matrix.
     */
    matrix& wiersz(int y, int* t);

    /**
     * @brief Ustawia wartoœci na przek¹tnej macierzy na 1, a pozosta³e na 0.
     * @return Referencja do obiektu matrix.
     */
    matrix& przekatna(void);

    /**
     * @brief Ustawia wartoœci pod przek¹tn¹ macierzy na 1, a pozosta³e na 0.
     * @return Referencja do obiektu matrix.
     */
    matrix& pod_przekatna(void);

    /**
     * @brief Ustawia wartoœci nad przek¹tn¹ macierzy na 1, a pozosta³e na 0.
     * @return Referencja do obiektu matrix.
     */
    matrix& nad_przekatna(void);

    /**
     * @brief Ustawia wartoœci w macierzy w formie szachownicy.
     * @return Referencja do obiektu matrix.
     */
    matrix& szachownica(void);

    /**
     * @brief Operator dodawania macierzy.
     * @param m Macierz do dodania.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator+(matrix& m);

    /**
     * @brief Operator mno¿enia macierzy.
     * @param m Macierz do pomno¿enia.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator*(matrix& m);

    /**
     * @brief Operator dodawania liczby do macierzy.
     * @param a Liczba do dodania.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator+(int a);

    /**
     * @brief Operator mno¿enia macierzy przez liczbê.
     * @param a Liczba do pomno¿enia.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator*(int a);

    /**
     * @brief Operator odejmowania liczby od macierzy.
     * @param a Liczba do odjêcia.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator-(int a);

    /**
     * @brief Operator dodawania liczby do macierzy (globalny).
     * @param a Liczba do dodania.
     * @param m Macierz.
     * @return Nowa macierz bêd¹ca wynikiem dodawania.
     */
    friend matrix operator+(int a, matrix& m);

    /**
     * @brief Operator mno¿enia liczby przez macierz (globalny).
     * @param a Liczba do pomno¿enia.
     * @param m Macierz.
     * @return Nowa macierz bêd¹ca wynikiem mno¿enia.
     */
    friend matrix operator*(int a, matrix& m);

    /**
     * @brief Operator odejmowania liczby od macierzy (globalny).
     * @param a Liczba do odjêcia.
     * @param m Macierz.
     * @return Nowa macierz bêd¹ca wynikiem odejmowania.
     */
    friend matrix operator-(int a, matrix& m);

    /**
     * @brief Operator inkrementacji macierzy.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator++(int);

    /**
     * @brief Operator dekrementacji macierzy.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator--(int);

    /**
     * @brief Operator dodawania liczby do macierzy.
     * @param a Liczba do dodania.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator+=(int a);

    /**
     * @brief Operator odejmowania liczby od macierzy.
     * @param a Liczba do odjêcia.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator-=(int a);

    /**
     * @brief Operator mno¿enia macierzy przez liczbê.
     * @param a Liczba do pomno¿enia.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator*=(int a);

    /**
     * @brief Operator dodawania liczby do macierzy.
     * @param value Wartoœæ do dodania.
     * @return Referencja do obiektu matrix.
     */
    matrix& operator()(double value);

    /**
     * @brief Operator wyjœcia strumienia dla obiektu matrix.
     * @param o Strumieñ wyjœciowy.
     * @param m Obiekt matrix do wyœwietlenia.
     * @return Strumieñ wyjœciowy.
     */
    friend ostream& operator<<(ostream& o, matrix& m);

    /**
     * @brief Operator porównania równoœci macierzy.
     * @param m Macierz do porównania.
     * @return true jeœli macierze s¹ równe, false w przeciwnym razie.
     */
    bool operator==(const matrix& m);

    /**
     * @brief Operator porównania wiêkszoœci macierzy.
     * @param m Macierz do porównania.
     * @return true jeœli bie¿¹ca macierz jest wiêksza, false w przeciwnym razie.
     */
    bool operator>(const matrix& m);

    /**
     * @brief Operator porównania mniejszoœci macierzy.
     * @param m Macierz do porównania.
     * @return true jeœli bie¿¹ca macierz jest mniejsza, false w przeciwnym razie.
     */
    bool operator<(const matrix& m);
};
