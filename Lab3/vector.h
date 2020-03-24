#ifndef VECTOR_H
#define VECTOR_H

// author: Grzegorz Prowadzacy
#include "fraction.h"
#include "utils/memoryManagement.h"
#include <memory>

/** Tresc zadania:
Panstwa zadaniem jest napisanie automatycznie rozszerzajacej sie tablicy dynamicznej (zwanej potocznie Vector), oraz funkcji do jej obslugi. Nasz Vector ma byc tablica elementow typu T (szczegoly ponizej). Nasza implementacja wzorowana C++owym std::vector, aczkolwiek inna: http://www.cplusplus.com/reference/vector/vector/

Nasza implementacja w razie automatycznego zwiekszania rozmiaru ma allokowac pamiec tylko o 1 wieksza!
Ma to byc struktura Vector, ktora zawiera w sobie:
    - wskaznik na tablice dynamiczna (ang. data)
    - rozmiar aktualnie zaalokowanej tablicy dynamicznej (ang. capacity)
    - ilosc elementow w tablicy (ang. size)

Poza struktura Vector prosze zaimplementowac pewne funkcje, ktorych deklaracje znajduja sie ponizej.

Prosze tez pamietac aby poza plikiem z rozwiazaniem zalaczyc rowniez ten plik naglowkowy o nazwie vector.h, bez robienia w nim jakichkolwiek zmian.

Podpowiedzi:
    - polecam ogarnac operator trojargumentowy: ?:,
    - polecam ogarnac funkcje realloc()

Ćw3 [17pkt] Klasy z dynamiczną zawartością, wyjątki (UWAGA: To bardzo wazne zadanie, jeśli ktoś chce być programista C++ to w srodku nocy powinien umiec takie zadania robic!)
Plan zajęć:

    Panstwa zadaniem jest napisanie automatycznie rozszerzajacej sie tablicy dynamicznej (zwanej potocznie Vector), oraz funkcji do jej obslugi. Nasz Vector ma byc tablica elementow typu Fraction. Nasza implementacja wzorowana C++owym std::vector, aczkolwiek inna: http://www.cplusplus.com/reference/vector/vector/
    Nie wolno uzyc w srodku std::vector! Zaawansowani moga uzyc uzyc inteligetnych wskaznikow, jesli chca.
Nasza implementacja w razie automatycznego zwiekszania rozmiaru ma allokowac pamiec tylko o 1 wieksza!
    Ma to byc klasa Vector, ktora zawiera w sobie:
    + wskaznik na tablice dynamiczna (ang. data)
    + rozmiar aktualnie zaalokowanej tablicy dynamicznej (ang. capacity)
    + ilosc elementow w tablicy (ang. size)
    + Ponadto proszę o zaimplementowanie metod zwracającej liczbę elementów w tablicy size(), wielkosc tablicy capacity()

    [6pkt] Uzupełnij drugą klasę o następujące elementy:
        + konstruktor przyjmujacy liczbe do wstepnej allokacji (z wartoscia domyslna 0)
        + destruktor (zwalniajacy pamiec),
        + konstruktor kopiujący (gleboko) oraz przenoszący,
        + operator podstawienia oraz przenoszący operator podstawienia,
        + metodę dodającą obiekt na koncu tablicy push_back()
        + operator dostepu po indeksie operator[](size_t index)
    + [1pkt] Dostep po indeksie poza rozmiar tablicy (size) powinny być zgłaszane poprzez wyjątki std::out_of_range
    ??? I tak nie możemy usuwać elementów ??? [1pkt] Auto-realokacja tablicy w razie braku elementow

    + [1pkt] Deklaracje klasy powinny znaleźć się w odpowiednich plikach nagłówkowych, definicje metod i konstruktorów - w plikach źródłowych.
    + [1pkt] Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne, metody/konstruktory/destruktory większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane poza klasą,

    + [1pkt] Obiekty typów klasowych powinny być przekazywane do funkcji/metod przez referencje (zwykłe lub stałe), metody niemodyfikujące zawartości klasy powinny być oznaczane jako const.
    +? [1pkt] Wszystkie metody, które mogą być stałe proszę aby były

Uwaga:
    co się da na listę inicjalizacyjną konstruktora
**/

using namespace std;
class Vector
{
    size_t dataSize;
    size_t dataCapacity;
    unique_ptr<Fraction[]> data;
public:
    explicit Vector(size_t initialCapacity = 0);
    Vector(const Vector& vector);
    Vector(Vector&& vector) noexcept;

    size_t size() const;
    size_t capacity() const;

    void push_back(const Fraction& fraction);

    Vector& operator=(const Vector& vector);
    Vector& operator=(Vector&& vector) noexcept;
    const Fraction operator[](size_t index) const;

    ~Vector() = default;
};

#endif // VECTOR_H
