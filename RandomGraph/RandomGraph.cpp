#include "RandomGraph.h"
#include "../RandomNumber/RandomNumber.h"
#include <cmath>
#include <iostream>

using namespace std;

RandomGraph::RandomGraph(int n)
{
    this->numVertices = n;
    this->numEdges = n * 2;
    this->adjMatrix = this->generateAdjMatrix(n);
    this->vector = this->generateVectorFromAdjMatrix();
    this->indexVector = this->generateIndexVectorFromVector();
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

int *RandomGraph::generateVectorFromAdjMatrix()
{
    int size = this->getSizeVector();

    int *binaryVector = new int[size];

    int k = 0;

    for (int i = 0; i < this->numVertices - 1; i++)
    {
        for (int j = i + 1; j < this->numVertices; j++)
        {
            binaryVector[k] = this->adjMatrix[i][j];
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

int *RandomGraph::generateIndexVectorFromVector()
{
    int sizeIndex = this->numEdges;
    int *indexVector = new int[sizeIndex];

    int size = this->getSizeVector();

    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (this->vector[i] == 1)
        {
            indexVector[k] = i;
            k++;
        }
    }

    return indexVector;
}

int RandomGraph::sumUntilRow(int row)
{
    return (this->numVertices - 1 + this->numVertices - row - 1) * (row + 1) / 2;
}


int RandomGraph::mapIndex(int row, int col)
{
    return this->sumUntilRow(row - 1) + col - row - 1;
}

int RandomGraph::mapRow(int index)
{
    int row = 0;

    while (this->sumUntilRow(row) <= index)
    {
        row++;
    }

    return row;
}

int RandomGraph::mapColumn(int index, int row)
{
    int col = index - this->sumUntilRow(row - 1) + row + 1;

    return col;
}

int **RandomGraph::generateAdjMatrixFromIndexVector()
{
    int **matrix = new int *[this->numVertices];
    for (int i = 0; i < this->numVertices; i++)
    {
        matrix[i] = new int[this->numVertices]();
    }

    for (int i = 0; i <= this->numEdges - 1; i++)
    {
        int index = this->indexVector[i];

        int row = this->mapRow(index);

        int col = this->mapColumn(index, row);

        matrix[row][col] = 1;
        matrix[col][row] = 1;
    }

    return matrix;
}