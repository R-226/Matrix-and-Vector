#include <iostream>
#include "matrix.hpp"
using namespace std;

int main(void)
{
    mvector a(3), b(3), c(3), d(3);
    matrix A(3, 3), B(3, 3), C(3, 3), D(3, 3), E(3, 3);
    double result;
    for (int i = 0; i < 3; i++)
    {
        a.elements[i] = i + 1;
        b.elements[i] = 3 - i;
        for (int j = 0; j < 3; j++)
        {
            A.elements[i][j] = j + 1;
            B.elements[i][j] = i + 1;
        }
    }
    c = a + b;
    d = a - b;
    for (int i = 0; i < 3; i++)
    {
        cout << a.elements[i];
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << b.elements[i];
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << c.elements[i];
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << d.elements[i];
    }
    cout << endl;
    cout << a * b << endl;
    C = A + B;
    D = A - B;
    E = A * B;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A.elements[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << B.elements[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << C.elements[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << D.elements[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << E.elements[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}