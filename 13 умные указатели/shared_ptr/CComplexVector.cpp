#include "CComplexVector.h"
#include <ctime>
#include <memory>
#include <string>

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
    m_Real = std :: shared_ptr<double []>(new double[len]);
    m_Imaginary = std :: shared_ptr<double []>(new double [len]);

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

    m_Real = std::shared_ptr<double[]>(new double[len]);
    m_Imaginary = std::shared_ptr<double[]>(new double[len]);

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
}

CComplexVector :: ~CComplexVector()
{
    //delete []m_Imaginary;
    //delete []m_Real;
    std :: cout << "Destructor" << std :: endl;
}

CComplexNumber :: ~CComplexNumber()
{
    
}

CComplexVector CComplexVector :: operator+(const CComplexVector &vector)
{
    CComplexVector result(N);

    result.len = vector.len;

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

CComplexVector& CComplexVector :: operator=(CComplexVector &&v)
{
    if (this == &v)
            return *this;

    len = v.len;
    m_Real = std :: move(v.m_Real);
    m_Imaginary = std :: move(v.m_Imaginary);


    return *this;
}

CComplexVector :: CComplexVector(CComplexVector &&v) :
    CComplexVector(v.len)
{
    m_Real = std :: move(v.m_Real);
    m_Imaginary = std :: move(v.m_Imaginary);
}

CComplexVector :: CComplexVector(const CComplexVector &vect) :
    CComplexVector(vect.len)
{
        for (int k = 0; k < len; ++k)
        {
            m_Real[k] = vect.m_Real[k];
            m_Imaginary[k] = vect.m_Imaginary[k];
        }
        //std::cout << "Copy constructor" << *this << std::endl;
}
