#include "CRat.hpp"

Rat :: Rat() : Rat :: Rat(1, 1) {}

Rat :: Rat(int n, int d)
{
    num = n;
    denum = d;
}

Rat :: ~Rat()
{
    
}

std :: ostream& operator<<(std :: ostream &out, const Rat& vector) // задаем оператор для вывода
{
    out << vector.num << " / " << vector.denum << "\n";

    return out;
}