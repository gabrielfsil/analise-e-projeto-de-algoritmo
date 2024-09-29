#include <iostream>
#include <cmath>
using namespace std;

// Função analítica para mapear k para (i, j)
pair<int, int> vetorParaParAnalitico(int k, int n) {
    int i = floor((-1 + sqrt(1 + 8 * k)) / 2); // Encontra o maior i tal que a soma até i não excede k
    int soma = (i * (i + 1)) / 2; // Soma dos primeiros i elementos
    int j = k - soma + i + 1; // Calcula j diretamente

    cout << "Row: " << (sqrt(2 * k)) << endl;
    return make_pair(i, j);
}

int main() {
    int n = 5; // Ordem da matriz
    int k;

    cout << "Digite o índice k do vetor: ";
    cin >> k;

    if (k < 0 || k >= (n * (n - 1)) / 2) {
        cout << "Índice fora do intervalo do triângulo superior!" << endl;
    } else {
        pair<int, int> par = vetorParaParAnalitico(k, n);
        cout << "O índice " << k << " corresponde ao par ordenado (" << par.first << ", " << par.second << ") na matriz." << endl;
    }

    return 0;
}
