#include <iostream>
#include <ostream>
#define N 5

class CComplexVector
{
    private:
        double *m_Real[N];
        double *m_Imaginary[N];
    public:
        CComplexVector();
        CComplexVector(double Real, double Imaginary);

        ~CComplexVector();

        CComplexVector operator+(const CComplexVector &vector);
        CComplexVector operator-(const CComplexVector &vector);
        double operator*(const CComplexVector &vector);
        void copyFrom(const CComplexVector &v);
        friend std :: ostream& operator<<(std :: ostream &out, const CComplexVector& vector);
};