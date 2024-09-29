#include <iostream>
using namespace std;

// Função analítica para mapear (i, j) para k
int parParaVetorAnalitico(int i, int j, int n) {
    return (i * (2 * n - i - 1)) / 2 + (j - i - 1);
}

int main() {
    int n = 5; // Ordem da matriz
    int i, j;

    cout << "Digite os índices i e j da matriz: " << endl << "i: ";
    cin >> i;
    cout << "j: ";
    cin >> j;

    if (i < 0 || j < 0 || i >= n || j >= n || i >= j) {
        cout << "Índices inválidos para o triângulo superior!" << endl;
    } else {
        int k = parParaVetorAnalitico(i, j, n);
        cout << "O par (" << i << ", " << j << ") corresponde ao índice " << k << " no vetor." << endl;
    }

    return 0;
}