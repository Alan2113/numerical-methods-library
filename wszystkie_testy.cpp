#include "biblioteka_numeryczna.h"
#include <iostream>

void testujMetodeBisekcji();
void testujEliminacjeGaussa();
void testujReguleTrapezow();

int main() {
    int wybor;

    do {
        std::cout << "\n=== MENU TESTÓW BIBLIOTEKI NUMERYCZNEJ ===" << std::endl;
        std::cout << "1. Test metody bisekcji" << std::endl;
        std::cout << "2. Test eliminacji Gaussa" << std::endl;
        std::cout << "3. Test regu³y trapezów" << std::endl;
        std::cout << "4. Uruchom wszystkie testy" << std::endl;
        std::cout << "0. Zakoñcz" << std::endl;
        std::cout << "Wybierz opcjê (0-4): ";

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
                std::cout << "Zakoñczenie programu." << std::endl;
                break;
            default:
                std::cout << "Nieprawid³owy wybór!" << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cout << "B³¹d: " << e.what() << std::endl;
        }

    } while (wybor != 0);

    return 0;
}
