#include "OperatorMatrix.h"
#include "../RandomGraph/RandomGraph.h"
#include <iostream>
#include <cmath>

using namespace std;

int OperatorMatrix::convertToIndex(int i, int j, int n)
{
    int index = 0;

    if (i < j)
    {
        index = (i * (2 * n - i - 1)) / 2 + (j - i - 1);
    }
    else
    {
        index = (j * (2 * n - j - 1)) / 2 + (i - j - 1);
    }

    return index;
}

int OperatorMatrix::convertToIndexItr(int i, int j, int n)
{
    if( i==j) return -1;
    
    if (i > j) 
    {
        int tmp = i;
        i = j;
        j = tmp;
    }

    int index = 0;

    for (int k = 0; k < i; k++)
    {
        index += n - k - 1;
    }

    return index + (j - i - 1);
}

int OperatorMatrix::sumIndex(int i, int n)
{
    if(i == 0) return 0;

    return n - i + this->sumIndex(i - 1, n);
}

int OperatorMatrix::convertToIndexRec(int i, int j, int n)
{
    if( i==j) return -1;
    
    if (i > j) 
    {
        int tmp = i;
        i = j;
        j = tmp;
    }

    return this->sumIndex(i, n) + (j - i - 1);
}


std::pair<int, int> OperatorMatrix::convertToPair(int k, int n)
{
    int row = floor((2*n - 1 - sqrt((2*n - 1)*(2*n - 1) - 8*k))/2);
    int soma = (row*(2*n - row - 1))/2;

    int col = k - soma + row + 1;
    
    return make_pair(row, col);
}

std::pair<int, int> OperatorMatrix::convertToPairPA(int k, int n)
{
    int sum = 0;
    int row = 0;
    while (sum <= k)
    {
        sum += n - row - 1;
        row++;
    }
    row--;

    int col = k - row * n + row * (row + 1) / 2 + row + 1;

    return make_pair(row, col);
}

int *OperatorMatrix::sum(int *vetor1, int *vetor2, int n)
{
    int tam = (n * (n - 1))/2;

    int *result = new int[tam];
    

    for (int i = 0; i < tam; i++)
    {
        result[i] = vetor1[i] + vetor2[i];
    }
    
    return result;
}

int **OperatorMatrix::multiply(int *vetor1, int *vetor2, int n)
{
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n]();
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int temp = 0;
            for(int x = 0; x < n; x++)
            {
                int a = 0;
                int b = 0;

                if(x > i){
                    int k = this->convertToIndex(i, x, n);
                    a = vetor1[k];
                }
                else if(x < i){
                    int k = this->convertToIndex(x, i, n);
                    a = vetor1[k];
                }

                if(j > x){
                    int k = this->convertToIndex(x, j, n);
                    b = vetor2[k];
                }
                else if(j < x){
                    int k = this->convertToIndex(j, x, n);
                    b = vetor2[k];
                }

                temp += a * b;
            }
            matrix[i][j] = temp;
            temp = 0;
        }
    }

    return matrix;
}

