#include "biblioteka_numeryczna.h"
#include <stdexcept>

namespace BibliotekaNumeryczna {
    double regulaTrapezow(std::function<double(double)> f, double a, double b, int n) {
        if (n <= 0) {
            throw std::invalid_argument("Liczba przedzia³ów musi byæ wiêksza od zera");
        }
        if (a >= b) {
            throw std::invalid_argument("Górna granica musi byæ wiêksza od dolnej");
        }

        double h = (b - a) / static_cast<double>(n); // wysokoœæ trapezów
        double suma = 0.0;

        // Pierwsza i ostatnia wartoœæ funkcji (z wag¹ 0.5)
        suma += 0.5 * f(a);
        suma += 0.5 * f(b);

        // Wartoœci poœrednie (z wag¹ 1.0)
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            suma += f(x);
        }

        return suma * h;
    }
}
