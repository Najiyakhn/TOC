#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, len;

    // Input string
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Print prefixes
    printf("\nPrefixes:\n");
    for (i = 1; i <= len; i++) {
        for (j = 0; j < i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }

    // Print suffixes
    printf("\nSuffixes:\n");
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }

    // Print substrings
    printf("\nSubstrings:\n");
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            int k;
            for (k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }

    return 0;
}

