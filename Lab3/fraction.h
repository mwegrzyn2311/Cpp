#ifndef FRACTION_H
#define FRACTION_H

/** Implementacja ulamka:
+ [3pkt] Zaimplementuj klase Ulamek (ang. Fraction), posiadająca licznik (ang. numerator) i mianownik (ang. denominator).
       + Powinna zawierac jeden konstruktor ustawiajacy licznik i mianownik (domyslne wartosci licznika=0 a mianownika domyslna 1)
       + Gettery i settery do wartosci licznika i mianownika
       + operator+ dla ulamka zwracajacy ulamek
       + operator* dla ulamka zwracajacy ulamek
+ [1pkt] Niepoprawny mianownik powinien byc zglaszany przez wyjatek std::invalid_argument.
+ [1pkt] Prosze o skracanie ulamkow po operacji + i * (pomocny moze sie okazac algorytm euklidesa), oczywiscie tutaj robimy tylko dla przypadkow dodatnich
**/

class Fraction
{
    int numerator;
    int denominator;
public:
    explicit Fraction(int numerator=0, int denominator=1);

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int newValue);
    void setDenominator(int newValue);

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
};

#endif // FRACTION_H
