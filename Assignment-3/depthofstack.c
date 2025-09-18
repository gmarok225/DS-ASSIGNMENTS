#include<stdio.h>
#include<stdlib.h>
#define MAX 5   // maximum size of stack

int stack[MAX];
int top = -1;  // stack is empty initially

// Function prototypes
void push();
void pop();
void display();
int isEmpty();
int isFull();
void peek();

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Display Stack\n");
        printf("6. Peek (Top element)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: 
                if (isEmpty())
                    printf("Stack is Empty.\n");
                else
                    printf("Stack is NOT Empty.\n");
                break;
            case 4: 
                if (isFull())
                    printf("Stack is Full.\n");
                else
                    printf("Stack is NOT Full.\n");
                break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to insert element into stack
void push() {
    int val;
    if (isFull()) {
        printf("Stack Overflow! Cannot push.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("%d pushed into stack.\n", val);
    }
}

// Function to remove element from stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

// Function to check if stack is empty
int isEmpty() {
    return (top == -1);
}

// Function to check if stack is full
int isFull() {
    return (top == MAX - 1);
}

// Function to display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is Empty.\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to show top element
void peek() {
    if (isEmpty()) {
        printf("Stack is Empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

