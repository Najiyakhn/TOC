#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

// Forward declaration
int S();

// Match function
int match(char expected) {
    if (input[pos] == expected) {
        pos++;
        return 1;
    }
    return 0;
}

// Non-terminal S
// Grammar: S ? (S)S | e
int S() {
    int save = pos;

    // Case e (empty string)
    if (pos >= strlen(input))
        return 1;

    // Case (S)S
    if (match('(')) {
        if (S() && match(')')) {
            if (S()) return 1;   // Allow concatenation (SS)
        }
        pos = save; // backtrack if fail
    }

    return 0;
}

int main() {
    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    if (S() && pos == strlen(input))
        printf("? String Accepted (belongs to CFG)\n");
    else
        printf("? String Rejected (does not belong to CFG)\n");

    return 0;
}

