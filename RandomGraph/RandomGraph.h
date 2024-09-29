#ifndef RANDOMGRAPH_H
#define RANDOMGRAPH_H

using namespace std;

class RandomGraph
{
private:
    int numVertices;
    int numEdges;

public:
    RandomGraph(int n);
    ~RandomGraph(){};

    int getSizeVector();
    int getSizeIndexVector() { return this->numEdges; };

    int **generateAdjMatrix(int n);
    int *generateVectorFromAdjMatrix(int **matrix);
    int *generateIndexVectorFromVector(int *vector);
    int **generateAdjMatrixFromIndexVector(int *indexVector);
};

#endif