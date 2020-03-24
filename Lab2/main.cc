#include <iostream>
#include <gtest/gtest.h>

#include "utils/programmerDetails.h"
#include "utils/argumentParsing.h"


/** Tresc zadan dla Panstwa:

Zadanie 0: absolutnie obowiazkowe, chociaz bez punktow
1) Pierwsza rzecza jest poprawa bledow kompilacji, czyli wpisanie poprawnych Panstwa danych w pliku: programmerDetails.h
2) Oddanne kolokwium musi sie bezwzglednie kompilowac, jesli sie nie skompiluje to jest to 0 punktow za kolokwium!
   Oczywiscie w razie problemow z kompilacja prosze pisać
3) Dobrze, jesli nie byloby warningow kompilacji, ale za to nie obnizam punktow.
4) Proszę aby się program nie crashował podczas testów, jesli ktoś nie umie zrobić danego zagadnienia, to przynajmniej żeby program się nie wywalał.
5) Mam program antyplagiatowy, dlatego prosze pracowac samodzielnie! Osoby ktore udostepniaja swoje rozwiazania rowniez beda mialy kare!

Zadanie 1: patrz plik: matrix.h
**/

int main(int argc, char* argv[])
{
	StudentsInfo::validateStudentsInfo();

    ArgumentParsing::reactToProgramArgumentsPossibilyExit(argc, argv);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
