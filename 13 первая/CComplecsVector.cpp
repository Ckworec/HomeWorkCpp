#include "CComplecsVector.h"

CComplexVector :: CComplexVector()
{
    for (int i = 0; i < N; i ++)
    {
        m_Real[i] = 0;
        m_Imaginary[i] = 0;
    }
}

CComplexNumber :: CComplexNumber() : CComplexNumber :: CComplexNumber(1, 1) {}

CComplexVector :: CComplexVector(double Real[N], double Imaginary[N])
{
    for (int i = 0; i < N; i ++)
    {
        m_Real[i] = Real[i];
        m_Imaginary[i] = Imaginary[i];
    }
    //std :: cout << "Constructor" << std :: endl; // endl - тоже самое что и \n
}

CComplexNumber :: CComplexNumber(double Real, double Imaginary)
{
    m_Real = Real;
    m_Imaginary = Imaginary;
    //std :: cout << "Constructor" << std :: endl; // endl - тоже самое что и \n
}

CComplexVector :: ~CComplexVector()
{
	//std :: cout << "Destructor" << std :: endl;
}

CComplexNumber :: ~CComplexNumber()
{
        //std :: cout << "Destructor" << std :: endl;
}

CComplexVector CComplexVector :: operator+(const CComplexVector &vector)
{
    double Real[N], Imaginary[N];

    for (int i = 0; i < N; i ++)
    {
            Real[i] = this -> m_Real[i] + vector.m_Real[i];
            Imaginary[i] = this -> m_Imaginary[i] + vector.m_Imaginary[i];
    }

    return CComplexVector(Real, Imaginary);
}

CComplexVector CComplexVector :: operator-(const CComplexVector &vector)
{
    double Real[N], Imaginary[N];

    for (int i = 0; i < N; i ++)
    {
            Real[i] = this -> m_Real[i] - vector.m_Real[i];
            Imaginary[i] = this -> m_Imaginary[i] - vector.m_Imaginary[i];
    }

    return CComplexVector(Real, Imaginary);
}

CComplexNumber CComplexVector :: operator*(const CComplexVector &vector)
{
    double Real = 0, Imaginary = 0;

    for (int i = 0; i < N; i ++)
    {
        Real = m_Real[i] * vector.m_Real[i] - m_Imaginary[i] * vector.m_Imaginary[i];
        Imaginary = m_Real[i] * vector.m_Imaginary[i] + m_Imaginary[i] * vector.m_Real[i];
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
