#include "biblioteka_numeryczna.h"
#include <stdexcept>
#include <cmath>

namespace BibliotekaNumeryczna {
    double metodaBisekcji(std::function<double(double)> f, double a, double b, double epsilon) {
        double fa = f(a);
        double fb = f(b);

        if (fa * fb >= 0) {
            throw std::invalid_argument("Funkcja musi miec rozne znaki na koncach przedzialu");
        }

        if (fa == 0.0) return a;
        if (fb == 0.0) return b;

        double srodek;
        while (std::abs(b - a) > epsilon) {
            srodek = (a + b) / 2.0;
            double fsrodek = f(srodek);

            if (fsrodek == 0.0) {
                return srodek;
            }

            if (fa * fsrodek < 0) {
                b = srodek;
                fb = fsrodek;
            }
            else {
                a = srodek;
                fa = fsrodek;
            }
        }

        return (a + b) / 2.0;
    }
}
