# Análise e Projeto de Algoritmo

## Primeiro Trabalho Implementação – APA

1 – Gerar randomicamente um grafo não orientado com 100 vértices , com um número baixo
de ligações ( de uma a dez vezes o número de vértices ).

2 – Implementar um algoritmo que gere a representação matricial ( matriz adjacência binária )

```
    int m = this->numEdges;
    
    while (m > 0)
    {

        RandomNumber generator;

        int i = generator.random(0, n - 1);
        int j = generator.random(0, n - 1);

        if (i != j && matrix[i][j] == 0)
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
            m--;
        }
    }
```

Complexidade:

- **Melhor Caso**: *O(m)*, onde todas as arestas são inseridas rapidamente sem muitas rejeições.
- **Pior Caso**: *O(m×n²)*, onde encontrar uma aresta válida se torna cada vez mais difícil devido à densidade da matriz.

![Matriz de Adjacência](assets/matrix.png)

3 – Implementar um algoritmo que, a partir da matriz, gere a representação vetorial ( vetor
binário )de sua parte triangular superior.

```
    int k = 0;

    for (int i = 0; i < this->numVertices - 1; i++)
    {
        for (int j = i + 1; j < this->numVertices; j++)
        {
            binaryVector[k] = this->adjMatrix[i][j];
            k++;
        }
    }
```
Complexidade:

- *O(n²)*, o algoritmo percorre o triângulo superior da matriz de adjacência, o que envolve $n*(n - 1)/2$ iterações no total


![Vetor Binário](assets/vector.png)

4 – Gerar o vetor compactado ( vetor de índices inteiros ) com endereçamento indireto.

```
    int size = (this->numVertices * (this->numVertices - 1)) / 2;

    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (this->vector[i] == 1)
        {
            indexVector[k] = i;
            k++;
        }
    }
```

Complexidade:

- *O(n²)*: O algoritmo percorre todos os *O(n²)* elementos do vetor vector, realizando uma comparação e, possivelmente, uma atribuição de índice. Como o número de elementos cresce quadraticamente com o número de vértices no grafo, a complexidade do algoritmo também é quadrática.

![Vetor de Índices](assets/index-vector.png)

5 – Implementar um algoritmo que a partir do vetor compactado gere a matriz de adjacência.

```
    for (int a = 0; a <= this->numEdges - 1; a++)
    {
        int k = this->indexVector[a];

        int sum = 0;
        int row = 0;
        while(sum <= k){
            sum += this->numVertices - row - 1;
            row++;
        }
        row--;

        int col = k - row* this->numVertices + row*(row + 1)/2 + row + 1;

        matrix[row][col] = 1;
        matrix[col][row] = 1;
    }
```

Complexidade:

- **Melhor Caso**: *O($m*n$)*, no caso de um grafo esparso, com poucas arestas, a complexidade será menor, proporcional a *O(n)*
- **Pior Caso**: *O(n³)*, para um grafo completo

![Transformação de Vetor de Índice em Matriz de Adjacência](assets/reverse.png)

6 – Implementar a função de mapeamento que a partir da entrada (i,j) da matriz de adjacência
de ordem n acesse a posição k do vetor de índices. Implementar o cálculo analítico (
progressão aritmética ) e também os procedimentos iterativo e recursivo.

![Mapeamento](assets/mapping.png)

7 – Implementar a função de mapeamento inversa que a partir do índice k do vetor acesse a
posição (i,j) da matriz de adjacência de ordem n. Implementar o cálculo analítico ( algoritmo
raiz quadrada ) e também o procedimento iterativo.

![Mapeamento](assets/reverse-mapping.png)

8 – Implementar as operações de soma ( operação de união ) , produto direto ( operação de
interseção ) entre duas matrizes utilizando suas respectivas representações vetoriais.

Obs.: Todos os algoritmos devem ser testados bem como determinado as suas funções de
complexidade.

## Execução

Clonar o repositório:

```
git clone git@github.com:gabrielfsil/analise-e-projeto-de-algoritmo.git
```

Acessar a pasta do projeto:

```
cd analise-e-projeto-de-algoritmo
```

Para compilar o projeto basta executar o comando na pasta raiz do projeto

```
make
```

E para executar:

```
./bin/main
```