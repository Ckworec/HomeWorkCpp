#include <iostream>
#include <ostream>
#include "CComplecsVector.h"
#include <ctime>

int main()
{
    double Real1[N], Imaginary1[N], Real2[N], Imaginary2[N];

    std :: cout << " Vector 1: (";

    srand(time(NULL));

    for (int i = 0; i < N; ++ i)
    {
        Real1[i] = rand() / static_cast<double>(RAND_MAX); //static_cast - переводит из инта в дабл
        Imaginary1[i] = rand() / static_cast<double>(RAND_MAX);
        Real2[i] = rand() / static_cast<double>(RAND_MAX);
        Imaginary2[i] = rand() / static_cast<double>(RAND_MAX);
        std :: cout << Real1[i] << " + i * " << Imaginary1[i] << "; ";
    }

    std :: cout << ")\n Vector 2: (";

    for (int i = 0; i < N; i ++)
    {
        std :: cout << Real2[i] << " + i * " << Imaginary2[i] << "; ";
    }

    std :: cout << ")\n Sum: vector1 + vector2 = (";

    for (int i = 0; i < N; ++ i)
    {
        CComplexVector vector1(Real1, Imaginary1), vector2(Real2, Imaginary2);

        std :: cout << " " << vector1 + vector2;
    }

    std :: cout << ")\n Difference: vector1 - vector2 = (";

    for (int i = 0; i < N; ++ i)
    {
        CComplexVector vector1(Real1, Imaginary1), vector2(Real2, Imaginary2);

        std :: cout << " " << vector1 - vector2;
    }

    CComplexVector vector1(Real1, Imaginary1), vector2(Real2, Imaginary2);

    std :: cout << ")\n Multiplication: vector1 * vector2 = ";

    std :: cout << vector1 * vector2 << "\n";
}
