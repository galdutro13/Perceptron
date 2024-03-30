#include <iostream>

// Perceptron class
class Perceptron {
private:
    int dimention;

    double* weights;
    double theta;
    double learningRate;

    const double bias = 1.0;

    inline double dot_product(int index, const int* dataset) {
        int t_index = index * dimention;
        double dotp = 0.0;
        for (int i = 0; i < dimention; i++) {
            dotp = dotp + (weights[i] * dataset[t_index]);
            t_index++;
        }

        dotp = dotp + (bias * weights[dimention]);
        return dotp;
    }

    inline bool ch_weights(int OUT, int TARGET, int index, const int* dataset) {
        if (OUT != TARGET) {
            int t_index = index * dimention;
            for (int i = 0; i < dimention; i++) {
                weights[i] = weights[i] + (learningRate * TARGET * dataset[t_index]);
                t_index++;
            }

            weights[dimention] = weights[dimention] + (learningRate * TARGET);
            return true;
        }
        else {
            return false;
        }
    }

    [[nodiscard]] inline int act_func(double y_in) const {
        if (y_in > theta) {
            return 1;
        }
        else if (y_in <= theta && y_in >= (theta - 1)) {
            return 0;
        }
        else {
            return -1;
        }
    }

    bool i_train(int dataset_size, int* dataset, int* target) {
        int a_limit = (dataset_size / dimention);
        double NET;
        int OUT;
        bool wchanged = false;

        for (int i = 0; i < a_limit; i++) {
            NET = dot_product(i, dataset);
            OUT = act_func(NET);
            if (ch_weights(OUT, target[i], i, dataset)) {
                wchanged = true;
            }

        }

        return wchanged;
    }

public:
    Perceptron(int dimention, double learningRate, double theta) {
        this->dimention = dimention;
        this->learningRate = learningRate;
        this->theta = theta;

        weights = new double[dimention + 1];
        for (int i = 0; i < dimention + 1; i++) {
            weights[i] = 0.0;
        }
    }

    ~Perceptron() {
        delete[] weights;
    }

    void train(int dataset_size, int* dataset, int* target) {
        bool weights_changed = true;

        while (weights_changed) {
            weights_changed = i_train(dataset_size, dataset, target);
            // this->learningRate = this->learningRate * 0.80;
        }
    }

    int predict(const int* dataset) {
        double NET = 0.0;
        for (int i = 0; i < dimention; i++) {
            NET = NET + (weights[i] * dataset[i]);
        }

        NET = NET + (bias * weights[dimention]);
        return act_func(NET);
    }

    void print_weights() {
        for (int i = 0; i < dimention; i++) {
            std::cout << "w" << i << " = ";
            std::cout << weights[i] << std::endl;
        }

        std::cout << "w_bias = " << weights[dimention] << std::endl;
    }

};

int main() {

    /*int input[] = { 1, 1, 1, 0, 0, 1, 0, 0 };
    int target[] = { 1, 1, 1, -1 };
    int size = 8;

    double learningrate = 1.0;
    double theta = 0.2;
    int dimention = 2;

    auto* p = new Perceptron(dimention, learningrate, theta);
    p->print_weights();

    p->train(size, input, target);
    p->print_weights();

    delete p;*/

    std::cout << "Teste com letras: " << std::endl;

    int lput[] = {
            'C', 'C', 'B',
            'A', 'A', 'A',
            'A', 'A', 'B',
            'A', 'A', 'C',
            'A', 'B', 'A',
            'A', 'B', 'B',
            'A', 'B', 'C',
            'A', 'C', 'A',
            'A', 'C', 'B',
            'A', 'C', 'C',
            'B', 'A', 'A',
            'B', 'A', 'B',
            'B', 'A', 'C',
            'B', 'B', 'A',
            'B', 'B', 'B',
            'B', 'B', 'C',
            'B', 'C', 'A',
            'B', 'C', 'B',
            'B', 'C', 'C',
            'C', 'A', 'B',
            'C', 'A', 'C',
            'C', 'B', 'A',
            'C', 'B', 'B',
            'C', 'B', 'C',
            'C', 'C', 'A',
            'C', 'A', 'A',
            'C', 'C', 'C'
    };
    int ltarget[] {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                   -1, -1, 1, -1, -1, 1, 1, 1, -1, -1,
                   1, 1, -1};
    auto *pl = new Perceptron(3, 0.05, 0.5);
    pl->print_weights();
    pl->train(81, lput, ltarget);
    pl->print_weights();
    int t[] = {'C', 'A', 'A'};
    int g[] = {'C', 'C', 'C',};
    std::cout << pl->predict(t) << std::endl;
    std::cout << pl->predict(g) << std::endl;




    delete pl;
}
// 'C', 'A', 'A',
//
