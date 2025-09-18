#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];  // first return then do --
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);   // (unsafe but simple for now)

    int len = strlen(str);

    // Push all characters of string into stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Pop all characters and print ? reversed string
    printf("Reversed string: ");
    for (int i = 0; i < len; i++) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}

