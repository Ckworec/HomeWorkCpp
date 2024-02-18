#include "CComplexVector.hpp"

void ChildClass1 :: output(const char * filename)
{
    ofstream out(filename);

    for (int i = 0; i < len; i ++)
    {
        for (int j = 0; j < len; j ++)
        {
            out << "(" <<m_Real << " + i * " << m_Imaginary << ")   ";;
        }

        out << endl;
    }
}

void ChildClass2 :: output(const char * filename)
{
    ofstream out(filename);

    for (int i = 0; i < len; i ++)
    {
        for (int j = 0; j < len; j ++)
        {
            out << "(" <<m_Real << " + i * " << m_Imaginary << ")\n";;
        }
        
        out << endl;
    }
}

CComplexVector :: CComplexVector()
{
    m_Real = NULL;
    m_Imaginary = NULL;
    len = 0;
}

CComplexVector :: CComplexVector(int length, const char * filename)
{
    len = length;
    file_name = filename;
    m_Real = new double[len];
    m_Imaginary = new double[len];
}

ChildClass2 operator+(const CComplexVector &v1, const CComplexVector &v2)
{
    ChildClass2 result(v1.len, v1.file_name);

    for (int i = 0; i < v1.len; i ++)
    {
        result.m_Real[i] = v1.m_Real[i] + v2.m_Real[i];
        result.m_Imaginary[i] = v1.m_Imaginary[i] + v2.m_Imaginary[i];
    }

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
		m_Imaginary[k] = vector.m_Imaginary[k];
        m_Real[k] = vector.m_Real[k];
    }
	
	return *this;
 }

 CComplexVector& CComplexVector :: operator=(CComplexVector &&v)
 {
    if (this == &v)
            return *this;

    delete []m_Real;
    delete []m_Imaginary;

    len = v.len;
    m_Real = v.m_Real;
    m_Imaginary = v.m_Imaginary;
    v.m_Real = nullptr;
    v.m_Imaginary = nullptr;

    return *this;
 }

 CComplexNumber& CComplexVector :: operator[](int index)
 {
    return CComplexNumber(m_Real[index], m_Imaginary[index]);
 }

 void CComplexVector :: Input(const char *FileName, vector<CComplexVector> &vector)
{
    ifstream f(FileName); 
    string str;
    char sp = ' ';
    string space;

    space = sp;

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

                size_t i; 
                ++it;
                ++it;

                while ((*it) != space)
                {
                    name += *it;
                }

				
                for (i = 0; i < vector[i].len && it != istream_iterator<string>(); ++it) 
                {
                    if (i % 2 == 0)
                    {
                        (*w).m_Real[i ++] = stod(*it);
                    }
                    else
                    {
                        (*w).m_Imaginary[i ++] = stod(*it);
                    }
                }

                (*w).id_children = 0;

				vector.push_back(w);
			}
			if (fabs(stod(*it) - 1) < eps)
			{
				ChildClass2 *w = new ChildClass2; 
                
                size_t i; 
                ++it;
                ++it;

                while ((*it) != space)
                {
                    name += *it;
                }
				
                for (i = 0; i < vector[i].len && it != std :: istream_iterator<std :: string>(); ++it) 
                {
                    if (i % 2 == 0)
                    {
                        (*w).m_Real[i ++] = stod(*it);
                    }
                    else
                    {
                        (*w).m_Imaginary[i ++] = stod(*it);
                    }
                }

                (*w).id_children = 1;

				vector.push_back(w);
			}
		}
	}
}

void ChildClass1 :: show()
{
    cout << "ChildClass1: " << endl;

    for (int i = 0; i < len; i ++)
    {
        cout << "(" << m_Real[i] << " + i * " << m_Imaginary[i] << ")" << endl;
    }
}

void ChildClass2 :: show()
{
    cout << "ChildClass2: " << endl;

    for (int i = 0; i < len; i ++)
    {
        cout << "(" << m_Real[i] << " + i * " << m_Imaginary[i] << ")" << endl;
    }
}