#include <iostream>
#include "RandomGraph/RandomGraph.h"
#define N 10

using namespace std;

int main(int, char *[])
{

    int n = N;

    RandomGraph *graph = new RandomGraph(n);

    int **adjMatrix = graph->getAdjMatrix();

    cout << "------- Matriz de Adjacência -------" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << ",";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete graph;

    return 0;
}
