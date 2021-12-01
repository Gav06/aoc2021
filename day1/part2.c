#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    printf("AoC 2021 Day 1 Solution (Part 2)\n");

    // Reading all of the depths from file
    // (Taken from part 1)
    int depths[2000];

    FILE *file = fopen("input.txt", "r");
    char line_buffer[256];

    assert(file != NULL);

    int i = 0;
    while ((fgets(line_buffer, sizeof(line_buffer), file)) != NULL) {
        depths[i] = atoi(line_buffer);
        i++;
    }
    fclose(file);
    free(file);

    int window[3];
    int times_increased = 0;
    int prev_sum;
    int sum;

    for (int i = 0; i < 2000; i++) {
        window[0] = window[1];
        window[1] = window[2];
        window[2] = depths[i];
        // if the window has no empty values
        if (window[0] != 0 && window[1] != 0 && window[2] != 0) {
            prev_sum = sum;
            sum = window[0] + window[1] + window[2];
            printf("%d %d %d", window[0], window[1], window[2]);

            if (sum > prev_sum) {
                printf(" (increased)\n");
                times_increased++;
            } else if (sum < prev_sum) {
                printf(" (decreased)\n");
            } else {
                printf(" (no change)\n");
            }
        }
    }

    printf("Window sum increased %d times.\n", times_increased);

    return 0;
}