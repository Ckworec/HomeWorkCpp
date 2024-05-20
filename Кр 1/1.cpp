#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <iterator>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

class Matrix {
public:
    vector<vector<int>> data;
    int size;

    Matrix(string n){
        stringstream ss(n);
        istream_iterator<string> it;
        it = ss;
        vector<int> elements;
        while (it != istream_iterator<string>())
        {
            elements.push_back(stoi(*it));
            ++it;
        }
        size = sqrt(elements.size());
        data.resize(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = elements[i * size + j];
            }
        }
    }

    int Trace() {
        int trace = 0;
        for (int i = 0; i < size; i++) {
            trace += data[i][i];
        }
        return trace;
    }

    void Write(ofstream& file, const int& k) {
        if (k > 0)
        {
            file << "Positive\n";
        }
        else if (k < 0)
        {
            file << "Negative\n";
        }
        else
        {
            file << "Zero\n";
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file << data[i][j] << " ";
            }
            file << endl;
        }
    }
};

class Positive : public Matrix {
public:
    Positive(string n) : Matrix(n) {}
};

class Zero : public Matrix {
public:
    Zero(string n) : Matrix(n) {}
};

class Negative : public Matrix {
public:
    Negative(string n) : Matrix(n) {}
};

int main() {
    ifstream inputFile("matrices.txt");
    ofstream outputFile("output.txt");

    string n;
    while (getline(inputFile, n)) {
        Negative matrix(n);
        if (matrix.Trace() > 0) {
            Positive positiveMatrix(n);
            positiveMatrix.data = matrix.data;
            positiveMatrix.Write(outputFile,1);
        } else if (matrix.Trace() == 0) {
            Zero zeroMatrix(n);
            zeroMatrix.data = matrix.data;
            zeroMatrix.Write(outputFile,0);
        } else {
            matrix.Write(outputFile,-1);
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
