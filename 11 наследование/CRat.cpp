#include "CRat.hpp"

void ChildClass1 :: output()
{
    ofstream out(file_name.c_str(), std :: ios_base :: app);

    out << "Vector: " << endl;

    for (int j = 0; j < len; j ++)
    {
        out << "(" << numerator[j] << " / " << denumerator[j] << ")   ";
    }

    out << endl;
}

void ChildClass2 :: output()
{
    ofstream out(file_name.c_str(), ios_base :: app);

    out << "Vector: " << endl;

    for (int j = 0; j < len; j ++)
    {
        out << "(" << numerator[j] << " / " << denumerator[j] << ")\n";
    }
        
    out << endl;
}

CRat :: CRat()
{
    len = 0;
}

CRat :: CRat(int length, string filename)
{
    len = length;
    file_name = filename;

    for (int i = 0; i < len; i ++)
    {
        numerator.push_back(0);
        denumerator.push_back(0);
    }
}

CRat :: ~CRat()
{

}

ChildClass2 operator+(const CRat &v1, const CRat &v2)
{
    ChildClass2 result(v1.len, v1.file_name);
    int n;


    for (int i = 0; i < v1.len; i ++)
    {
        result.numerator[i] = v1.numerator[i] * v2.denumerator[i] + v2.numerator[i] * v1.denumerator[i];
        result.denumerator[i] = v1.denumerator[i] * v2.denumerator[i];

        n = nod(result.numerator[i], result.denumerator[i]);

        result.numerator[i] /= n;
        result.denumerator[i] /= n;
    }

    result.file_name = v1.file_name;

    result.output();

    return result;
}

ChildClass1 operator-(const CRat &v1, const CRat &v2)
{
    ChildClass1 result(v1.len, v1.file_name);
    int n;

    for (int i = 0; i < v1.len; i ++)
    {
        result.numerator[i] = v1.numerator[i] * v2.denumerator[i] - v2.numerator[i] * v1.denumerator[i];
        result.denumerator[i] = v1.denumerator[i] * v2.denumerator[i];

        n = nod(result.numerator[i], result.denumerator[i]);

        result.numerator[i] /= n;
        result.denumerator[i] /= n;
    }

    result.file_name = v1.file_name;

    result.output();

    return result;
}

Rat operator*(const CRat &v1, const CRat &v2)
{
    int num = 0, denum = 0, sum_n = 0, sum_d = 0, n;

    for (int i = 0; i < v1.len; i ++)
    {
        num = v1.numerator[i] * v2.denumerator[i] + v1.denumerator[i] * v2.numerator[i];
        denum = v1.denumerator[i] * v2.denumerator[i];

        n = nod(num, denum);
        num /= n;
        denum /= n;

        sum_n = sum_n * denum + sum_n * num;
        sum_d = sum_d * denum;

        n = nod(sum_d, sum_n);
        sum_d /= n;
        sum_n /= n;
    }

    return Rat(num, denum);
}

 CRat& CRat :: operator=(const CRat& vector)
 {
    if (this == &vector) 
		return *this;

	len = vector.len;

	for (int k = 0; k < len; ++ k)
        {
            denumerator.push_back(vector.denumerator[k]);
            numerator.push_back(vector.numerator[k]);
        }
	
	return *this;
 }

 CRat& CRat :: operator=(CRat &&v)
 {
    if (this == &v)
            return *this;

    len = v.len;
    numerator = move(v.numerator);
    denumerator = move(v.denumerator);

    return *this;
 }

 ChildClass1& ChildClass1 :: operator=(const ChildClass1& vector)
 {
    if (this == &vector)
                return *this;

        len = vector.len;

        for (int k = 0; k < len; ++ k)
        {
            denumerator.push_back(vector.denumerator[k]);
            numerator.push_back(vector.numerator[k]);
        }

        return *this;
 }

 ChildClass1& ChildClass1 :: operator=(ChildClass1 &&v)
 {
    if (this == &v)
            return *this;

    len = v.len;
    numerator = move(v.numerator);
    denumerator = move(v.denumerator);

    return *this;
 }

 ChildClass2& ChildClass2 :: operator=(const ChildClass2& vector)
 {
    if (this == &vector)
                return *this;

        len = vector.len;

        for (int k = 0; k < len; ++ k)
        {
            denumerator.push_back(vector.denumerator[k]);
            numerator.push_back(vector.numerator[k]);
        }

        return *this;
 }

 ChildClass2& ChildClass2 :: operator=(ChildClass2 &&v)
 {
    if (this == &v)
            return *this;

    len = v.len;
    numerator = move(v.numerator);
    denumerator = move(v.denumerator);

    return *this;
 }

 Rat CRat :: operator[](int index)
 {
    double re = numerator[index];
    double im = denumerator[index];

    return Rat(re, im);
 }

 void CRat :: Input(const char *FileName, vector<CRat *> &v)
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
				
                for (i = 0; it != istream_iterator<string>(); ++it)
                {
                    if (i % 2 == 0)
                    {
                        (*w).numerator.push_back(stod(*it));
                    }
                    else
                    {
                        (*w).denumerator.push_back(stod(*it));
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
				
                for (i = 0; it != std :: istream_iterator<std :: string>(); ++it)
                {
                    if (i % 2 == 0)
                    {
                        (*w).numerator.push_back(stod(*it));
                    }
                    else
                    {
                        (*w).denumerator.push_back(stod(*it));
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
        cout << "(" << numerator[i] << " / " << denumerator[i] << ")   ";
    }

    cout << endl;
}

void ChildClass2 :: show()
{
    cout << "ChildClass2: " << file_name << endl;

    for (int i = 0; i < len; i ++)
    {
        cout << "(" << numerator[i] << " / " << denumerator[i] << ")   ";
    }

    cout << endl;
}

int nod(int a, int b)
{
    if (a < b) 
    {
        swap(a, b);
    }

    if (b) 
    {
        return nod(b, a % b);
    } 
    else 
    {
        return a;
    }
}