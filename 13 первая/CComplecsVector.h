#include <iostream>
#include <ostream>
#define N 5

class CComplexNumber
{
    private:
        double m_Real;
        double m_Imaginary;
    public:
        CComplexNumber();
        CComplexNumber(double Real, double Imaginary);

        ~CComplexNumber();
        
        void copyFrom(const CComplexNumber &v);
        friend std :: ostream& operator<<(std :: ostream &out, const CComplexNumber& vector);
};

class CComplexVector
{
    private:
        double m_Real[N];
        double m_Imaginary[N];
    public:
        CComplexVector();
        CComplexVector(double Real[N], double Imaginary[N]);

        ~CComplexVector();

        CComplexVector operator+(const CComplexVector &vector);
        CComplexVector operator-(const CComplexVector &vector);
        CComplexNumber operator*(const CComplexVector &vector);
        void copyFrom(const CComplexVector &v);
        friend std :: ostream& operator<<(std :: ostream &out, const CComplexVector& vector);
        friend class CComplexNumber;
};
