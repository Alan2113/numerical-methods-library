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
        std::cout << "\n=== MENU TEST�W BIBLIOTEKI NUMERYCZNEJ ===" << std::endl;
        std::cout << "1. Test metody bisekcji" << std::endl;
        std::cout << "2. Test eliminacji Gaussa" << std::endl;
        std::cout << "3. Test regu�y trapez�w" << std::endl;
        std::cout << "4. Test interpolacji Lagrange'a" << std::endl;
        std::cout << "5. Test metody najmniejszych kwadrat�w" << std::endl;
        std::cout << "6. Test metody Eulera" << std::endl;
        std::cout << "7. Uruchom wszystkie testy" << std::endl;
        std::cout << "0. Zako�cz" << std::endl;
        std::cout << "Wybierz opcj� (0-7): ";

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
                std::cout << "=== URUCHAMIANIE WSZYSTKICH TEST�W BIBLIOTEKI NUMERYCZNEJ ===" << std::endl;
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
                std::cout << "?? WSZYSTKIE TESTY ZAKO�CZONE POMY�LNIE! ??" << std::endl;
                std::cout << "Biblioteka numeryczna zawiera 6 kompletnych kategorii metod:" << std::endl;
                std::cout << "? Rozwi�zywanie r�wna� nieliniowych (metoda bisekcji)" << std::endl;
                std::cout << "? Rozwi�zywanie uk�ad�w r�wna� liniowych (eliminacja Gaussa)" << std::endl;
                std::cout << "? Ca�kowanie numeryczne (regu�a trapez�w)" << std::endl;
                std::cout << "? Interpolacja (metoda Lagrange'a)" << std::endl;
                std::cout << "? Aproksymacja (metoda najmniejszych kwadrat�w)" << std::endl;
                std::cout << "? Rozwi�zywanie r�wna� r�niczkowych (metoda Eulera)" << std::endl;
                std::cout << std::string(60, '=') << std::endl;
                break;
            case 0:
                std::cout << "Zako�czenie programu. Dzi�kujemy za korzystanie z biblioteki numerycznej!" << std::endl;
                break;
            default:
                std::cout << "? Nieprawid�owy wyb�r! Wybierz opcj� od 0 do 7." << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cout << "? B��d podczas wykonywania testu: " << e.what() << std::endl;
            std::cout << "Sprawd� implementacj� odpowiedniej metody numerycznej." << std::endl;
        }

        if (wybor != 0) {
            std::cout << "\nNaci�nij Enter aby kontynuowa�...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (wybor != 0);

    return 0;
}
