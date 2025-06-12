#include "biblioteka_numeryczna.h"
#include <stdexcept>

namespace BibliotekaNumeryczna {
    double regulaTrapezow(std::function<double(double)> f, double a, double b, int n) {
        if (n <= 0) {
            throw std::invalid_argument("Liczba przedzia��w musi by� wi�ksza od zera");
        }
        if (a >= b) {
            throw std::invalid_argument("G�rna granica musi by� wi�ksza od dolnej");
        }

        double h = (b - a) / static_cast<double>(n); // wysoko�� trapez�w
        double suma = 0.0;

        // Pierwsza i ostatnia warto�� funkcji (z wag� 0.5)
        suma += 0.5 * f(a);
        suma += 0.5 * f(b);

        // Warto�ci po�rednie (z wag� 1.0)
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            suma += f(x);
        }

        return suma * h;
    }
}
