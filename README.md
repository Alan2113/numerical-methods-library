# Numerical Methods Library

Biblioteka podstawowych metod numerycznych w C++ z testami jednostkowymi i przykładami zastosowań.

## Spis treści

- [Zaimplementowane metody](#zaimplementowane-metody)
  - [1. Eliminacja Gaussa](#1-eliminacja-gaussa)
  - [2. Interpolacja Lagrange'a](#2-interpolacja-lagrangea)
  - [3. Metoda najmniejszych kwadratów](#3-metoda-najmniejszych-kwadratów)
  - [4. Reguła trapezów](#4-reguła-trapezów)
  - [5. Metoda Eulera](#5-metoda-eulera)
  - [6. Metoda bisekcji](#6-metoda-bisekcji)
- [Struktura projektu](#struktura-projektu)
- [Budowanie](#budowanie)

---

## Zaimplementowane metody

### 1. Eliminacja Gaussa

**Plik:** `src/eliminacja_gaussa.cpp` — *rozwiązywanie układów równań liniowych*

#### Opis algorytmu
Eliminacja Gaussa przekształca macierz współczynników do postaci schodkowej przez eliminację w przód, następnie wykonuje podstawianie wsteczne dla rozwiązania układu `Ax = b`.

#### Funkcjonalność
- Przyjmuje macierz kwadratową `A` i wektor `b`
- Zwraca wektor rozwiązań `x`
- Kontroluje dzielenie przez zero i stabilność numeryczną

#### Zastosowania praktyczne
Analiza obwodów elektrycznych, mechanika konstrukcji, bilanse masowe w inżynierii chemicznej, modele równowagi ekonomicznej.

---

### 2. Interpolacja Lagrange'a

**Plik:** `src/interpolacja_lagrangea.cpp` — *interpolacja*

#### Opis algorytmu
Interpolacja Lagrange'a konstruuje wielomian przechodzący przez zadane punkty używając wielomianów bazowych `L_i(x)`.

#### Funkcjonalność
- Przyjmuje wektory węzłów `x` i wartości `y`
- Oblicza wartość wielomianu w dowolnym punkcie `xi`
- Zapewnia dokładność w węzłach interpolacji

#### Zastosowania praktyczne
Prognozowanie temperatury, aproksymacja danych eksperymentalnych, przetwarzanie sygnałów cyfrowych, grafika komputerowa, meteorologia.

---

### 3. Metoda najmniejszych kwadratów

**Plik:** `src/metoda_najmniejszych_kwadratow.cpp` — *aproksymacja*

#### Opis algorytmu
Metoda najmniejszych kwadratów dopasowuje prostą `y = ax + b` do zbioru punktów minimalizując sumę kwadratów odchyleń.

#### Funkcjonalność
- Oblicza współczynniki `a`, `b` prostej regresji
- Wyznacza współczynnik determinacji `R²`
- Zwraca strukturę `WynikRegresji` z parametrami dopasowania

#### Zastosowania praktyczne
Analiza trendów ekonomicznych, regresja liniowa w statystyce, modelowanie zależności fizycznych, prognozowanie biznesowe.

---

### 4. Reguła trapezów

**Plik:** `src/regula_trapezow.cpp` — *całkowanie numeryczne*

#### Opis algorytmu
Reguła trapezów aproksymuje całkę oznaczoną przez podział przedziału na `n` podprzedziałów i aproksymację funkcji trapezami.

#### Funkcjonalność
- Przyjmuje funkcję, granice całkowania i liczbę przedziałów
- Oblicza przybliżoną wartość całki oznaczonej
- Kontroluje poprawność parametrów wejściowych

#### Zastosowania praktyczne
Obliczanie pracy i energii w fizyce, analiza powierzchni pod krzywymi, momenty bezwładności, przepływy w hydrologii.

---

### 5. Metoda Eulera

**Plik:** `src/metoda_eulera.cpp` — *rozwiązywanie równań różniczkowych*

#### Opis algorytmu
Metoda Eulera numerycznie rozwiązuje równania różniczkowe pierwszego rzędu `y' = f(x, y)` z warunkiem początkowym `y(x₀) = y₀`.

#### Funkcjonalność
- Iteracyjnie oblicza wartości `y_{n+1} = y_n + h · f(x_n, y_n)`
- Zwraca wektor rozwiązań w zadanych punktach
- Kontroluje stabilność kroku całkowania

#### Zastosowania praktyczne
Modelowanie wzrostu populacji, dynamika układów mechanicznych, kinetyka reakcji chemicznych, symulacje czasowe w inżynierii.

---

### 6. Metoda bisekcji

**Plik:** `src/metoda_bisekcji.cpp` — *rozwiązywanie równań nieliniowych*

#### Opis algorytmu
Metoda bisekcji iteracyjnie znajduje pierwiastki równań nieliniowych `f(x) = 0` wykorzystując twierdzenie Bolzano o wartości pośredniej.

#### Funkcjonalność
- Dzieli przedział na pół i wybiera część zawierającą pierwiastek
- Kontynuuje do osiągnięcia zadanej dokładności
- Sprawdza warunek zmiany znaku funkcji

#### Zastosowania praktyczne
Obliczanie pierwiastków, rozwiązywanie równań transcendentnych, analiza punktów równowagi, optymalizacja procesów nieliniowych.

---

## Struktura projektu

```
numerical-methods-library/
├── include/        # interfejs API (pliki nagłówkowe)
├── src/            # implementacje metod numerycznych
├── tests/          # testy jednostkowe każdej metody
├── examples/       # przykłady praktycznych zastosowań
└── CMakeLists.txt  # konfiguracja budowania
```

### Architektura modułowa
- Interfejs API w pliku nagłówkowym
- Implementacje w osobnych plikach źródłowych
- Testy jednostkowe dla każdej metody
- Przykłady praktycznych zastosowań

### Standardy jakości
- Dokumentacja z komentarzami Doxygen
- Obsługa wyjątków i kontrola błędów
- Modularność i separacja interfejsu
- Kompletne testy weryfikacyjne

---

## Budowanie

```bash
git clone https://github.com/Alan2113/numerical-methods-library
cd numerical-methods-library
cmake -B build
cmake --build build
./build/wszystkie_testy
```
