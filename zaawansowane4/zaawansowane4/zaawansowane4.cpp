#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream mac;
    mac.open("mac.txt", std::ios::out | std::ios::trunc);
    if (!mac.is_open()) {
        std::cout << "Nie ma dostepu do pliku PRE.txt" << std::endl;
        return;
    }


    mac.close();
}