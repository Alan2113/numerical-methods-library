#include "biblioteka_numeryczna.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>

void testujMetodeBisekcji() {
    std::cout << "=== TESTOWANIE METODY BISEKCJI ===" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Test 1: f(x) = x^2 - 4, pierwiastek x = 2 w przedziale [0, 3]
    std::cout << "\nTest 1: f(x) = x^2 - 4" << std::endl;
    auto f1 = [](double x) { return x * x - 4; };
    double pierwiastek1 = BibliotekaNumeryczna::metodaBisekcji(f1, 0, 3, 0.00001);
    std::cout << "Pierwiastek: " << pierwiastek1 << std::endl;
    std::cout << "Sprawdzenie f(" << pierwiastek1 << ") = " << f1(pierwiastek1) << std::endl;
    assert(std::abs(pierwiastek1 - 2.0) < 0.001);
    std::cout << "Test 1 przeszedl pomyslnie!" << std::endl;

    // Test 2: f(x) = x^3 - x - 1, pierwiastek okolo 1.324718
    std::cout << "\nTest 2: f(x) = x^3 - x - 1" << std::endl;
    auto f2 = [](double x) { return x * x * x - x - 1; };
    double pierwiastek2 = BibliotekaNumeryczna::metodaBisekcji(f2, 1, 2, 0.000001);
    std::cout << "Pierwiastek: " << pierwiastek2 << std::endl;
    std::cout << "Sprawdzenie f(" << pierwiastek2 << ") = " << f2(pierwiastek2) << std::endl;
    assert(std::abs(pierwiastek2 - 1.324718) < 0.001);
    std::cout << "Test 2 przeszedl pomyslnie!" << std::endl;

    // Test 3: f(x) = x - exp(-x), pierwiastek okolo 0.567143
    std::cout << "\nTest 3: f(x) = x - e^(-x)" << std::endl;
    auto f3 = [](double x) { return x - exp(-x); };
    double pierwiastek3 = BibliotekaNumeryczna::metodaBisekcji(f3, 0, 1, 0.000001);
    std::cout << "Pierwiastek: " << pierwiastek3 << std::endl;
    std::cout << "Sprawdzenie f(" << pierwiastek3 << ") = " << f3(pierwiastek3) << std::endl;
    assert(std::abs(pierwiastek3 - 0.567143) < 0.001);
    std::cout << "Test 3 przeszedl pomyslnie!" << std::endl;

    // Test 4: f(x) = cos(x) - x, pierwiastek okolo 0.739085
    std::cout << "\nTest 4: f(x) = cos(x) - x" << std::endl;
    auto f4 = [](double x) { return cos(x) - x; };
    double pierwiastek4 = BibliotekaNumeryczna::metodaBisekcji(f4, 0, 1.5, 0.000001);
    std::cout << "Pierwiastek: " << pierwiastek4 << std::endl;
    std::cout << "Sprawdzenie f(" << pierwiastek4 << ") = " << f4(pierwiastek4) << std::endl;
    assert(std::abs(pierwiastek4 - 0.739085) < 0.001);
    std::cout << "Test 4 przeszedl pomyslnie!" << std::endl;

    // Test 5: Test obslugi bledow - funkcja nie zmienia znaku
    std::cout << "\nTest 5: Obsluga bledow" << std::endl;
    auto f5 = [](double x) { return x * x + 1; }; // Brak pierwiastkow rzeczywistych
    try {
        BibliotekaNumeryczna::metodaBisekcji(f5, 0, 2, 0.001);
        std::cout << "Test 5 nie przeszedl - powinien rzucic wyjatek!" << std::endl;
        assert(false);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Test 5 przeszedl pomyslnie - poprawnie rzucony wyjatek: " << e.what() << std::endl;
    }

    std::cout << "\n=== WSZYSTKIE TESTY PRZESZLY POMYSLNIE! ===" << std::endl;
}
