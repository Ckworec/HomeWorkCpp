#include "CComplexVector.hpp"

int main(void)
{
    vector<CComplexVector> vector;
    ChildClass1 child1;
    ChildClass2 child2;
    CComplexNumber ComplexN;
    int command = 0, i, j;

    CComplexVector :: Input("data.txt", vector);

    cout << "1. Fold \n2. Subtract \n3. Multiply \n4" << endl;

    cout << "Enter a command: ";
    cin >> command;

    while (command != 0)
    {
        if (command == 1)
        {
            cout << "Enter the index of the vector you want to fold: ";
            cin >> i >> j;

            child2 = vector[i] + vector[j];

            child2.show();
        }

        else if (command == 2)
        {
            cout << "Enter the index of the vector you want to substract: ";
            cin >> i >> j;

            child1 = vector[i] - vector[j];

            child1.show();
        }

        else if (command == 3)
        {
            cout << "Enter the index of the vector you want to multiplied: ";
            cin >> i >> j;

            ComplexN = vector[i] * vector[j];

            cout << ComplexN;
        }
    }


    return 0;
}