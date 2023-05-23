#include <stdio.h>
#include "./include/neural.h"

#define INPUT_SIZE 3
#define OUTPUT_SIZE 1
#define MAX_ITERATIONS 10000

int main() {
    NeuralNetwork nn;
    int i;

    initialize(&nn);

    printf("Random starting synaptic weight:\n");
    for (i = 0; i < INPUT_SIZE; i++) {
        printf("%f\n", nn.synaptic_weights[i][0]);
    }

    double training_set_input[][INPUT_SIZE] = {
        {0, 0, 1},
        {1, 1, 1},
        {0, 1, 0},
        {1, 0, 0},
        {0, 1, 1}
    };
    double training_set_output[][OUTPUT_SIZE] = {
        {0},
        {1},
        {1},
        {0},
        {1}
    };

    train(&nn, training_set_input, training_set_output, MAX_ITERATIONS);

    printf("New synaptic weights:\n");
    for (i = 0; i < INPUT_SIZE; i++) {
        printf("%f\n", nn.synaptic_weights[i][0]);
    }

    double input[] = {1, 0, 1};
    printf("Under New situation [1, 0, 1]:\n");
    printf("%f\n", think(&nn, input));

    return 0;
}
