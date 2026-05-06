#include "biblioteka_numeryczna.h"
#include <stdexcept>

namespace BibliotekaNumeryczna {
    std::vector<double> metodaEulera(std::function<double(double, double)> f, double x0, double y0, double h, int n) {
        if (n <= 0) {
            throw std::invalid_argument("Liczba kroków musi byæ wiêksza od zera");
        }
        if (h <= 0) {
            throw std::invalid_argument("Krok h musi byæ wiêkszy od zera");
        }

        std::vector<double> wynik;
        wynik.reserve(n + 1);

        double x = x0;
        double y = y0;
        wynik.push_back(y);

        for (int i = 0; i < n; i++) {
            y = y + h * f(x, y);
            x = x + h;
            wynik.push_back(y);
        }

        return wynik;
    }
}
