#include "biblioteka_numeryczna.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#define M_PI 3.14159265358979323846

void demonstracjaInterpolacjiLagrangea() {
    std::cout << "=== PRZYKLAD ZASTOSOWANIA INTERPOLACJI LAGRANGE'A ===" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Przyklad 1: Interpolacja danych pomiarowych temperatury
    std::cout << "\n--- PRZYKLAD 1: INTERPOLACJA DANYCH POMIAROWYCH ---" << std::endl;
    std::cout << "Problem: Mamy pomiary temperatury w roznych godzinach dnia." << std::endl;
    std::cout << "Chcemy przewidziec temperature o godzinie 14:30." << std::endl;

    // Dane pomiarowe: godzina vs temperatura (stopnie C)
    std::vector<double> godziny = { 8.0, 12.0, 16.0, 20.0 };
    std::vector<double> temperatury = { 15.2, 22.8, 25.1, 18.7 };

    std::cout << "\nDane pomiarowe:" << std::endl;
    for (int i = 0; i < static_cast<int>(godziny.size()); i++) {
        std::cout << "Godzina " << godziny[i] << ":00 -> " << temperatury[i] << " stopni C" << std::endl;
    }

    double godzina_szukana = 14.5; // 14:30
    double temp_interpolowana = BibliotekaNumeryczna::interpolacjaLagrangea(godziny, temperatury, godzina_szukana);

    std::cout << "\nWynik interpolacji:" << std::endl;
    std::cout << "Przewidywana temperatura o godzinie 14:30: " << temp_interpolowana << " stopni C" << std::endl;

    // Przyklad 2: Interpolacja funkcji matematycznej
    std::cout << "\n--- PRZYKLAD 2: INTERPOLACJA FUNKCJI MATEMATYCZNEJ ---" << std::endl;
    std::cout << "Problem: Aproksymacja funkcji f(x) = 1/(1+x^2) na przedziale [-2, 2]" << std::endl;
    std::cout << "Znana jako funkcja Runge'go - trudna do interpolacji wielomianowej." << std::endl;

    // Wezly interpolacji (rownomiernie rozlozone)
    std::vector<double> x_wezly = { -2.0, -1.0, 0.0, 1.0, 2.0 };
    std::vector<double> y_wezly;

    // Oblicz wartosci funkcji Runge'go w wezlach
    std::cout << "\nWezly interpolacji:" << std::endl;
    for (double x : x_wezly) {
        double y = 1.0 / (1.0 + x * x);
        y_wezly.push_back(y);
        std::cout << "f(" << x << ") = " << y << std::endl;
    }

    // Testuj interpolacje w kilku punktach
    std::cout << "\nPorownianie interpolacji z wartosciami rzeczywistymi:" << std::endl;
    std::vector<double> punkty_testowe = { -1.5, -0.5, 0.5, 1.5 };

    for (double x_test : punkty_testowe) {
        double y_rzeczywista = 1.0 / (1.0 + x_test * x_test);
        double y_interpolowana = BibliotekaNumeryczna::interpolacjaLagrangea(x_wezly, y_wezly, x_test);
        double blad = std::abs(y_rzeczywista - y_interpolowana);

        std::cout << "x = " << x_test << std::endl;
        std::cout << "  Wartosc rzeczywista: " << y_rzeczywista << std::endl;
        std::cout << "  Wartosc interpolowana: " << y_interpolowana << std::endl;
        std::cout << "  Blad bezwzgledny: " << blad << std::endl;
        std::cout << std::endl;
    }

    // Przyklad 3: Interpolacja danych eksperymentalnych
    std::cout << "\n--- PRZYKLAD 3: INTERPOLACJA DANYCH EKSPERYMENTALNYCH ---" << std::endl;
    std::cout << "Problem: Zaleznosc predkosci reakcji chemicznej od temperatury." << std::endl;
    std::cout << "Chcemy przewidziec predkosc reakcji przy temperaturze 45 stopni C." << std::endl;

    // Dane eksperymentalne: temperatura (stopnie C) vs predkosc reakcji (mol/s)
    std::vector<double> temp_exp = { 20.0, 30.0, 40.0, 50.0, 60.0 };
    std::vector<double> predkosc = { 0.12, 0.28, 0.65, 1.48, 3.21 };

    std::cout << "\nDane eksperymentalne:" << std::endl;
    for (int i = 0; i < static_cast<int>(temp_exp.size()); i++) {
        std::cout << "T = " << temp_exp[i] << " stopni C -> v = " << predkosc[i] << " mol/s" << std::endl;
    }

    double temp_szukana = 45.0;
    double predkosc_interpolowana = BibliotekaNumeryczna::interpolacjaLagrangea(temp_exp, predkosc, temp_szukana);

    std::cout << "\nWynik interpolacji:" << std::endl;
    std::cout << "Przewidywana predkosc reakcji przy T = " << temp_szukana << " stopni C: "
        << predkosc_interpolowana << " mol/s" << std::endl;

    // Przyklad 4: Interpolacja funkcji trygonometrycznej
    std::cout << "\n--- PRZYKLAD 4: INTERPOLACJA FUNKCJI TRYGONOMETRYCZNEJ ---" << std::endl;
    std::cout << "Problem: Interpolacja funkcji sin(x) na przedziale [0, pi]." << std::endl;

    // Wezly interpolacji dla sin(x)
    std::vector<double> x_sin = { 0, M_PI / 6, M_PI / 3, M_PI / 2, 2 * M_PI / 3, 5 * M_PI / 6, M_PI };
    std::vector<double> y_sin;

    std::cout << "\nWezly interpolacji dla sin(x):" << std::endl;
    for (double x : x_sin) {
        double y = std::sin(x);
        y_sin.push_back(y);
        std::cout << "sin(" << x << ") = " << y << std::endl;
    }

    // Test interpolacji dla sin(pi/4)
    double x_test_sin = M_PI / 4;
    double sin_rzeczywisty = std::sin(x_test_sin);
    double sin_interpolowany = BibliotekaNumeryczna::interpolacjaLagrangea(x_sin, y_sin, x_test_sin);

    std::cout << "\nTest interpolacji w punkcie x = pi/4:" << std::endl;
    std::cout << "sin(pi/4) rzeczywiste: " << sin_rzeczywisty << std::endl;
    std::cout << "sin(pi/4) interpolowane: " << sin_interpolowany << std::endl;
    std::cout << "Blad: " << std::abs(sin_rzeczywisty - sin_interpolowany) << std::endl;

    std::cout << "\n=== ZASTOSOWANIA PRAKTYCZNE INTERPOLACJI LAGRANGE'A ===" << std::endl;
    std::cout << "• Przetwarzanie sygnalow cyfrowych" << std::endl;
    std::cout << "• Analiza danych eksperymentalnych" << std::endl;
    std::cout << "• Grafika komputerowa (animacje, krzywe)" << std::endl;
    std::cout << "• Prognozowanie w meteorologii" << std::endl;
    std::cout << "• Modelowanie procesow fizycznych" << std::endl;
    std::cout << "• Aproksymacja funkcji w obliczeniach naukowych" << std::endl;
}
