#ifndef BIBLIOTEKA_NUMERYCZNA_H
#define BIBLIOTEKA_NUMERYCZNA_H

#include <vector>
#include <functional>

namespace BibliotekaNumeryczna {
    // Metoda bisekcji
    double metodaBisekcji(std::function<double(double)> f, double a, double b, double tolerancja = 0.001);

    // Eliminacja Gaussa  
    std::vector<double> eliminacjaGaussa(std::vector<std::vector<double>> A, std::vector<double> b);

    // Regu³a trapezów
    double regulaTrapezow(std::function<double(double)> f, double a, double b, int n);
}

#endif