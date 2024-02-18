#include "CComplexVector.hpp"

CComplexNumber :: CComplexNumber() : CComplexNumber :: CComplexNumber(1, 1) {}

CComplexNumber :: CComplexNumber(double Real, double Imaginary)
{
    m_Real = Real;
    m_Imaginary = Imaginary;
}

CComplexNumber :: ~CComplexNumber()
{
    
}

std :: ostream& operator<<(std :: ostream &out, const CComplexNumber& vector) // задаем оператор для вывода
{
    out << vector.m_Real << " + i * " << vector.m_Imaginary << "\n";

    return out;
}