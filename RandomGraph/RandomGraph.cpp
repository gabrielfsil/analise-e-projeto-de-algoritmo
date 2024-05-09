#include "RandomGraph.h"
#include "../RandomNumber/RandomNumber.h"

using namespace std;

RandomGraph::RandomGraph(int n)
{
    this->n = n;
    this->adjMatrix = this->generateAdjMatrix(n);
    this->vector = this->generateVectorFromAdjMatrix();
}

int **RandomGraph::generateAdjMatrix(int n)
{
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n]();
    }

    int m = n * 2;

    while (m > 0)
    {

        RandomNumber generator;

        int i = generator.random(0, n - 1);
        int j = generator.random(0, n - 1);

        if (i != j && matrix[i][j] == 0)
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
            m--;
        }
    }

    return matrix;
}

int *RandomGraph::generateVectorFromAdjMatrix()
{
    int size = (this->n * (this->n - 1)) / 2;

    int *binaryVector = new int[size];

    int k = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            binaryVector[k] = this->adjMatrix[i][j];
            k++;
        }
    }

    return binaryVector;
}

int RandomGraph::getSizeVector()
{
    int size = (this->n * (this->n - 1)) / 2;
    
    return size;
}