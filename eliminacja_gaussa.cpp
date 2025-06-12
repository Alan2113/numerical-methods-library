#include "biblioteka_numeryczna.h"
#include <stdexcept>
#include <cmath>
#include <iomanip>

namespace BibliotekaNumeryczna {
    std::vector<double> eliminacjaGaussa(std::vector<std::vector<double>> A, std::vector<double> b) {
        int n = static_cast<int>(b.size());
        const double eps = 1e-12; // sta�a przybli�enia zera

        // Sprawd� wymiary macierzy
        if (static_cast<int>(A.size()) != n) {
            throw std::invalid_argument("Macierz A musi by� kwadratowa");
        }
        for (int i = 0; i < n; i++) {
            if (static_cast<int>(A[i].size()) != n) {
                throw std::invalid_argument("Macierz A musi by� kwadratowa");
            }
        }

        // Tworzenie macierzy rozszerzonej [A|b]
        std::vector<std::vector<double>> AB(n, std::vector<double>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                AB[i][j] = A[i][j];
            }
            AB[i][n] = b[i];
        }

        // Eliminacja wsp�czynnik�w (eliminacja w prz�d)
        for (int i = 0; i < n - 1; i++) {
            // Sprawd� czy element g��wny nie jest zerem
            if (std::abs(AB[i][i]) < eps) {
                throw std::runtime_error("Dzielenie przez zero - uk�ad mo�e by� nieoznaczony");
            }

            // Eliminacja w kolumnie i
            for (int j = i + 1; j < n; j++) {
                double mnoznik = AB[j][i] / AB[i][i];

                // Odejmij wielokrotno�� wiersza i od wiersza j
                for (int k = i; k <= n; k++) {
                    AB[j][k] -= mnoznik * AB[i][k];
                }
            }
        }

        // Sprawd� czy ostatni element g��wny nie jest zerem
        if (std::abs(AB[n - 1][n - 1]) < eps) {
            throw std::runtime_error("Uk�ad r�wna� jest nieoznaczony lub sprzeczny");
        }

        // Podstawianie wsteczne (back substitution)
        std::vector<double> x(n);

        // Ostatnia niewiadoma
        x[n - 1] = AB[n - 1][n] / AB[n - 1][n - 1];

        // Pozosta�e niewiadome
        for (int i = n - 2; i >= 0; i--) {
            double suma = AB[i][n];

            for (int j = i + 1; j < n; j++) {
                suma -= AB[i][j] * x[j];
            }

            x[i] = suma / AB[i][i];
        }

        return x;
    }
}
