#include "RandomGraph/RandomGraph.h"
#include "Printer/Printer.h"
#define N 10

using namespace std;

int main(int, char *[])
{

    int n = N;

    RandomGraph *graph = new RandomGraph(n);

    Printer printer;

    int **adjMatrix = graph->getAdjMatrix();

    printer.printMatrix(adjMatrix, n);

    int *vector = graph->getVector();
    int size = graph->getSizeVector();

    printer.printVector(vector, size);

    for (int i = 0; i < n; ++i)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete vector;
    delete graph;

    return 0;
}