#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    assert(file != NULL);
    char line_buffer[256];

    // first 6 are for gamma, second 6 are for epsilon
    int *common_nums;
    common_nums = (int*) calloc(12, sizeof(int));

    int gamma_rate = 0;
    int epsilon_rate = 0;

    while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
        for (int i = 0; i < 12; i++) {
            if (line_buffer[i] == '1') {
                common_nums[i]++;
            } else {
                common_nums[i] += 0;
            }
            // printf("%c", line_buffer[i]);
        }
        // printf("\n");
    }
    fclose(file);

    // setting gamma rate based on bits
    for (int i = 0; i < 6; i++) {
        // 501 - 1000
        gamma_rate |= common_nums[i] > 500 ? (1 >> (i + 1)) : (0 >> (i + 1));
    }

    for (int i = 6; i < 12; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Gamma: %d Epsilon %d\n");
    printf("Result: %d\n", gamma_rate * epsilon_rate);
    return 0;
}