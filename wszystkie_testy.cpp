#include "biblioteka_numeryczna.h"
#include <iostream>

void testujMetodeBisekcji();
void testujEliminacjeGaussa();
void testujReguleTrapezow();

int main() {
    int wybor;

    do {
        std::cout << "\n=== MENU TEST�W BIBLIOTEKI NUMERYCZNEJ ===" << std::endl;
        std::cout << "1. Test metody bisekcji" << std::endl;
        std::cout << "2. Test eliminacji Gaussa" << std::endl;
        std::cout << "3. Test regu�y trapez�w" << std::endl;
        std::cout << "4. Uruchom wszystkie testy" << std::endl;
        std::cout << "0. Zako�cz" << std::endl;
        std::cout << "Wybierz opcj� (0-4): ";

        std::cin >> wybor;

        try {
            switch (wybor) {
            case 1:
                testujMetodeBisekcji();
                break;
            case 2:
                testujEliminacjeGaussa();
                break;
            case 3:
                testujReguleTrapezow();
                break;
            case 4:
                testujMetodeBisekcji();
                testujEliminacjeGaussa();
                testujReguleTrapezow();
                break;
            case 0:
                std::cout << "Zako�czenie programu." << std::endl;
                break;
            default:
                std::cout << "Nieprawid�owy wyb�r!" << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cout << "B��d: " << e.what() << std::endl;
        }

    } while (wybor != 0);

    return 0;
}
