#ifndef BIBLIOTEKA_NUMERYCZNA_H
#define BIBLIOTEKA_NUMERYCZNA_H

#include <vector>
#include <functional>

namespace BibliotekaNumeryczna {
    // TYLKO DEKLARACJE - bez implementacji!
    double metodaBisekcji(std::function<double(double)> f, double a, double b, double epsilon = 0.00001);
    std::vector<double> eliminacjaGaussa(std::vector<std::vector<double>> A, std::vector<double> b);
    double regulaTrapezow(std::function<double(double)> f, double a, double b, int n);
}

#endif
