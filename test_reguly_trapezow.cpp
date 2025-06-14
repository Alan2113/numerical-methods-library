#include "biblioteka_numeryczna.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>
#define M_PI 3.14159265358979323846
void testujReguleTrapezow() {
    std::cout << "=== TESTOWANIE REGULY TRAPEZOW ===" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Test 1:x dx = 0.5
    std::cout << "\nTest 1: calka 1 0 x dx" << std::endl;
    auto f1 = [](double x) { return x; };

    double wynik1 = BibliotekaNumeryczna::regulaTrapezow(f1, 0, 1, 1000);
    double oczekiwany1 = 0.5;
    std::cout << "Wynik numeryczny: " << wynik1 << std::endl;
    std::cout << "Wynik analityczny: " << oczekiwany1 << std::endl;
    std::cout << "Blad: " << std::abs(wynik1 - oczekiwany1) << std::endl;
    assert(std::abs(wynik1 - oczekiwany1) < 0.001);
    std::cout << "? Test 1 przeszedl pomyslnie!" << std::endl;

    // Test 2:x^2 dx = 8/3 = 2.666667
    std::cout << "\nTest 2: calka 2 0 x^2 dx" << std::endl;
    auto f2 = [](double x) { return x * x; };
    double wynik2 = BibliotekaNumeryczna::regulaTrapezow(f2, 0, 2, 1000);
    double oczekiwany2 = 8.0 / 3.0;
    std::cout << "Wynik numeryczny: " << wynik2 << std::endl;
    std::cout << "Wynik analityczny: " << oczekiwany2 << std::endl;
    std::cout << "Blad: " << std::abs(wynik2 - oczekiwany2) << std::endl;
    assert(std::abs(wynik2 - oczekiwany2) < 0.01);
    std::cout << "? Test 2 przeszedl pomyslnie!" << std::endl;

    // Test 3:pi^0 sin(x) dx = 2
    std::cout << "\nTest 3: calka pi 0 sin(x) dx" << std::endl;
    auto f3 = [](double x) { return sin(x); };
    double wynik3 = BibliotekaNumeryczna::regulaTrapezow(f3, 0, M_PI, 1000);
    double oczekiwany3 = 2.0;
    std::cout << "Wynik numeryczny: " << wynik3 << std::endl;
    std::cout << "Wynik analityczny: " << oczekiwany3 << std::endl;
    std::cout << "Blad: " << std::abs(wynik3 - oczekiwany3) << std::endl;
    assert(std::abs(wynik3 - oczekiwany3) < 0.01);
    std::cout << "? Test 3 przeszedl pomyslnie!" << std::endl;

    std::cout << "\n=== WSZYSTKIE TESTY REGULY TRAPEZOW PRZESZLY! ===" << std::endl;
}
