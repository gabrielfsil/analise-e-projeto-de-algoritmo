#ifndef RANDOMGRAPH_H
#define RANDOMGRAPH_H

class RandomGraph
{
private:
    int numVertices;
    int numEdges;
    int **adjMatrix;
    int *vector;
    int *indexVector;
    int **generateAdjMatrix(int n);
    int *generateVectorFromAdjMatrix();
    int *generateIndexVectorFromVector();

public:
    RandomGraph(int n);
    ~RandomGraph(){};
    int **getAdjMatrix() { return this->adjMatrix; };
    int *getVector() { return this->vector; };
    int *getIndexVector() { return this->indexVector; };
    int getSizeVector();
    int getSizeIndexVector() { return this->numEdges; };
};

#endif