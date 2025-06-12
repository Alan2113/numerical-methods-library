#include "biblioteka_numeryczna.h"
#include <iostream>
#include <cmath>

// Funkcja demonstracyjna - BEZ main()
void demonstracjaBisekcji() {
    std::cout << "Demonstracja metody bisekcji" << std::endl;

    auto f = [](double x) { return x * x - 4; };
    double wynik = BibliotekaNumeryczna::metodaBisekcji(f, 0, 3, 0.001);
    std::cout << "Pierwiastek: " << wynik << std::endl;
}
