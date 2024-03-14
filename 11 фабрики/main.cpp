#include "CRat.hpp"

int main(void)
{
    vector<CRat *> v;
    vector<CFabric *> fabric;
    ChildClass1 child1;
    ChildClass2 child2;
    Rat RatN;
    int command = 0, i, j;

    fabric.push_back(new CFabric1);
    fabric.push_back(new CFabric2);

    CRat :: Input("data.txt", v, fabric);

    cout << "1. Fold \n2. Subtract \n3. Multiply \n" << endl;

    cout << "Enter a command: ";
    cin >> command;

    while (command != 0)
    {
        if (command == 1)
        {
            cout << "Enter the index of the vector you want to fold: ";
            cin >> i >> j;

            (*v[i]).show();
            (*v[j]).show();

            child2 = (*v[i]) + (*v[j]);

            child2.show();
            cout << "\n" << endl;
        }

        else if (command == 2)
        {
            cout << "Enter the index of the vector you want to substract: ";
            cin >> i >> j;

            (*v[i]).show();
            (*v[j]).show();

            child1 = (*v[i]) - (*v[j]);

            child1.show();
            cout << "\n" << endl;
        }

        else if (command == 3)
        {
            cout << "Enter the index of the vector you want to multiplied: ";
            cin >> i >> j;

            (*v[i]).show();
            (*v[j]).show();

            RatN = (*v[i]) * (*v[j]);

            cout << RatN;
        }

        cout << "Enter a command: ";
        cin >> command;
    }

    for (size_t i = 0; i < v.size(); i ++)
    {
        (*v[i]).output();
        delete v[i];
    }

    return 0;
}
