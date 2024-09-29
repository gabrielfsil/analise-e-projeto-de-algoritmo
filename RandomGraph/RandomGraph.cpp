#include "RandomGraph.h"
#include "../RandomNumber/RandomNumber.h"
#include <cmath>
#include <iostream>

using namespace std;

RandomGraph::RandomGraph(int n)
{
    this->numVertices = n;
    this->numEdges = n * 2;
    this->adjMatrix = this->generateAdjMatrix();
    this->vector = this->generateVectorFromAdjMatrix();
    this->indexVector = this->generateIndexVectorFromVector();
}

int **RandomGraph::generateAdjMatrix()
{
    int **matrix = new int *[this->numVertices];
    for (int i = 0; i < this->numVertices; i++)
    {
        matrix[i] = new int[this->numVertices]();
    }

    int m = this->numEdges;

    while (m > 0)
    {

        RandomNumber generator;

        int i = generator.random(0, this->numVertices - 1);
        int j = generator.random(0, this->numVertices - 1);

        if (i != j && matrix[i][j] == 0)
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
            m--;
        }
    }

    this->adjMatrix = matrix;

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

    this->vector = binaryVector;

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

    this->indexVector = indexVector;

    return indexVector;
}

int **RandomGraph::generateAdjMatrixFromIndexVector()
{
    int **matrix = new int *[this->numVertices];
    for (int i = 0; i < this->numVertices; i++)
    {
        matrix[i] = new int[this->numVertices]();
    }

    for (int a = 0; a <= this->numEdges - 1; a++)
    {
        int k = this->indexVector[a];

        int soma = 0;
        int row = 0;
        while(soma <= k){
            soma += this->numVertices - row - 1;
            row++;
        }
        row--;

        int col = k - row* this->numVertices + row*(row + 1)/2 + row + 1;

        matrix[row][col] = 1;
        matrix[col][row] = 1;
    }

    return matrix;
}