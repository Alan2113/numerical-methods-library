#include "biblioteka_numeryczna.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <iomanip>

#define M_PI 3.14159265358979323846

void testujInterpolacjeLagrangea() {
    std::cout << "=== TESTOWANIE INTERPOLACJI LAGRANGE'A ===" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Test 1: Interpolacja liniowa przez 2 punkty
    std::cout << "\nTest 1: Interpolacja liniowa f(x) = 2x + 1" << std::endl;
    std::vector<double> x1 = { 0, 1 };
    std::vector<double> y1 = { 1, 3 }; // f(0) = 1, f(1) = 3

    double wynik1 = BibliotekaNumeryczna::interpolacjaLagrangea(x1, y1, 0.5);
    double oczekiwany1 = 2 * 0.5 + 1; // f(0.5) = 2

    std::cout << "Interpolacja w x = 0.5: " << wynik1 << std::endl;
    std::cout << "Wartosc rzeczywista: " << oczekiwany1 << std::endl;
    std::cout << "Blad: " << std::abs(wynik1 - oczekiwany1) << std::endl;
    assert(std::abs(wynik1 - oczekiwany1) < 0.000001);
    std::cout << "? Test 1 przeszedl pomyslnie!" << std::endl;

    // Test 2: Interpolacja kwadratowa przez 3 punkty
    std::cout << "\nTest 2: Interpolacja kwadratowa f(x) = x^2" << std::endl;
    std::vector<double> x2 = { 0, 1, 2 };
    std::vector<double> y2 = { 0, 1, 4 }; // f(0) = 0, f(1) = 1, f(2) = 4

    double wynik2 = BibliotekaNumeryczna::interpolacjaLagrangea(x2, y2, 1.5);
    double oczekiwany2 = 1.5 * 1.5; // f(1.5) = 2.25

    std::cout << "Interpolacja w x = 1.5: " << wynik2 << std::endl;
    std::cout << "Wartosc rzeczywista: " << oczekiwany2 << std::endl;
    std::cout << "Blad: " << std::abs(wynik2 - oczekiwany2) << std::endl;
    assert(std::abs(wynik2 - oczekiwany2) < 0.000001);
    std::cout << "? Test 2 przeszedl pomyslnie!" << std::endl;

    // Test 3: Interpolacja przez punkty funkcji sin(x)
    std::cout << "\nTest 3: Interpolacja funkcji sin(x)" << std::endl;
    std::vector<double> x3 = { 0, M_PI / 6, M_PI / 4, M_PI / 3, M_PI / 2 };
    std::vector<double> y3;

    // Oblicz wartosci sin(x) w punktach
    for (double xi : x3) {
        y3.push_back(sin(xi));
    }

    double punkt_test = M_PI / 8; // 22.5 stopni
    double wynik3 = BibliotekaNumeryczna::interpolacjaLagrangea(x3, y3, punkt_test);
    double oczekiwany3 = sin(punkt_test);

    std::cout << "Interpolacja sin(" << punkt_test << ") = " << wynik3 << std::endl;
    std::cout << "Wartosc rzeczywista: " << oczekiwany3 << std::endl;
    std::cout << "Blad: " << std::abs(wynik3 - oczekiwany3) << std::endl;
    assert(std::abs(wynik3 - oczekiwany3) < 0.01); // Wieksza tolerancja dla funkcji nieliniowej
    std::cout << "? Test 3 przeszedl pomyslnie!" << std::endl;

    // Test 4: Sprawdzenie dokladnosci w punktach wezlowych
    std::cout << "\nTest 4: Sprawdzenie dokladnosci w punktach wezlowych" << std::endl;
    for (int i = 0; i < static_cast<int>(x2.size()); i++) {
        double wynik_wezlowy = BibliotekaNumeryczna::interpolacjaLagrangea(x2, y2, x2[i]);
        std::cout << "f(" << x2[i] << ") = " << wynik_wezlowy << ", oczekiwane: " << y2[i] << std::endl;
        assert(std::abs(wynik_wezlowy - y2[i]) < 0.000001);
    }
    std::cout << "? Test 4 przeszedl pomyslnie!" << std::endl;

    std::cout << "\n=== WSZYSTKIE TESTY INTERPOLACJI LAGRANGE'A PRZESZLY! ===" << std::endl;
}
