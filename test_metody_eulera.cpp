#include "biblioteka_numeryczna.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <iomanip>

void testujMetodeEulera() {
    std::cout << "=== TESTOWANIE METODY EULERA ===" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Test 1: y' = y, y(0) = 1, rozwiazanie analityczne y = e^x
    std::cout << "\nTest 1: y' = y, y(0) = 1 (rozwiazanie: y = e^x)" << std::endl;
    auto f1 = [](double x, double y) { return y; };
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    int n = 10;

    std::vector<double> wynik1 = BibliotekaNumeryczna::metodaEulera(f1, x0, y0, h, n);

    // Sprawdz kilka punktow
    for (int i = 0; i <= n; i += 2) { // Co drugi punkt
        double x = x0 + i * h;
        double y_analit = std::exp(x);
        double blad = std::abs(wynik1[i] - y_analit);
        std::cout << "x = " << x << ", y (numeryczne) = " << wynik1[i]
            << ", y (analityczne) = " << y_analit << ", blad = " << blad << std::endl;
        assert(blad < 0.15); // Tolerancja dla metody Eulera
    }
    std::cout << "? Test 1 przeszedl pomyslnie!" << std::endl;

    // Test 2: y' = -y, y(0) = 1, rozwiazanie analityczne y = e^(-x)
    std::cout << "\nTest 2: y' = -y, y(0) = 1 (rozwiazanie: y = e^(-x))" << std::endl;
    auto f2 = [](double x, double y) { return -y; };
    std::vector<double> wynik2 = BibliotekaNumeryczna::metodaEulera(f2, x0, y0, h, n);

    // Sprawdz punkt koncowy
    double x_koniec = x0 + n * h;
    double y_analit_koniec = std::exp(-x_koniec);
    double blad_koniec = std::abs(wynik2[n] - y_analit_koniec);
    std::cout << "x = " << x_koniec << ", y (numeryczne) = " << wynik2[n]
        << ", y (analityczne) = " << y_analit_koniec << ", blad = " << blad_koniec << std::endl;
    assert(blad_koniec < 0.15);
    std::cout << "? Test 2 przeszedl pomyslnie!" << std::endl;

    // Test 3: y' = x, y(0) = 0, rozwiazanie analityczne y = x?/2
    std::cout << "\nTest 3: y' = x, y(0) = 0 (rozwiazanie: y = x?/2)" << std::endl;
    auto f3 = [](double x, double y) { return x; };
    std::vector<double> wynik3 = BibliotekaNumeryczna::metodaEulera(f3, 0.0, 0.0, 0.1, 10);

    double x_test = 1.0;
    double y_test_analit = (x_test * x_test) / 2.0; // x?/2
    double y_test_numeryczne = wynik3[10]; // x = 0 + 10*0.1 = 1.0
    double blad_test = std::abs(y_test_numeryczne - y_test_analit);

    std::cout << "x = " << x_test << ", y (numeryczne) = " << y_test_numeryczne
        << ", y (analityczne) = " << y_test_analit << ", blad = " << blad_test << std::endl;
    assert(blad_test < 0.1);
    std::cout << "? Test 3 przeszedl pomyslnie!" << std::endl;

    std::cout << "\n=== WSZYSTKIE TESTY METODY EULERA PRZESZLY! ===" << std::endl;
}
