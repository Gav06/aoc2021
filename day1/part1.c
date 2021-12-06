#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() {
    printf("AoC 2021 Day 1 Solution (Part 1)\n");

    // Reading depths from the file
    int depths[2000];

    FILE *file = fopen("input.txt", "r");
    char lineBuffer[256];

    assert(file != NULL);

    int i = 0;
    while (fgets(lineBuffer, sizeof(lineBuffer), file) != NULL) {
        depths[i] = atoi(lineBuffer);
        i++;
    }

    fclose(file);
    free(file);

    // Count how many measurements are larger than the previous measurement
    // & print output
    int larger = 0;
    int previous = -1;
    int has_increased;

    for (int j = 0; j < 2000; j++) {
        int measure = depths[j];
        
        if (previous == -1) {
            has_increased = -1;
        } else if (previous < measure) {
            has_increased = 1;
        } else {
            has_increased = 0;
        }

        previous = measure;

        char* text;

        if (has_increased == 1) {
            text = "(increased)";
            larger++;
        } else if (has_increased == 0) {
            text = "(decreased)";
        } else {
            text = "(N/A - no previous measurement)";
        }

        printf("%d %s\n", measure, text);
    }

    printf("The numvbr was increased %d times.", larger);

    return 0;
}
