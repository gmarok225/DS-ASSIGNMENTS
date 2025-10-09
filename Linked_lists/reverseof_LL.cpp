#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

// Function to insert a new node at the end
void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL)
            cout << "->";
        node = node->next;
    }
    cout << "->NULL" << endl;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;  // Store next
        current->next = prev;      // Reverse current node's pointer
        prev = current;            // Move prev to current
        current = nextNode;        // Move current to next
    }

    return prev;  // New head
}

int main() {
    // Example input: 1->2->3->4->NULL
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);

    cout << "Original Linked List: ";
    displayList(head);

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    displayList(head);

    return 0;
}

