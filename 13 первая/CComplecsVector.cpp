#include "CComplecsVector.h"

CComplexVector :: CComplexVector() : CComplexVector :: CComplexVector(1, 1) {}

CComplexVector :: CComplexVector(double Real, double Imaginary)
{
    m_Real = Real;
    m_Imaginary = Imaginary;
	//std :: cout << "Constructor" << std :: endl; // endl - тоже самое что и \n
}

CComplexVector :: ~CComplexVector()
{
	//std :: cout << "Destructor" << std :: endl;
}

CComplexVector CComplexVector :: operator+(const CComplexVector &vector)
{
	return CComplexVector(this -> m_Real + vector.m_Real, this -> m_Imaginary + vector.m_Imaginary);
}

CComplexVector CComplexVector :: operator-(const CComplexVector &vector)
{
	return CComplexVector(this -> m_Real - vector.m_Real, this -> m_Imaginary - vector.m_Imaginary);
}

double CComplexVector :: operator*(const CComplexVector &vector)
{
	return m_Real * vector.m_Real + m_Imaginary * vector.m_Imaginary;
}

std :: ostream& operator<<(std :: ostream &out, const CComplexVector& vector) // задаем оператор для вывода
{
	out << "(" << vector.m_Real << ", " << vector.m_Imaginary << ")";
	return out;
}

void CComplexVector :: copyFrom(const CComplexVector &v) // функция копирования
{
	m_Real = v.m_Real;
	m_Imaginary = v.m_Imaginary;
}