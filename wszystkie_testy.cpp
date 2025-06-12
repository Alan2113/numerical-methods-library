#include "biblioteka_numeryczna.h"
#include <iostream>

// Deklaracje funkcji testowych
void testujMetodeBisekcji();
void testujEliminacjeGaussa();
void testujReguleTrapezow();
void testujInterpolacjeLagrangea();
void testujMetodeNajmniejszychKwadratow();
void testujMetodeEulera();

int main() {
    int wybor;

    do {
        std::cout << "\n=== MENU TESTÓW BIBLIOTEKI NUMERYCZNEJ ===" << std::endl;
        std::cout << "1. Test metody bisekcji" << std::endl;
        std::cout << "2. Test eliminacji Gaussa" << std::endl;
        std::cout << "3. Test regu³y trapezów" << std::endl;
        std::cout << "4. Test interpolacji Lagrange'a" << std::endl;
        std::cout << "5. Test metody najmniejszych kwadratów" << std::endl;
        std::cout << "6. Test metody Eulera" << std::endl;
        std::cout << "7. Uruchom wszystkie testy" << std::endl;
        std::cout << "0. Zakoñcz" << std::endl;
        std::cout << "Wybierz opcjê (0-7): ";

        std::cin >> wybor;

        try {
            switch (wybor) {
            case 1:
                std::cout << "\n" << std::string(50, '=') << std::endl;
                testujMetodeBisekcji();
                std::cout << std::string(50, '=') << std::endl;
                break;
            case 2:
                std::cout << "\n" << std::string(50, '=') << std::endl;
                testujEliminacjeGaussa();
                std::cout << std::string(50, '=') << std::endl;
                break;
            case 3:
                std::cout << "\n" << std::string(50, '=') << std::endl;
                testujReguleTrapezow();
                std::cout << std::string(50, '=') << std::endl;
                break;
            case 4:
                std::cout << "\n" << std::string(50, '=') << std::endl;
                testujInterpolacjeLagrangea();
                std::cout << std::string(50, '=') << std::endl;
                break;
            case 5:
                std::cout << "\n" << std::string(50, '=') << std::endl;
                testujMetodeNajmniejszychKwadratow();
                std::cout << std::string(50, '=') << std::endl;
                break;
            case 6:
                std::cout << "\n" << std::string(50, '=') << std::endl;
                testujMetodeEulera();
                std::cout << std::string(50, '=') << std::endl;
                break;
            case 7:
                std::cout << "\n" << std::string(60, '=') << std::endl;
                std::cout << "=== URUCHAMIANIE WSZYSTKICH TESTÓW BIBLIOTEKI NUMERYCZNEJ ===" << std::endl;
                std::cout << std::string(60, '=') << std::endl;

                testujMetodeBisekcji();
                std::cout << "\n" << std::string(30, '-') << std::endl;

                testujEliminacjeGaussa();
                std::cout << "\n" << std::string(30, '-') << std::endl;

                testujReguleTrapezow();
                std::cout << "\n" << std::string(30, '-') << std::endl;

                testujInterpolacjeLagrangea();
                std::cout << "\n" << std::string(30, '-') << std::endl;

                testujMetodeNajmniejszychKwadratow();
                std::cout << "\n" << std::string(30, '-') << std::endl;

                testujMetodeEulera();

                std::cout << "\n" << std::string(60, '=') << std::endl;
                std::cout << "?? WSZYSTKIE TESTY ZAKOÑCZONE POMYŒLNIE! ??" << std::endl;
                std::cout << "Biblioteka numeryczna zawiera 6 kompletnych kategorii metod:" << std::endl;
                std::cout << "? Rozwi¹zywanie równañ nieliniowych (metoda bisekcji)" << std::endl;
                std::cout << "? Rozwi¹zywanie uk³adów równañ liniowych (eliminacja Gaussa)" << std::endl;
                std::cout << "? Ca³kowanie numeryczne (regu³a trapezów)" << std::endl;
                std::cout << "? Interpolacja (metoda Lagrange'a)" << std::endl;
                std::cout << "? Aproksymacja (metoda najmniejszych kwadratów)" << std::endl;
                std::cout << "? Rozwi¹zywanie równañ ró¿niczkowych (metoda Eulera)" << std::endl;
                std::cout << std::string(60, '=') << std::endl;
                break;
            case 0:
                std::cout << "Zakoñczenie programu. Dziêkujemy za korzystanie z biblioteki numerycznej!" << std::endl;
                break;
            default:
                std::cout << "? Nieprawid³owy wybór! Wybierz opcjê od 0 do 7." << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cout << "? B³¹d podczas wykonywania testu: " << e.what() << std::endl;
            std::cout << "SprawdŸ implementacjê odpowiedniej metody numerycznej." << std::endl;
        }

        if (wybor != 0) {
            std::cout << "\nNaciœnij Enter aby kontynuowaæ...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (wybor != 0);

    return 0;
}
