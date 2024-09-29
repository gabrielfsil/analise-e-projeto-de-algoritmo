#include "RandomGraph.h"
#include "../RandomNumber/RandomNumber.h"
#include "../OperatorMatrix/OperatorMatrix.h"
#include <cmath>
#include <iostream>

using namespace std;

RandomGraph::RandomGraph(int n)
{
    this->numVertices = n;
    this->numEdges = n * 2;
}

int **RandomGraph::generateAdjMatrix(int n)
{
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n]();
    }

    int m = this->numEdges;

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

int *RandomGraph::generateVectorFromAdjMatrix(int **matrix)
{
    int size = (this->numVertices * (this->numVertices - 1)) / 2;

    int *binaryVector = new int[size];

    int k = 0;

    for (int i = 0; i < this->numVertices - 1; i++)
    {
        for (int j = i + 1; j < this->numVertices; j++)
        {
            binaryVector[k] = matrix[i][j];
            k++;
        }
    }

    return binaryVector;
}

int RandomGraph::getSizeVector()
{
    int size = (this->numVertices * (this->numVertices - 1)) / 2;

    return size;
}

int *RandomGraph::generateIndexVectorFromVector(int *vector)
{
    int sizeIndex = this->numEdges;
    int *indexVector = new int[sizeIndex];

    int size = (this->numVertices * (this->numVertices - 1)) / 2;

    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (vector[i] == 1)
        {
            indexVector[k] = i;
            k++;
        }
    }

    return indexVector;
}

int **RandomGraph::generateAdjMatrixFromIndexVector(int *indexVector)
{
    int **matrix = new int *[this->numVertices];
    for (int i = 0; i < this->numVertices; i++)
    {
        matrix[i] = new int[this->numVertices]();
    }

    OperatorMatrix operatorMatrix;

    for (int a = 0; a <= this->numEdges - 1; a++)
    {
        int k = indexVector[a];

        pair<int,int> p = operatorMatrix.convertToPair(k, this->numVertices);

        matrix[p.first][p.second] = 1;
        matrix[p.second][p.first] = 1;
    }

    return matrix;
}