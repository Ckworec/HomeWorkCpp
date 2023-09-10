#include <iostream>
#include <ostream>
#include "CComplecsVector.h"
#include <ctime>
#define lenght 5

int main()
{
    double *Real1, *Imaginary1, *Real2, *Imaginary2, sum = 0;

    Real1 = (double *) malloc (sizeof(double) * lenght);
    Imaginary1 = (double *) malloc (sizeof(double) * lenght);
    Real2 = (double *) malloc (sizeof(double) * lenght);
    Imaginary2 = (double *) malloc (sizeof(double) * lenght);

    std :: cout << " Vector 1: (";

    srand(time(NULL));

    for (int i = 0; i < lenght; ++ i)
    {
        Real1[i] = rand() / static_cast<double>(RAND_MAX); //static_cast - переводит из инта в дабл
        Imaginary1[i] = rand() / static_cast<double>(RAND_MAX);
        Real2[i] = rand() / static_cast<double>(RAND_MAX);
        Imaginary2[i] = rand() / static_cast<double>(RAND_MAX);
        std :: cout << "(" << Real1[i] << "," << Imaginary1[i] << ") ";
    }

    std :: cout << ")\n Vector 2: (";

    for (int i = 0; i < lenght; i ++)
    {
        std :: cout << "(" << Real2[i] << "," << Imaginary2[i] << ") ";
    }

    std :: cout << ")\n Sum: vector1 + vector2 = (";

    for (int i = 0; i < lenght; ++ i)
    {
        CComplexVector vector1(Real1[i], Imaginary1[i]), vector2(Real2[i], Imaginary2[i]);

        std :: cout << " " << vector1 + vector2;
    }

    std :: cout << ")\n Difference: vector1 - vector2 = (";

    for (int i = 0; i < lenght; ++ i)
    {
        CComplexVector vector1(Real1[i], Imaginary1[i]), vector2(Real2[i], Imaginary2[i]);

        std :: cout << " " << vector1 - vector2;
    }

    std :: cout << ")\n Multiplication: vector1 * vector2 = ";

    for (int i = 0; i < lenght; ++ i)
    {
        CComplexVector vector1(Real1[i], Imaginary1[i]), vector2(Real2[i], Imaginary2[i]);

        sum += vector1 * vector2;
    }

    std :: cout << sum << "\n";

    free(Real1);
    free(Imaginary1);
    free(Real2);
    free(Imaginary2);
}