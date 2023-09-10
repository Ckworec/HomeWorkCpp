#include "CComplexVector.h"

CComplexVector :: CComplexVector()
{
    len = 0;
    m_Real = NULL;
    m_Imaginary = NULL;
}

CComplexNumber :: CComplexNumber() : CComplexNumber :: CComplexNumber(1, 1) {}

CComplexVector :: CComplexVector(int num)
{
    len = num;
	m_Real = new double[num];
    m_Imaginary = new double[num];

	for (int k = 0; k < len; ++ k)
    {
		m_Imaginary[k] = rand() / static_cast<double>(RAND_MAX);
        m_Real[k] = rand() / static_cast<double>(RAND_MAX);
    }

    //std :: cout << "Constructor" << std :: endl; // endl - тоже самое что и \n
}

CComplexVector& CComplexVector :: operator=(const CComplexVector &vect)
{
	if (this == &vect) 
		return *this;

	len = vect.len;

	for (int k = 0; k < len; ++ k)
    {
		m_Imaginary[k] = vect.m_Imaginary[k];
        m_Real[k] = vect.m_Real[k];
    }
	
	return *this;
}

CComplexNumber :: CComplexNumber(double Real, double Imaginary)
{
    m_Real = Real;
    m_Imaginary = Imaginary;
    //std :: cout << "Constructor" << std :: endl; // endl - тоже самое что и \n
}

CComplexVector :: ~CComplexVector()
{
    //std :: cout << "Destructor for " << *this << std :: endl;
	delete []m_Imaginary;
    delete []m_Real;
	//std :: cout << "Destructor" << std :: endl;
}

CComplexNumber :: ~CComplexNumber()
{
        //std :: cout << "Destructor" << std :: endl;
}

CComplexVector CComplexVector :: operator+(const CComplexVector &vector)
{
    CComplexVector result(N);

    for (int i = 0; i < N; i ++)
    {
        result.m_Imaginary[i] = m_Imaginary[i] + vector.m_Imaginary[i];
        result.m_Real[i] = m_Real[i] + vector.m_Real[i];
    }

    return result;
}

CComplexVector CComplexVector :: operator-(const CComplexVector &vector)
{
    CComplexVector result(N);

    for (int i = 0; i < N; i ++)
    {
        result.m_Imaginary[i] = m_Imaginary[i] - vector.m_Imaginary[i];
        result.m_Real[i] = m_Real[i] - vector.m_Real[i];
    }

    return result;
}

CComplexNumber CComplexVector :: operator*(const CComplexVector &vector)
{
    double Real = 0, Imaginary = 0;

    for (int i = 0; i < N; i ++)
    {
        Real += m_Real[i] * vector.m_Real[i] - m_Imaginary[i] * vector.m_Imaginary[i];
        Imaginary += m_Real[i] * vector.m_Imaginary[i] + m_Imaginary[i] * vector.m_Real[i];
    }

    return CComplexNumber(Real, Imaginary);
}

std :: ostream& operator<<(std :: ostream &out, const CComplexVector& vector) // задаем оператор для вывода
{
    for (int i = 0; i < N; i ++)
        out << vector.m_Real[i] << " + i * " << vector.m_Imaginary[i] << "; ";

    return out;
}

std :: ostream& operator<<(std :: ostream &out, const CComplexNumber& vector) // задаем оператор для вывода
{
    out << vector.m_Real << " + i * " << vector.m_Imaginary << "\n";

    return out;
}

void CComplexVector :: copyFrom(const CComplexVector &v) // функция копирования
{
    for (int i = 0; i < N; i ++)
    {
        m_Real[i] = v.m_Real[i];
        m_Imaginary[i] = v.m_Imaginary[i];
    }
}

void CComplexNumber :: copyFrom(const CComplexNumber &v) // функция копирования
{
        m_Real = v.m_Real;
        m_Imaginary = v.m_Imaginary;
}
