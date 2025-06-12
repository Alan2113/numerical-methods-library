#include "biblioteka_numeryczna.h"
#include <stdexcept>
#include <cmath>

namespace BibliotekaNumeryczna {
    WynikRegresji metodaNajmniejszychKwadratow(const std::vector<double>& x, const std::vector<double>& y) {
        int n = static_cast<int>(x.size());

        if (n == 0) {
            throw std::invalid_argument("Wektory nie mog¹ byæ puste");
        }
        if (x.size() != y.size()) {
            throw std::invalid_argument("Wektory x i y musz¹ mieæ tê sam¹ d³ugoœæ");
        }
        if (n < 2) {
            throw std::invalid_argument("Potrzeba co najmniej 2 punkty");
        }

        // Oblicz sumy potrzebne do wzorów
        double suma_x = 0, suma_y = 0, suma_xy = 0, suma_x2 = 0;

        for (int i = 0; i < n; i++) {
            suma_x += x[i];
            suma_y += y[i];
            suma_xy += x[i] * y[i];
            suma_x2 += x[i] * x[i];
        }

        // SprawdŸ czy mo¿na obliczyæ wspó³czynniki
        double mianownik = n * suma_x2 - suma_x * suma_x;
        if (std::abs(mianownik) < 1e-12) {
            throw std::runtime_error("Nie mo¿na obliczyæ regresji - wszystkie punkty x s¹ identyczne");
        }

        // Oblicz wspó³czynniki prostej y = ax + b
        double a = (n * suma_xy - suma_x * suma_y) / mianownik;
        double b = (suma_y - a * suma_x) / n;

        // Oblicz wspó³czynnik determinacji R?
        double srednia_y = suma_y / n;
        double ss_tot = 0, ss_res = 0;

        for (int i = 0; i < n; i++) {
            double y_pred = a * x[i] + b;
            ss_res += (y[i] - y_pred) * (y[i] - y_pred);
            ss_tot += (y[i] - srednia_y) * (y[i] - srednia_y);
        }

        double r2 = (ss_tot > 1e-12) ? 1.0 - (ss_res / ss_tot) : 1.0;

        return { a, b, r2 };
    }
}
