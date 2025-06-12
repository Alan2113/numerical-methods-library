#include "biblioteka_numeryczna.h"
#include <stdexcept>
#include <cmath>

namespace BibliotekaNumeryczna {
    double interpolacjaLagrangea(const std::vector<double>& x, const std::vector<double>& y, double xi) {
        int n = static_cast<int>(x.size());

        // Sprawd� poprawno�� danych wej�ciowych
        if (n == 0) {
            throw std::invalid_argument("Wektory punkt�w nie mog� by� puste");
        }
        if (x.size() != y.size()) {
            throw std::invalid_argument("Wektory x i y musz� mie� t� sam� d�ugo��");
        }

        // Sprawd� czy punkty x s� r�ne
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (std::abs(x[i] - x[j]) < 1e-12) {
                    throw std::invalid_argument("Punkty x musz� by� r�ne");
                }
            }
        }

        double wynik = 0.0;

        // Oblicz interpolacj� Lagrange'a
        for (int i = 0; i < n; i++) {
            // Oblicz i-ty wielomian bazowy Lagrange'a L_i(xi)
            double Li = 1.0;

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    Li *= (xi - x[j]) / (x[i] - x[j]);
                }
            }

            // Dodaj sk�adnik y[i] * L_i(xi) do wyniku
            wynik += y[i] * Li;
        }

        return wynik;
    }
}
