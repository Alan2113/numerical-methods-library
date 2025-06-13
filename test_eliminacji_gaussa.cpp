#include "biblioteka_numeryczna.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <iomanip>

void testujEliminacjeGaussa() {
    std::cout << "=== TESTOWANIE ELIMINACJI GAUSSA ===" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Test 1: Prosty uklad 2x2
    std::cout << "\nTest 1: Uklad 2x2" << std::endl;
    std::cout << "2x + 3y = 7" << std::endl;
    std::cout << "x - y = 1" << std::endl;

    std::vector<std::vector<double>> A1 = { {2, 3}, {1, -1} };
    std::vector<double> b1 = { 7, 1 };

    auto rozwiazanie1 = BibliotekaNumeryczna::eliminacjaGaussa(A1, b1);
    std::cout << "Rozwiazanie: x = " << rozwiazanie1[0] << ", y = " << rozwiazanie1[1] << std::endl;

    // Sprawdzenie: x = 2, y = 1
    assert(std::abs(rozwiazanie1[0] - 2.0) < 0.001);
    assert(std::abs(rozwiazanie1[1] - 1.0) < 0.001);
    std::cout << "Test 1 przeszedl pomyslnie!" << std::endl;

    // Test 2: Uklad 3x3
    std::cout << "\nTest 2: Uklad 3x3" << std::endl;
    std::cout << "x + y + z = 9" << std::endl;
    std::cout << "2x - 3y + 4z = 13" << std::endl;
    std::cout << "3x + 4y + 5z = 40" << std::endl;

    std::vector<std::vector<double>> A2 = {
        {1, 1, 1},
        {2, -3, 4},
        {3, 4, 5}
    };
    std::vector<double> b2 = { 9, 13, 40 };

    auto rozwiazanie2 = BibliotekaNumeryczna::eliminacjaGaussa(A2, b2);
    std::cout << "Rozwiazanie: x = " << rozwiazanie2[0]
        << ", y = " << rozwiazanie2[1]
        << ", z = " << rozwiazanie2[2] << std::endl;

    // Sprawdzenie: x = 1, y = 3, z = 5
    assert(std::abs(rozwiazanie2[0] - 1.0) < 0.001);
    assert(std::abs(rozwiazanie2[1] - 3.0) < 0.001);
    assert(std::abs(rozwiazanie2[2] - 5.0) < 0.001);
    std::cout << "Test 2 przeszedl pomyslnie!" << std::endl;

    // Test 3: Weryfikacja rozwiazania
    std::cout << "\nTest 3: Weryfikacja rozwiazania" << std::endl;
    double sprawdzenie1 = A2[0][0] * rozwiazanie2[0] + A2[0][1] * rozwiazanie2[1] + A2[0][2] * rozwiazanie2[2];
    double sprawdzenie2 = A2[1][0] * rozwiazanie2[0] + A2[1][1] * rozwiazanie2[1] + A2[1][2] * rozwiazanie2[2];
    double sprawdzenie3 = A2[2][0] * rozwiazanie2[0] + A2[2][1] * rozwiazanie2[1] + A2[2][2] * rozwiazanie2[2];

    std::cout << "Sprawdzenie rownan:" << std::endl;
    std::cout << "Rownanie 1: " << sprawdzenie1 << " = " << b2[0] << std::endl;
    std::cout << "Rownanie 2: " << sprawdzenie2 << " = " << b2[1] << std::endl;
    std::cout << "Rownanie 3: " << sprawdzenie3 << " = " << b2[2] << std::endl;

    assert(std::abs(sprawdzenie1 - b2[0]) < 0.001);
    assert(std::abs(sprawdzenie2 - b2[1]) < 0.001);
    assert(std::abs(sprawdzenie3 - b2[2]) < 0.001);
    std::cout << "Test 3 przeszedl pomyslnie!" << std::endl;

    std::cout << "\n=== WSZYSTKIE TESTY ELIMINACJI GAUSSA PRZESZLY! ===" << std::endl;
}
