#include "biblioteka_numeryczna.h"
#include <stdexcept>
#include <cmath>
#include <functional>
using namespace std;

namespace BibliotekaNumeryczna {
    double metodaBisekcji(std::function<double(double)> f, double a, double b, double tolerancja) {
        // Sprawd� warunek pocz�tkowy
        if (f(a) * f(b) >= 0) {
            throw std::invalid_argument("Funkcja musi mie� r�ne znaki na ko�cach przedzia�u");
        }

        double c = a;
        while ((b - a) >= tolerancja) {
            // Znajd� punkt �rodkowy
            c = (a + b) / 2;

            // Sprawd� czy znale�li�my dok�adny pierwiastek
            if (f(c) == 0.0) {
                break;
            }
            // Zdecyduj kt�ra po�owa zawiera pierwiastek
            else if (f(c) * f(a) < 0) {
                b = c;
            }
            else {
                a = c;
            }
        }
        return c;
    }
}
