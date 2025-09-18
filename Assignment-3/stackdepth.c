#include<stdio.h>
#define MAXLEN 100    // Maximum size of stack

// Stack structure
typedef struct {
    int element[MAXLEN];
    int top;
} stack;

// Initialize stack 
stack init(){
    stack S;
    S.top = -1;
    return S;
}

// Check if stack is empty
int isEmpty(stack S) {
    return (S.top == -1);
}

// Check if stack is full
int isFull(stack S) {
    return (S.top == MAXLEN - 1);
}

// Get top element of stack
int top(stack S) {
    if (isEmpty(S))
        printf("Empty stack\n");
    else
        return S.element[S.top];
}

// Push element into stack
stack push(stack S, int x) {
    if (isFull(S))
        printf("OVERFLOW\n");
    else {
        ++S.top;
        S.element[S.top] = x;
    }
    return S;
}

// Pop element from stack
stack pop(stack S) {
    if (isEmpty(S))
        printf("UNDERFLOW\n");
    else
        --S.top;
    return S;
}

// Print stack
void print(stack S) {
    int i;
    for (i = S.top; i >= 0; --i)
        printf("%d ", S.element[i]);
    printf("\n");
}

// Main function
int main() {
    stack S;
    S = init();

    // Push elements
    S = push(S, 10);
    S = push(S, 45);
    S = push(S, 1);
    S = push(S, 50);

    // Print stack
    printf("Current stack: ");
    print(S);
    printf(" with top = %d.\n", top(S));

    // Pop elements
    S = pop(S);
    S = pop(S);

    // Print again
    printf("Current stack: ");
    print(S);
    printf(" with top = %d.\n", top(S));

    return 0;
}

