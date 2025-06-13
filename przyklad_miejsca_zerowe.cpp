#include "biblioteka_numeryczna.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#define M_PI 3.14159265358979323846

void znajdzMiejscaZerowe() {
    std::cout << "=== ZNAJDOWANIE MIEJSC ZEROWYCH FUNKCJI sin^2(x-0.5) ===" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Definicja funkcji f(x) = sin^2(x - 0.5)
    auto f = [](double x) {
        double sin_val = sin(x - 0.5);
        return sin_val * sin_val;
        };

    std::cout << "\nFunkcja: f(x) = sin^2(x - 0.5)" << std::endl;
    std::cout << "Przedzial poszukiwan: [-2pi, 2pi]" << std::endl;
    std::cout << "Metoda: Bisekcja" << std::endl;

    // Przedzialy zawierajace miejsca zerowe
    std::vector<std::pair<double, double>> przedzialy = {
        {-6.5, -5.0},  // dla x = 0.5 - 2pi
        {-3.5, -2.0},  // dla x = 0.5 - pi
        {0.0, 1.0},    // dla x = 0.5
        {3.0, 4.0},    // dla x = 0.5 + pi
        {6.0, 7.0}     // dla x = 0.5 + 2pi
    };

    std::vector<double> miejsca_zerowe;

    std::cout << "\nSzukanie miejsc zerowych:" << std::endl;

    for (int i = 0; i < static_cast<int>(przedzialy.size()); i++) {
        double a = przedzialy[i].first;
        double b = przedzialy[i].second;

        std::cout << "\nPrzedzial [" << a << ", " << b << "]:" << std::endl;
        std::cout << "f(" << a << ") = " << f(a) << std::endl;
        std::cout << "f(" << b << ") = " << f(b) << std::endl;

        try {
            double pierwiastek = BibliotekaNumeryczna::metodaBisekcji(f, a, b, 0.00000000001);
            miejsca_zerowe.push_back(pierwiastek);

            std::cout << "Miejsce zerowe: x = " << pierwiastek << std::endl;
            std::cout << "Sprawdzenie: f(" << pierwiastek << ") = " << f(pierwiastek) << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Blad: " << e.what() << std::endl;
        }
    }

    // Podsumowanie wynikow
    std::cout << "\n=== PODSUMOWANIE WYNIKOW ===" << std::endl;
    std::cout << "Znalezione miejsca zerowe:" << std::endl;

    for (int i = 0; i < static_cast<int>(miejsca_zerowe.size()); i++) {
        double x = miejsca_zerowe[i];
        std::cout << "x" << (i + 1) << " = " << x << " (blad: " << f(x) << ")" << std::endl;
    }

    // Weryfikacja teoretyczna
    std::cout << "\nWeryfikacja teoretyczna:" << std::endl;
    std::cout << "sin^2(x - 0.5) = 0 gdy sin(x - 0.5) = 0" << std::endl;
    std::cout << "sin(u) = 0 gdy u = kpi, wiec x - 0.5 = kpi" << std::endl;
    std::cout << "Rozwiazanie: x = 0.5 + kpi" << std::endl;

    std::vector<double> teoretyczne = {
        0.5 - 2 * M_PI,  // k = -2
        0.5 - M_PI,    // k = -1
        0.5,           // k = 0
        0.5 + M_PI,    // k = 1
        0.5 + 2 * M_PI   // k = 2
    };

    std::cout << "\nWartosci teoretyczne:" << std::endl;
    for (int i = 0; i < static_cast<int>(teoretyczne.size()); i++) {
        std::cout << "x" << (i + 1) << " = " << teoretyczne[i] << std::endl;
    }

}
