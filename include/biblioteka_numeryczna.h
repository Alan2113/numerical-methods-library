#ifndef BIBLIOTEKA_NUMERYCZNA_H
#define BIBLIOTEKA_NUMERYCZNA_H

#include <vector>
#include <functional>

/**
 * @brief Biblioteka metod numerycznych dla inżynierii obliczeniowej
 * @author Student II roku inżynierii komputerowej
 * @version 1.0
 *
 * Zawiera implementacje podstawowych metod numerycznych:
 * - Rozwiązywanie równań nieliniowych
 * - Rozwiązywanie układów równań liniowych
 * - Całkowanie numeryczne
 * - Interpolacja
 * - Aproksymacja
 * - Rozwiązywanie równań różniczkowych
 */

namespace BibliotekaNumeryczna {

    /**
     * @brief Metoda bisekcji do znajdowania pierwiastków równań nieliniowych
     * @param f Funkcja, dla której szukamy pierwiastka f(x) = 0
     * @param a Lewa granica przedziału poszukiwań
     * @param b Prawa granica przedziału poszukiwań
     * @param epsilon Tolerancja błędu (domyślnie 0.00001)
     * @return Przybliżony pierwiastek równania
     * @throws std::invalid_argument gdy f(a)*f(b) >= 0
     */
    double metodaBisekcji(std::function<double(double)> f, double a, double b, double epsilon = 0.00001);

    /**
     * @brief Eliminacja Gaussa do rozwiązywania układów równań liniowych Ax = b
     * @param A Macierz współczynników (kwadratowa n×n)
     * @param b Wektor wyrazów wolnych (rozmiar n)
     * @return Wektor rozwiązań x
     * @throws std::invalid_argument gdy macierz nie jest kwadratowa
     * @throws std::runtime_error gdy układ jest nieoznaczony lub sprzeczny
     */
    std::vector<double> eliminacjaGaussa(std::vector<std::vector<double>> A, std::vector<double> b);

    /**
     * @brief Reguła trapezów do całkowania numerycznego
     * @param f Funkcja podcałkowa
     * @param a Dolna granica całkowania
     * @param b Górna granica całkowania
     * @param n Liczba przedziałów podziału
     * @return Przybliżona wartość całki oznaczonej
     * @throws std::invalid_argument gdy n <= 0 lub a >= b
     */
    double regulaTrapezow(std::function<double(double)> f, double a, double b, int n);

    /**
     * @brief Interpolacja wielomianowa metodą Lagrange'a
     * @param x Wektor węzłów interpolacji (punkty x_i)
     * @param y Wektor wartości funkcji (wartości y_i = f(x_i))
     * @param xi Punkt, w którym obliczamy wartość interpolowanej funkcji
     * @return Wartość wielomianu interpolacyjnego w punkcie xi
     * @throws std::invalid_argument gdy wektory mają różne rozmiary lub są puste
     */
    double interpolacjaLagrangea(const std::vector<double>& x, const std::vector<double>& y, double xi);

    /**
     * @brief Struktura przechowująca wynik regresji liniowej
     */
    struct WynikRegresji {
        double a;  ///< Współczynnik kierunkowy prostej y = ax + b
        double b;  ///< Wyraz wolny prostej y = ax + b
        double r2; ///< Współczynnik determinacji R² (jakość dopasowania)
    };

    /**
     * @brief Metoda najmniejszych kwadratów (aproksymacja średniokwadratowa)
     * Znajduje prostą y = ax + b najlepiej dopasowaną do zbioru punktów
     * @param x Wektor współrzędnych x punktów
     * @param y Wektor współrzędnych y punktów
     * @return Struktura WynikRegresji zawierająca parametry prostej i R²
     * @throws std::invalid_argument gdy wektory mają różne rozmiary, są puste lub mają mniej niż 2 punkty
     * @throws std::runtime_error gdy wszystkie punkty x są identyczne
     */
    WynikRegresji metodaNajmniejszychKwadratow(const std::vector<double>& x, const std::vector<double>& y);

    /**
     * @brief Metoda Eulera do rozwiązywania równań różniczkowych zwyczajnych
     * Rozwiązuje zagadnienie początkowe: y' = f(x,y), y(x0) = y0
     * @param f Funkcja prawej strony równania różniczkowego f(x,y)
     * @param x0 Punkt początkowy x
     * @param y0 Wartość początkowa y(x0)
     * @param h Krok całkowania
     * @param n Liczba kroków
     * @return Wektor wartości y w punktach x0, x0+h, x0+2h, ..., x0+n*h
     * @throws std::invalid_argument gdy n <= 0 lub h <= 0
     */
    std::vector<double> metodaEulera(std::function<double(double, double)> f, double x0, double y0, double h, int n);

} // namespace BibliotekaNumeryczna

#endif // BIBLIOTEKA_NUMERYCZNA_H
