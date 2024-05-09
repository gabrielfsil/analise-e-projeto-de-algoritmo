#ifndef RANDOMGRAPH_H
#define RANDOMGRAPH_H

class RandomGraph
{
private:
    int **adjMatrix;
    int **generateAdjcencyMatrix(int n);

public:
    RandomGraph(int n);
    ~RandomGraph(){};
    int **getAdjMatrix() { return this->adjMatrix; };
};

#endif