1. Rozwiązywanie układów równań liniowych - eliminacja_gaussa.cpp
Opis algorytmu:
Eliminacja Gaussa przekształca macierz współczynników do postaci schodkowej przez eliminację w przód, następnie wykonuje podstawianie wsteczne dla rozwiązania układu Ax = b.

Funkcjonalność:

Przyjmuje macierz kwadratową A i wektor b

Zwraca wektor rozwiązań x

Kontroluje dzielenie przez zero i stabilność numeryczną

Zastosowania praktyczne:
Analiza obwodów elektrycznych, mechanika konstrukcji, bilanse masowe w inżynierii chemicznej, modele równowagi ekonomicznej.

2. Interpolacja - interpolacja_lagrangea.cpp
Opis algorytmu:
Interpolacja Lagrange'a konstruuje wielomian przechodzący przez zadane punkty używając wielomianów bazowych L_i(x).

Funkcjonalność:

Przyjmuje wektory węzłów x i wartości y

Oblicza wartość wielomianu w dowolnym punkcie xi

Zapewnia dokładność w węzłach interpolacji

Zastosowania praktyczne:
Prognozowanie temperatury, aproksymacja danych eksperymentalnych, przetwarzanie sygnałów cyfrowych, grafika komputerowa, meteorologia.

3. Aproksymacja - metoda_najmniejszych_kwadratow.cpp
Opis algorytmu:
Metoda najmniejszych kwadratów dopasowuje prostą y = ax + b do zbioru punktów minimalizując sumę kwadratów odchyleń.

Funkcjonalność:

Oblicza współczynniki a, b prostej regresji

Wyznacza współczynnik determinacji R²

Zwraca strukturę WynikRegresji z parametrami dopasowania

Zastosowania praktyczne:
Analiza trendów ekonomicznych, regresja liniowa w statystyce, modelowanie zależności fizycznych, prognozowanie biznesowe.

4. Całkowanie numeryczne - regula_trapezow.cpp
Opis algorytmu:
Reguła trapezów aproksymuje całkę oznaczoną przez podział przedziału na n podprzedziałów i aproksymację funkcji trapezami.

Funkcjonalność:

Przyjmuje funkcję, granice całkowania i liczbę przedziałów

Oblicza przybliżoną wartość całki oznaczonej

Kontroluje poprawność parametrów wejściowych

Zastosowania praktyczne:
Obliczanie pracy i energii w fizyce, analiza powierzchni pod krzywymi, momenty bezwładności, przepływy w hydrologii.

5. Rozwiązywanie równań różniczkowych - metoda_eulera.cpp
Opis algorytmu:
Metoda Eulera numerycznie rozwiązuje równania różniczkowe pierwszego rzędu y' = f(x,y) z warunkiem początkowym y(x₀) = y₀.

Funkcjonalność:

Iteracyjnie oblicza wartości y_{n+1} = y_n + h × f(x_n, y_n)

Zwraca wektor rozwiązań w zadanych punktach

Kontroluje stabilność kroku całkowania

Zastosowania praktyczne:
Modelowanie wzrostu populacji, dynamika układów mechanicznych, kinetyka reakcji chemicznych, symulacje czasowe w inżynierii.

6. Rozwiązywanie równań nieliniowych - metoda_bisekcji.cpp
Opis algorytmu:
Metoda bisekcji iteracyjnie znajduje pierwiastki równań nieliniowych f(x) = 0 wykorzystując twierdzenie Bolzano o wartości pośredniej.

Funkcjonalność:

Dzieli przedział na pół i wybiera część zawierającą pierwiastek

Kontynuuje do osiągnięcia zadanej dokładności

Sprawdza warunek zmiany znaku funkcji

Zastosowania praktyczne:
Obliczanie pierwiastków, rozwiązywanie równań transcendentnych, analiza punktów równowagi, optymalizacja procesów nieliniowych.

Struktura i organizacja projektu
Architektura modułowa:

Interfejs API w pliku nagłówkowym

Implementacje w osobnych plikach źródłowych

Testy jednostkowe dla każdej metody

Przykłady praktycznych zastosowań

Standardy jakości:

Dokumentacja z komentarzami Doxygen

Obsługa wyjątków i kontrola błędów

Modularność i separacja interfejsu

Kompletne testy weryfikacyjne
