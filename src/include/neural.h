#ifndef NEURAL_H
#define NEURAL_H

#define INPUT_SIZE 3
#define OUTPUT_SIZE 1

typedef struct {
    double synaptic_weights[INPUT_SIZE][OUTPUT_SIZE];
} NeuralNetwork;

void initialize(NeuralNetwork* nn);
double sigmoid(double x);
double sigmoid_derivative(double x);
void train(NeuralNetwork* nn, double training_set_inputs[][INPUT_SIZE], double training_set_outputs[][OUTPUT_SIZE], int num_trials);
double think(NeuralNetwork* nn, double inputs[INPUT_SIZE]);

#endif
