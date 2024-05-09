#ifndef RANDOMGRAPH_H
#define RANDOMGRAPH_H

class RandomGraph
{
private:
    int n;
    int **adjMatrix;
    int *vector;
    int **generateAdjMatrix(int n);
    int *generateVectorFromAdjMatrix();

public:
    RandomGraph(int n);
    ~RandomGraph(){};
    int **getAdjMatrix() { return this->adjMatrix; };
    int *getVector() { return this->vector; };
    int getSizeVector();
};

#endif