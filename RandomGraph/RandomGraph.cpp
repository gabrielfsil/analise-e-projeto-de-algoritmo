#include "RandomGraph.h"
#include "../RandomNumber/RandomNumber.h"

using namespace std;

RandomGraph::RandomGraph(int n)
{
    this->adjMatrix = this->generateAdjcencyMatrix(n);
}

int **RandomGraph::generateAdjcencyMatrix(int n)
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