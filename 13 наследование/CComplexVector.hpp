#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <math.h>
#define eps 1e-20
using namespace std;

class CFabric;

class CComplexNumber
{
    private:
        double m_Real;
        double m_Imaginary;
    public:
        CComplexNumber();
        CComplexNumber(double Real, double Imaginary);
        CComplexNumber(const CComplexNumber &num)
        {
            m_Real = num.m_Real;
            m_Imaginary = num.m_Imaginary;
        }
        CComplexNumber(CComplexNumber &&num)
        {
            m_Real = num.m_Real;
            m_Imaginary = num.m_Imaginary;
        }

        ~CComplexNumber();
        
        friend std :: ostream& operator<<(std :: ostream &out, const CComplexNumber& vector);
        CComplexNumber& operator=(const CComplexNumber& n)
        {
            m_Real = n.m_Real;
            m_Imaginary = n.m_Imaginary;

            return *this;
        }
        friend class CComplexVector;
};

class CComplexVector
{
    public:
        int len = 0;
        int id_children;
        string file_name;
        vector<double> m_Real;
        vector<double> m_Imaginary;

        CComplexVector();
        CComplexVector(int len, string file_name);
        CComplexVector(const CComplexVector &v)
        {
            len = v.len;
            id_children = v.id_children;
            file_name = v.file_name;
            m_Real = v.m_Real;
            m_Imaginary = v.m_Imaginary;
        }

        virtual ~CComplexVector();

        CComplexVector& operator=(const CComplexVector& vector);
        CComplexVector& operator=(CComplexVector&& vector);

        static void Input(const char *filename, vector<CComplexVector *> &v);
        virtual void output() = 0;
        virtual void show() = 0;

        CComplexNumber operator[](int index);
};

class ChildClass1 : public CComplexVector
{
    public:
        ChildClass1() : CComplexVector() {};
        ChildClass1(int len, string filename) : CComplexVector(len, filename) {};
        ~ChildClass1() {};
        ChildClass1(const ChildClass1 &v) : CComplexVector(v) {};

        ChildClass1& operator=(const ChildClass1& vector);
        ChildClass1& operator=(ChildClass1&& vector);

        virtual void output();
        void show();
};

class ChildClass2 : public CComplexVector
{
    public:
        ChildClass2() : CComplexVector() {};
        ChildClass2(int len, string filename) : CComplexVector(len, filename) {};
        ~ChildClass2() {};
        ChildClass2(const ChildClass2 &v) : CComplexVector(v) {};

        ChildClass2& operator=(const ChildClass2& vector);
        ChildClass2& operator=(ChildClass2&& vector);

        virtual void output();
        void show();
};

ChildClass2 operator+(const CComplexVector &v1, const CComplexVector &v2);
ChildClass1 operator-(const CComplexVector &v1, const CComplexVector &v2);
CComplexNumber operator*(const CComplexVector &v1, const CComplexVector &v2);
