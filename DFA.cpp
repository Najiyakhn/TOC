#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0;  // start state q0
    int i;

    printf("Enter a binary string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        char ch = str[i];

        switch (state) {
            case 0: // q0
                if (ch == '0') state = 1;
                else if (ch == '1') state = 0;
                else {
                    printf("Invalid input!\n");
                    return 0;
                }
                break;

            case 1: // q1
                if (ch == '0') state = 2;
                else if (ch == '1') state = 0;
                break;

            case 2: // q2
                if (ch == '0') state = 2;
                else if (ch == '1') state = 3;  // found "001"
                break;

            case 3: // q3 (accepting)
                state = 3; // stay here no matter what
                break;
        }
    }

    if (state == 3)
        printf("String Accepted (contains substring 001)\n");
    else
        printf("String Rejected (does not contain substring 001)\n");

    return 0;
}

