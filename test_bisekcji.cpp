#include "biblioteka_numeryczna.h"
#include <iostream>
#include <cmath>
#include <cassert>

void testujMetodeBisekcji() {
    std::cout << "Testowanie metody bisekcji..." << std::endl;

    // Test 1: f(x) = x^2 - 4, pierwiastek x = 2
    auto f1 = [](double x) { return x * x - 4; };
    double pierwiastek1 = BibliotekaNumeryczna::metodaBisekcji(f1, 0, 3, 0.001);
    std::cout << "Test 1: Pierwiastek x^2 - 4 = " << pierwiastek1 << std::endl;
    assert(std::abs(pierwiastek1 - 2.0) < 0.01);

    // Test 2: f(x) = x - 1, pierwiastek x = 1
    auto f2 = [](double x) { return x - 1; };
    double pierwiastek2 = BibliotekaNumeryczna::metodaBisekcji(f2, 0, 2, 0.001);
    std::cout << "Test 2: Pierwiastek x - 1 = " << pierwiastek2 << std::endl;
    assert(std::abs(pierwiastek2 - 1.0) < 0.01);

    std::cout << "Wszystkie testy przesz³y pomyœlnie!" << std::endl;
}

int main() {
    testujMetodeBisekcji();
    return 0;
}
