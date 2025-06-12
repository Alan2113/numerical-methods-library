#include "biblioteka_numeryczna.h"
#include <stdexcept>
#include <cmath>
#include <functional>
using namespace std;

namespace BibliotekaNumeryczna {
    double metodaBisekcji(std::function<double(double)> f, double a, double b, double tolerancja) {
        // Sprawdü warunek poczπtkowy
        if (f(a) * f(b) >= 0) {
            throw std::invalid_argument("Funkcja musi mieÊ rÛøne znaki na koÒcach przedzia≥u");
        }

        double c = a;
        while ((b - a) >= tolerancja) {
            // Znajdü punkt úrodkowy
            c = (a + b) / 2;

            // Sprawdü czy znaleüliúmy dok≥adny pierwiastek
            if (f(c) == 0.0) {
                break;
            }
            // Zdecyduj ktÛra po≥owa zawiera pierwiastek
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
