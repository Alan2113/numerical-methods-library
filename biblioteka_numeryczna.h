#ifndef BIBLIOTEKA_NUMERYCZNA_H
#define BIBLIOTEKA_NUMERYCZNA_H

#include <vector>
#include <functional>

namespace BibliotekaNumeryczna {
    // Istniej�ca metoda bisekcji...
    double metodaBisekcji(std::function<double(double)> f, double a, double b, double epsilon = 0.00001);

    // NOWA: Eliminacja Gaussa
    std::vector<double> eliminacjaGaussa(std::vector<std::vector<double>> A, std::vector<double> b);

    // Pozosta�e metody...
    double regulaTrapezow(std::function<double(double)> f, double a, double b, int n);
}

#endif
