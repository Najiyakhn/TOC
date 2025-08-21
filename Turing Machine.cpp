#include <stdio.h>
#include <string.h>

#define MAX 100

char tape[MAX];
int head = 0;

// Move head right until find symbol
int moveRightUntil(char c) {
    while (tape[head] != '\0') {
        if (tape[head] == c) return 1;
        head++;
    }
    return 0;
}

// Move head left until find symbol
void moveLeftUntilStart() {
    while (head > 0 && tape[head] != 'X') head--;
    if (head > 0) head--; // step back to search for next 0
}

int main() {
    printf("Enter a binary string: ");
    scanf("%s", tape);

    int len = strlen(tape);

    while (1) {
        head = 0;

        // Step 1: find leftmost 0
        while (head < len && (tape[head] == 'X' || tape[head] == 'Y'))
            head++;

        if (head >= len) {
            // All symbols are marked
            printf("? String Accepted (equal number of 0s followed by 1s)\n");
            return 0;
        }

        if (tape[head] != '0') {
            printf("? String Rejected (does not belong to L)\n");
            return 0;
        }

        // Mark 0 as X
        tape[head] = 'X';

        // Step 2: find matching 1
        head++;
        while (head < len && tape[head] != '1')
            head++;

        if (head >= len) {
            printf("? String Rejected (no matching 1 found)\n");
            return 0;
        }

        // Mark 1 as Y
        tape[head] = 'Y';
    }
}

