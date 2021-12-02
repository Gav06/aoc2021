#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * part2 is just part1 with slightly different
 * calculations, so i just pasted part1 into this
 */

// Instruction opcodes
#define FORWARD 0
#define DOWN 1
#define UP 2

struct instruction {
    int opcode;
    int amount;
};

int main() {
    int horizontal_pos = 0;
    int depth_pos = 0;
    int aim = 0;

    // Our array of instructions should have a length of 1000
    // because there are 1000 lines in the input file
    struct instruction insns[1000];

    // Reading lines from input file, and processing them into instructions
    // (mostly code from day1)
    FILE *file = fopen("input.txt", "r");
    char line_buffer[256];
    
    assert(file != NULL);

    int i = 0;
    while ((fgets(line_buffer, sizeof(line_buffer), file)) != NULL) {
        struct instruction insn;
        // Split should currently be the name of the instruction
        char *split = strtok(line_buffer, " ");
        
        // Check if result == 0 because strcmp returns 0 if the strings are equal
        if (strcmp(split, "forward") == 0) {
            insn.opcode = FORWARD;
        } else if (strcmp(split, "up") == 0) {
            insn.opcode = UP;
        } else if (strcmp(split, "down") == 0) {
            insn.opcode = DOWN;
        } else {
            printf("Error processing instruction opcode (line #%s)\n", i + 1);
            insn.opcode = -1;
        }

        // printf("opcode: %d %d\n", insn.opcode, i);

        // Getting the next token in the split (number value)
        split = strtok(NULL, " ");
        int value = atoi(split);
        printf("%s %d\n", line_buffer, value);
        insn.amount = value;
        insns[i] = insn;
        i++;
    }

    fclose(file);
    free(file);

    // Process instructions
    for (int i = 0; i < 1000; i++) {
        struct instruction insn = insns[i];
        
        switch (insn.opcode) {
            case FORWARD:
                horizontal_pos += insn.amount;
                depth_pos += aim * insn.amount;
                break;
            case UP:
                aim -= insn.amount;
                break;
            case DOWN:
                aim += insn.amount;
                break;
        }
    }

    // multiply horizontal and depth values to get the answer
    int value = horizontal_pos * depth_pos;
    printf("Final depth * final horizontal: %d\n", value);

    return 0;
}