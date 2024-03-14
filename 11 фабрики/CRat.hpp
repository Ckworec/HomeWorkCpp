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

class Rat
{
    private:
        int num;
        int denum;
    public:
        Rat();
        Rat(int Real, int Imaginary);
        Rat(const Rat &n)
        {
            num = n.num;
            denum = n.denum;
        }
        Rat(Rat &&n)
        {
            num = n.num;
            denum = n.denum;
        }

        ~Rat();
        
        friend std :: ostream& operator<<(std :: ostream &out, const Rat& vector);
        Rat& operator=(const Rat& n)
        {
            num = n.num;
            denum = n.denum;

            return *this;
        }
        friend class CRat;
};

class CRat
{
    public:
        int len = 0;
        int id_children;
        string file_name;
        vector<int> numerator;
        vector<int> denumerator;

        CRat();
        CRat(int len, string file_name);
        CRat(const CRat &v)
        {
            len = v.len;
            id_children = v.id_children;
            file_name = v.file_name;
            numerator = v.numerator;
            denumerator = v.denumerator;
        }

        virtual ~CRat();

        CRat& operator=(const CRat& vector);
        CRat& operator=(CRat&& vector);

        static void Input(const char *filename, vector<CRat *> &v, vector<CFabric *> &fabric);
        virtual void output() = 0;
        virtual void show() = 0;

        Rat operator[](int index);
};

class ChildClass1 : public CRat
{
    public:
        ChildClass1() : CRat() {};
        ChildClass1(int len, string filename) : CRat(len, filename) {};
        ~ChildClass1() {};
        ChildClass1(const ChildClass1 &v) : CRat(v) {};

        ChildClass1& operator=(const ChildClass1& vector);
        ChildClass1& operator=(ChildClass1&& vector);

        virtual void output();
        void show();
};

class ChildClass2 : public CRat
{
    public:
        ChildClass2() : CRat() {};
        ChildClass2(int len, string filename) : CRat(len, filename) {};
        ~ChildClass2() {};
        ChildClass2(const ChildClass2 &v) : CRat(v) {};

        ChildClass2& operator=(const ChildClass2& vector);
        ChildClass2& operator=(ChildClass2&& vector);

        virtual void output();
        void show();
};

class CFabric
{
    public:
    virtual CRat *Create() = 0;
    virtual ~CFabric() {};
};

class CFabric1 : public CFabric
{
    public:
        virtual CRat *Create() {return new ChildClass1;}
};

class CFabric2 : public CFabric
{
    public:
        virtual CRat *Create() {return new ChildClass2;}
};

ChildClass2 operator+(const CRat &v1, const CRat &v2);
ChildClass1 operator-(const CRat &v1, const CRat &v2);
Rat operator*(const CRat &v1, const CRat &v2);
int nod(int a, int b);