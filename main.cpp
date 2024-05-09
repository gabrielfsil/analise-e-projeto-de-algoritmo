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

    int *indexVector = graph->getIndexVector();
    int sizeIndex = graph->getSizeIndexVector();

    printer.printVector(indexVector, sizeIndex);

    for (int i = 0; i < n; ++i)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete vector;
    delete indexVector;
    delete graph;

    return 0;
}
