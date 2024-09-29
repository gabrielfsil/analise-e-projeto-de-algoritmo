#include "RandomGraph/RandomGraph.h"
#include "OperatorMatrix/OperatorMatrix.h"
#include "Printer/Printer.h"
#include <iostream>
#define N 10

using namespace std;

int main(int, char *[])
{

    int n = N;
    Printer printer;

    RandomGraph *graph = new RandomGraph(n);

    int **adjMatrix1 = graph->generateAdjMatrix(n);

    int **adjMatrix2 = graph->generateAdjMatrix(n);

    cout << "Representação Matricial" << endl;
    printer.printMatrix(adjMatrix1, n);
    printer.printMatrix(adjMatrix2, n);

    int *vector1 = graph->generateVectorFromAdjMatrix(adjMatrix1);
    int size1 = graph->getSizeVector();

    int *vector2 = graph->generateVectorFromAdjMatrix(adjMatrix2);
    int size2 = graph->getSizeVector();

    cout << "Representação Vetorial" << endl;
    printer.printVector(vector1, size1);
    printer.printVector(vector2, size2);

    int *indexVector1 = graph->generateIndexVectorFromVector(vector1);
    int sizeIndex1 = graph->getSizeIndexVector();

    int *indexVector2 = graph->generateIndexVectorFromVector(vector2);
    int sizeIndex2 = graph->getSizeIndexVector();

    cout << "Representação de Índices" << endl;
    printer.printVector(indexVector1, sizeIndex1);
    printer.printVector(indexVector2, sizeIndex2);

    int **adjMatrixFromIndexVector1 = graph->generateAdjMatrixFromIndexVector(indexVector1);

    int **adjMatrixFromIndexVector2 = graph->generateAdjMatrixFromIndexVector(indexVector2);

    cout << "Representação Matricial a partir de Índices" << endl;
    printer.printMatrix(adjMatrixFromIndexVector1,n);
    printer.printMatrix(adjMatrixFromIndexVector2,n);

    OperatorMatrix operatorMatrix;

    cout << "Soma de Vetores" << endl;
    int *vectorSum = operatorMatrix.sum(vector1, vector2, n);
    printer.printVector(vectorSum, size1);

    cout << "Multiplicação de Matrizes" << endl;
    int **matrixMultiplication = operatorMatrix.multiply(vector1, vector2, n);
    printer.printMatrix(matrixMultiplication, n);

    for (int i = 0; i < n; ++i)
    {
        delete[] adjMatrixFromIndexVector1[i];
        delete[] adjMatrixFromIndexVector2[i];
        delete[] adjMatrix1[i];
        delete[] adjMatrix2[i];
        delete[] matrixMultiplication[i];
    }
    delete[] adjMatrix1;
    delete[] adjMatrix2;
    delete[] adjMatrixFromIndexVector1;
    delete[] adjMatrixFromIndexVector2;
    delete[] matrixMultiplication;
    
    delete[] vector1;
    delete[] vector2;
    delete[] indexVector1;
    delete[] indexVector2;
    delete[] vectorSum;
    delete graph;

    return 0;
}
