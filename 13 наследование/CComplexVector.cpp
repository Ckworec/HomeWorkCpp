#include "CComplexVector.hpp"

void ChildClass1 :: output()
{
    ofstream out(file_name.c_str(), std :: ios_base :: app);

    out << "Vector: " << endl;

    for (int j = 0; j < len; j ++)
    {
        out << "(" << m_Real[j] << " + i * " << m_Imaginary[j] << ")   ";
    }

    out << endl;
}

void ChildClass2 :: output()
{
    ofstream out(file_name.c_str(), ios_base :: app);

    out << "Vector: " << endl;

    for (int j = 0; j < len; j ++)
    {
        out << "(" << m_Real[j] << " + i * " << m_Imaginary[j] << ")\n";
    }
        
    out << endl;
}

CComplexVector :: CComplexVector()
{
    len = 0;
}

CComplexVector :: CComplexVector(int length, string filename)
{
    len = length;
    file_name = filename;

    for (int i = 0; i < len; i ++)
    {
        m_Real.push_back(0);
        m_Imaginary.push_back(0);
    }
}

CComplexVector :: ~CComplexVector()
{

}

ChildClass2 operator+(const CComplexVector &v1, const CComplexVector &v2)
{
    ChildClass2 result(v1.len, v1.file_name);

    for (int i = 0; i < v1.len; i ++)
    {
        result.m_Real[i] = v1.m_Real[i] + v2.m_Real[i];
        result.m_Imaginary[i] = v1.m_Imaginary[i] + v2.m_Imaginary[i];
    }

    result.file_name = v1.file_name;

    result.output();

    return result;
}

ChildClass1 operator-(const CComplexVector &v1, const CComplexVector &v2)
{
    ChildClass1 result(v1.len, v1.file_name);

    for (int i = 0; i < v1.len; i ++)
    {
        result.m_Real[i] = v1.m_Real[i] - v2.m_Real[i];
        result.m_Imaginary[i] = v1.m_Imaginary[i] - v2.m_Imaginary[i];
    }

    result.file_name = v1.file_name;

    result.output();

    return result;
}

CComplexNumber operator*(const CComplexVector &v1, const CComplexVector &v2)
{
    double Real = 0, Imaginary = 0;

    for (int i = 0; i < v1.len; i ++)
    {
        Real += v1.m_Real[i] * v2.m_Real[i] - v1.m_Imaginary[i] * v2.m_Imaginary[i];
        Imaginary += v1.m_Real[i] * v2.m_Imaginary[i] + v1.m_Imaginary[i] * v2.m_Real[i];
    }

    return CComplexNumber(Real, Imaginary);
}

 CComplexVector& CComplexVector :: operator=(const CComplexVector& vector)
 {
    if (this == &vector) 
		return *this;

	len = vector.len;

	for (int k = 0; k < len; ++ k)
        {
            m_Imaginary.push_back(vector.m_Imaginary[k]);
            m_Real.push_back(vector.m_Real[k]);
        }
	
	return *this;
 }

 CComplexVector& CComplexVector :: operator=(CComplexVector &&v)
 {
    if (this == &v)
            return *this;

    len = v.len;
    m_Real = move(v.m_Real);
    m_Imaginary = move(v.m_Imaginary);

    return *this;
 }

 ChildClass1& ChildClass1 :: operator=(const ChildClass1& vector)
 {
    if (this == &vector)
                return *this;

        len = vector.len;

        for (int k = 0; k < len; ++ k)
        {
            m_Imaginary.push_back(vector.m_Imaginary[k]);
            m_Real.push_back(vector.m_Real[k]);
        }

        return *this;
 }

 ChildClass1& ChildClass1 :: operator=(ChildClass1 &&v)
 {
    if (this == &v)
            return *this;

    len = v.len;
    m_Real = move(v.m_Real);
    m_Imaginary = move(v.m_Imaginary);

    return *this;
 }

 ChildClass2& ChildClass2 :: operator=(const ChildClass2& vector)
 {
    if (this == &vector)
                return *this;

        len = vector.len;

        for (int k = 0; k < len; ++ k)
        {
            m_Imaginary.push_back(vector.m_Imaginary[k]);
            m_Real.push_back(vector.m_Real[k]);
        }

        return *this;
 }

 ChildClass2& ChildClass2 :: operator=(ChildClass2 &&v)
 {
    if (this == &v)
            return *this;

    len = v.len;
    m_Real = move(v.m_Real);
    m_Imaginary = move(v.m_Imaginary);

    return *this;
 }

 CComplexNumber CComplexVector :: operator[](int index)
 {
    double re = m_Real[index];
    double im = m_Imaginary[index];

    return CComplexNumber(re, im);
 }

 void CComplexVector :: Input(const char *FileName, vector<CComplexVector *> &v)
 {
    ifstream f(FileName); 
    string str;

    while (getline(f, str))
    {
        stringstream ss(str);
        istream_iterator<string> it;
        string name;
        it = ss;
		
        if (it != istream_iterator<string>())
        {
            if (fabs(stod(*it)) < eps)
            {
                ChildClass1 *w = new ChildClass1;

                int i;
                ++it;

                name = (*it);

                (*w).file_name = name;

                ofstream out(name.c_str(), ios_base :: trunc);
                out.close();

                ++it;
				
                for (i = 0; /*i < vector[i] -> len && */it != istream_iterator<string>(); ++it)
                {
                    if (i % 2 == 0)
                    {
                        (*w).m_Real.push_back(stod(*it));
                    }
                    else
                    {
                        (*w).m_Imaginary.push_back(stod(*it));
                    }

                    (*w).len ++;

                    i ++;
                }

                (*w).id_children = 0;

                (*w).len /= 2;

                v.push_back(w);
            }
            if (fabs(stod(*it) - 1) < eps)
            {
                ChildClass2 *w = new ChildClass2;
                
                int i;
                ++it;

                name = (*it);

                ofstream out(name.c_str(), ios_base :: trunc);
                out.close();

                (*w).file_name = name;

                ++it;
				
                for (i = 0; /*i < vector[i] -> len && */it != std :: istream_iterator<std :: string>(); ++it)
                {
                    if (i % 2 == 0)
                    {
                        (*w).m_Real.push_back(stod(*it));
                    }
                    else
                    {
                        (*w).m_Imaginary.push_back(stod(*it));
                    }

                    (*w).len ++;

                    i ++;
                }

                (*w).id_children = 1;

                (*w).len /= 2;

                v.push_back(w);
            }
        }
    }
}

void ChildClass1 :: show()
{
    cout << "ChildClass1: " << file_name << endl;

    for (int i = 0; i < len; i ++)
    {
        cout << "(" << m_Real[i] << " + i * " << m_Imaginary[i] << ")   ";
    }

    cout << endl;
}

void ChildClass2 :: show()
{
    cout << "ChildClass2: " << file_name << endl;

    for (int i = 0; i < len; i ++)
    {
        cout << "(" << m_Real[i] << " + i * " << m_Imaginary[i] << ")   ";
    }

    cout << endl;
}
