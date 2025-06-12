#include "biblioteka_numeryczna.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <iomanip>

void testujMetodeNajmniejszychKwadratow() {
    std::cout << "=== TESTOWANIE METODY NAJMNIEJSZYCH KWADRATÓW ===" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Test 1: Prosta y = 2x + 1
    std::cout << "\nTest 1: Aproksymacja prostej y = 2x + 1" << std::endl;
    std::vector<double> x1 = { 0, 1, 2, 3, 4 };
    std::vector<double> y1 = { 1, 3, 5, 7, 9 }; // Dok³adnie na prostej

    auto wynik1 = BibliotekaNumeryczna::metodaNajmniejszychKwadratow(x1, y1);
    std::cout << "Równanie: y = " << wynik1.a << "x + " << wynik1.b << std::endl;
    std::cout << "R? = " << wynik1.r2 << std::endl;

    assert(std::abs(wynik1.a - 2.0) < 0.001);
    assert(std::abs(wynik1.b - 1.0) < 0.001);
    assert(wynik1.r2 > 0.99);
    std::cout << "? Test 1 przeszed³ pomyœlnie!" << std::endl;

    std::cout << "\n=== WSZYSTKIE TESTY METODY NAJMNIEJSZYCH KWADRATÓW PRZESZ£Y! ===" << std::endl;
}
