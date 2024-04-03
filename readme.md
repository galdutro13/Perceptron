# README
## Perceptron em C++
Este repositório contém uma implementação simples de um Perceptron em C++. O código é estruturado da seguinte forma:

````
#include <iostream>

// Classe Perceptron
class Perceptron {
private:
int dimention;
double* weights;
double theta;
double learningRate;
const double bias = 1.0;

    // Função que calcula o 'dot product'
    inline double dot_product(int index, const int* dataset) {
        // Código omitido por brevidade
    }

    // Função que atualiza os pesos
    inline bool ch_weights(int OUT, int TARGET, int index, const int* dataset) {
        // Código omitido por brevidade
    }

    // Função de ativação
    [[nodiscard]] inline int act_func(double y_in) const {
        // Código omitido por brevidade
    }

    // Loop interno do código de treinamento
    bool i_train(int dataset_size, int* dataset, int* target) {
        // Código omitido por brevidade
    }

public:

    Perceptron(int dimention, double learningRate, double theta)
            : dimention(dimention), learningRate(learningRate), theta(theta), weights(new double[dimention + 1]{}) {}

    ~Perceptron() {
        delete[] weights;
    }

    // Loop externo do código de treinamento
    void train(int dataset_size, int* dataset, int* target) {
        // Código omitido por brevidade
    }

    // Função para predizer o resultado
    int predict(const int* dataset) {
        // Código omitido por brevidade
    }

    void print_weights() {
        // Código omitido por brevidade
    }
};

int main() {
// Código omitido por brevidade
}
````
### Como usar
Para utilizar este código, você deve criar uma instância da classe Perceptron, passando a dimensão dos dados, a taxa de aprendizado e o valor de theta no construtor. Em seguida, você pode treinar o Perceptron usando o método train, passando o tamanho do conjunto de dados, o conjunto de dados e o vetor alvo. Você também pode usar o método predict para fazer previsões com o Perceptron treinado.
### Exemplo
No método main, temos um exemplo de como usar a classe Perceptron. Primeiro, criamos uma instância do Perceptron com dimensão 2, taxa de aprendizado 1.0 e theta 0.2. Em seguida, treinamos o Perceptron com um conjunto de dados de entrada e um vetor alvo. Finalmente, imprimimos os pesos do Perceptron treinado.
