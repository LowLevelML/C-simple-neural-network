#include <stdlib.h>
#include <math.h>
#include "neural.h"

void initialize(NeuralNetwork* nn) {
    int i, j;
    srand(1);
    for (i = 0; i < INPUT_SIZE; i++)
        for (j = 0; j < OUTPUT_SIZE; j++)
            nn->synaptic_weights[i][j] = 2 * ((double)rand() / RAND_MAX) - 1;
}

double sigmoid(double x) { return 1 / (1 + exp(-x)); }

double sigmoid_derivative(double x) {
    return x * (1 - x);
}

void train(NeuralNetwork* nn, double training_set_inputs[][INPUT_SIZE], double training_set_outputs[][OUTPUT_SIZE], int num_trials) {
    int i, j, k;
    double o, e, a;

    for (i = 0; i < num_trials; i++) {
        for (j = 0; j < OUTPUT_SIZE; j++) {
            o = 0;
            for (k = 0; k < INPUT_SIZE; k++)
                o += training_set_inputs[j][k] * nn->synaptic_weights[k][0];
            o = sigmoid(o);
            e = training_set_outputs[j][0] - o;
            a = training_set_inputs[j][0] * (e * sigmoid_derivative(o));

            for (k = 0; k < INPUT_SIZE; k++) {
                nn->synaptic_weights[k][0] += a;
            }
        }
    }
}

double think(NeuralNetwork* nn, double inputs[INPUT_SIZE]) {
    int i;
    double output = 0;

    for (i = 0; i < INPUT_SIZE; i++)
        output += inputs[i] * nn->synaptic_weights[i][0];

    return sigmoid(output);
}
