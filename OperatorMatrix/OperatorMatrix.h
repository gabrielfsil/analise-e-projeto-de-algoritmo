#ifndef OPERATORMATRIX_H
#define OPERATORMATRIX_H

#include <utility>
using namespace std;

class OperatorMatrix
{

public:
    OperatorMatrix(){};
    ~OperatorMatrix(){};
    int **multiply(int *vetor1, int *vetor2, int n);
    int *sum(int *vetor1, int *vetor2, int n);
    int convertToIndex(int i, int j, int n);
    std::pair<int,int> convertToPair(int k, int n);
    std::pair<int,int> convertToPairPA(int k, int n);

    
};

#endif