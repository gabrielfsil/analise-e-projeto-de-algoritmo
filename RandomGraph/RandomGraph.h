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
    int sumUntilRow(int row);

public:
    RandomGraph(int n);
    ~RandomGraph(){};
    int **getAdjMatrix() { return this->adjMatrix; };
    int *getVector() { return this->vector; };
    int *getIndexVector() { return this->indexVector; };
    int getSizeVector();
    int getSizeIndexVector() { return this->numEdges; };
    int **generateAdjMatrix(int n);
    int *generateVectorFromAdjMatrix();
    int *generateIndexVectorFromVector();
    int **generateAdjMatrixFromIndexVector();
    int mapIndex(int row, int col);
    int mapRow(int index);
    int mapColumn(int index, int row);
};

#endif