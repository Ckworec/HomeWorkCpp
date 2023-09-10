#include <iostream>
#include "CComplecsVector.h"
#include <cassert>

void TestCComplexvector()
{
    CComplexVector vector1(1, 2), vector2(3, 4), result(4, 6);
    double res;

    assert(vector1.m_Real + vector2.m_Real == result.m_Real && vector1.m_Imaginary + vector2.m_Imaginary == result.m_Imaginary);

    assert(vector1 + vector2 == result);

    assert(vector1 - vector2 == result);

    assert(vector1 - vector2 == result);

    assert(vector1 * vector2 == res);
    
    assert(vector1 * vector2 == res);
}