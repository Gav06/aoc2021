#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    assert(file != NULL);
    char line_buffer[256];

    // first 6 are for gamma, second 6 are for epsilon
    int *ones;
    ones = (int*) calloc(12, sizeof(int));

    int gamma_rate = 0;
    int epsilon_rate = 0;

    while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
        for (int i = 0; i < 12; i++) {
            if (line_buffer[i] == '1') {
                ones[i]++;
            }
        }
    }
    fclose(file);
    free(file);

    for (int i = 0; i < 12; i++) {
        if (i < 6) {
            // gamma calcs

        } else {
            // epsilon calcs

        }
    }

    free(ones);

    printf("Gamma: %d Epsilon: %d\n", gamma_rate, epsilon_rate);
    printf("Result: %d\n", gamma_rate * epsilon_rate);
    return 0;
}