#ifndef PRINTER_H
#define PRINTER_H

class Printer
{

public:
    Printer(){};
    ~Printer(){};
    void printMatrix(int **matrix, int n);
    void printVector(int *vector, int size);
};

#endif