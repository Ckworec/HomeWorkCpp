#include "CComplexVector.hpp"

int main(void)
{
    vector<CComplexVector *> v;
    vector<CFabric *> fabric;
    ChildClass1 child1;
    ChildClass2 child2;
    CComplexNumber ComplexN;
    int command = 0, i, j, num;

    srand(time(NULL));


    fabric.push_back(new CFabric1);
    fabric.push_back(new CFabric2);

    CComplexVector :: Input("data.txt", v, fabric);

    cout << "1. Fold \n2. Subtract \n3. Multiply \n4. Generate\n" << endl;

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

            //auto start = chrono::steady_clock::now();

            child2 = (*v[i]) + (*v[j]);

            //auto end = chrono::steady_clock::now();

            //std::cout << "Runtime is " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsec\n";

            child2.show();
            cout << "\n" << endl;
        }

        else if (command == 2)
        {
            cout << "Enter the index of the vector you want to substract: ";
            cin >> i >> j;

            (*v[i]).show();
            (*v[j]).show();

            //auto start = chrono::steady_clock::now();

            child1 = (*v[i]) - (*v[j]);

            //auto end = chrono::steady_clock::now();

           // std::cout << "Runtime is " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsec\n";

            child1.show();
            cout << "\n" << endl;
        }

        else if (command == 3)
        {
            cout << "Enter the index of the vector you want to multiplied: ";
            cin >> i >> j;

            (*v[i]).show();
            (*v[j]).show();

            ComplexN = (*v[i]) * (*v[j]);

            cout << ComplexN;
        }

        else if (command == 4)
        {
            cout << "Enter the number of the vector you want to create: ";
            cin >> num;

            for (int k = 0; k < num; k ++)
            {
                CComplexVector :: Generate(fabric, v);
            }

            for (int k = 0; k < num; k ++)
            {
                (*v[k]).show();
            }
        }

        cout << "Enter a command: ";
        cin >> command;
        cout << endl;
    }

    for (size_t i = 0; i < v.size(); i ++)
    {
        (*v[i]).output();
        delete v[i];
    }

    for (size_t i = 0; i < fabric.size(); i ++)
        delete fabric[i];


    return 0;
}
