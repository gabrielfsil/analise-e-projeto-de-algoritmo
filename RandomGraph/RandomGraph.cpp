#include "RandomGraph.h"
#include "../RandomNumber/RandomNumber.h"

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
    int size = (this->numVertices * (this->numVertices - 1)) / 2;

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