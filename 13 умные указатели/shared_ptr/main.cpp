#include <iostream>
#include <ostream>
#include "CComplexVector.h"
#include <ctime>
#include <memory>
#include <string>

int main()
{
    CComplexVector vector1(N), vector2(N), vector3(N);

    std :: cout << "\n Vector1 : (" << vector1 << ")\n\n" << " Vector2 : (" << vector2 << ")" << std :: endl;

    vector3 = vector1 + vector2;

    std :: cout << "--1--" << std :: endl;

    std :: cout << "\n Sum: vector1 + vector2 = ( " << vector3 << ")" << std :: endl;

    vector3 = vector1 - vector2;

    vector3 = vector3;

    std :: cout << "\n Difference: vector1 - vector2 = (" << " " << vector3<< ")" << std :: endl;

    std :: cout << "\n Multiplication: vector1 * vector2 = " << vector1 * vector2 << std :: endl;

    std::cout << "\n Test vecor: " << vector3 << std::endl;
}
