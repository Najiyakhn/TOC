#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push onto stack
void push(char c) {
    stack[++top] = c;
}

// Pop from stack
char pop() {
    if (top == -1) return '\0'; // empty stack
    return stack[top--];
}

// Peek top of stack
char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int main() {
    char str[100];
    int i;

    printf("Enter a binary string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        char ch = str[i];

        if (ch != '0' && ch != '1') {
            printf("? Invalid input! Only 0 and 1 allowed.\n");
            return 0;
        }

        if (ch == '0') {
            if (peek() == '1') pop(); // match 1
            else push('0');            // push 0
        } else { // ch == '1'
            if (peek() == '0') pop(); // match 0
            else push('1');            // push 1
        }
    }

    if (top == -1)
        printf("? String Accepted (Empty Stack)\n");
    else
        printf("? String Rejected (Stack not empty)\n");

    return 0;
}

