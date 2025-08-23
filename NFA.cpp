implement NFA over alphabet {0,1} that accepts ll the string that contain substring 001
#include <stdio.h>
#include <string.h>

#define STATES 4   // q0, q1, q2, q3

int main() {
    char str[100];
    int current[STATES] = {0}; // active states
    int next[STATES];
    int i, j;

    printf("Enter a binary string: ");
    scanf("%s", str);

    // Start with q0 active
    current[0] = 1;

    // Process each character
    for (i = 0; i < strlen(str); i++) {
        char ch = str[i];

        // Reset next states
        for (j = 0; j < STATES; j++) next[j] = 0;

        // For every active state, apply transitions
        for (j = 0; j < STATES; j++) {
            if (current[j]) {
                switch (j) {
                    case 0: // q0
                        if (ch == '0') {
                            next[0] = 1; // stay in q0
                            next[1] = 1; // move to q1
                        } else if (ch == '1') {
                            next[0] = 1; // stay in q0
                        }
                        break;

                    case 1: // q1
                        if (ch == '0') next[2] = 1;
                        break;

                    case 2: // q2
                        if (ch == '0') next[2] = 1;
                        else if (ch == '1') next[3] = 1;
                        break;

                    case 3: // q3 (accepting)
                        next[3] = 1; // remain accepted
                        break;
                }
            }
        }

        // Copy next to current
        for (j = 0; j < STATES; j++) current[j] = next[j];
    }

    // Check if accepting state q3 is active
    if (current[3] == 1)
        printf("? String Accepted (contains substring 001)\n");
    else
        printf("? String Rejected (does not contain substring 001)\n");

    return 0;
}

