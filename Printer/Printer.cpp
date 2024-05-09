#include "Printer.h"
#include <iostream>

using namespace std;

void Printer::printMatrix(int **matrix, int n)
{
    cout << endl
         << "------- Matriz -------" << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }

    cout << endl;
}

void Printer::printVector(int *vector, int size)
{
    cout << endl
         << "------- Vetor -------" << endl
         << endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << vector[i];
        if (i != size - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl
         << endl;
}