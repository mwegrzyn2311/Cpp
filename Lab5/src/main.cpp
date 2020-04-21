#include <iostream>
#include <gtest/gtest.h>

/** Zadanie implementacyjne:
1. Prosze w pliku include/mylist.h dokonac nastepujacej implementacji:
  Proszę o zaimplementowanie szablonu klasy MyList<T>, reprezentujacej liste jednokierunkowa
  z glowa i iteratorami.
    Punktacja przydzielana za nastepujace metody (jak testy):
    1. za konstruktor bezargumentowy i metode size() zwracajaca ilosc elementow
    2. za metody push_front i pop_front, ktore odpowiednio dodaja/usuwaja element z poczatku
    3. metode front() zwracajaca element na poczatku,
       oraz aby pop_front() zwracala usuniety element
    4. jesli pierwszy wezel (o nazwie head), oraz kazdy nastepny wezel (head->next)
       sa zaimplementowane przy pomocy unique_ptr<MyList::Node>
    5. jesli w razie zawolania pop_front na pustej liscie zostal wyrzucony wyjatek std::out_of_range
    6. jesli kopiowanie (konstruktor kopiujacy i operator przypisania) jest niemozliwe dla listy
    7. jesli mamy zaimplementowane metody iteratora
       (tutaj jeszcze nie musza w pelni dzialac, chociaz powinny zwracac co nalezy)
    8. jesli napisany iterator dziala z petla for-zakresowym
    9. jesli nasz iterator dziala z algorytmami standardowymi na przykladzie std::count_if
   10. jesli mamy metode remove(T element), ktora usuwa wszystkie elementy z listy o danej wartosci
   11. jesli lista ma operator wypisywania na strumien
       (forma wydruku dowolna, byleby byly wszystkie elementy)

Prosze o zaimplementowanie pliku mySorting.h
W nim prosze o zaimplementowanie szablonu funkcji globalnej mySort:
    Punktacja (analogicznie jak testy):
    1. Sortowanie statycznej tablicy dziala
    2. Dziala z kontenerami standardowymi (na przykladzie std::vector)
    3. Dziala z nasza lista - specjalizacja
    4. Specjalizacja sortowania dla tablicy char[][]
       jesli dziala dla tablicy slow skladajacych sie wylacznie z DUZYCH LITER
    5. Jw. ale powinno dzialac z pominieciem wielkosci liter.

--------- sprawdzane ręcznie:
    [1pkt] klasa wzorcowa powinna w całości być zdefiniowana w odpowiednim pliku
    nagłówkowym, z tymze w klasie tylko deklaracje, a poza klasa definicje metod.
    Funkcje skladowe zawierajace jedna linie (czyli najczesciej jedna instrukcje)
    moga byc zdefiniowane w klasie.

Dodam, ze struktura projektu wraz z CMake'iem dostarczona przez pana Michala,
ktory zgodzil sie aby byla na nastepne zadania.
**/

int main(int argc, char* argv[])
{
    StudentsInfo::validateStudentsInfo();

    ArgumentParsing::reactToProgramArgumentsPossibilyExit(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
