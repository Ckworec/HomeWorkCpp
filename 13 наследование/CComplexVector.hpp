#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <math.h>
#define eps 1e-20
using namespace std;

class CComplexNumber
{
    private:
        double m_Real;
        double m_Imaginary;
    public:
        CComplexNumber();
        CComplexNumber(double Real, double Imaginary);

        ~CComplexNumber();
        
        friend std :: ostream& operator<<(std :: ostream &out, const CComplexNumber& vector);
        friend CComplexVector;
};

class CComplexVector
{
    public:
        int len;
        int id_children;
        const char* file_name;
        double *m_Real;
        double *m_Imaginary;

        CComplexVector();
        CComplexVector(int len, const char* file_name);

        virtual ~CComplexVector();

        CComplexVector& operator=(const CComplexVector& vector);
        CComplexVector& operator=(CComplexVector&& vector);

        static void Input(const char *filename, vector<CComplexVector> &vector);
        virtual void output(const char* filename) = 0;

        CComplexNumber& operator[](int index);
};

class ChildClass1 : public CComplexVector
{
    public:
        ChildClass1() : CComplexVector() {};
        ChildClass1(int len, const char *filename) : CComplexVector(len, filename) {};

        CComplexVector& operator=(const CComplexVector& vector);
        CComplexVector& operator=(CComplexVector&& vector);

        virtual void output(const char* filename);
        void show();
};

class ChildClass2 : public CComplexVector
{
    public:
        ChildClass2() : CComplexVector() {};
        ChildClass2(int len, const char *filename) : CComplexVector(len, filename) {};

        CComplexVector& operator=(const CComplexVector& vector);
        CComplexVector& operator=(CComplexVector&& vector);

        virtual void output(const char* filename);
        void show();
};

ChildClass2 operator+(const CComplexVector &v1, const CComplexVector &v2);
ChildClass1 operator-(const CComplexVector &v1, const CComplexVector &v2);
CComplexNumber operator*(const CComplexVector &v1, CComplexVector &v2); 