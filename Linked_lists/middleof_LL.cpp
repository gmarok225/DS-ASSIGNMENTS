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

// Function to display the list
void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find the middle element
int findMiddle() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    // Move fast pointer 2 steps and slow pointer 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() {
    // Example Input: 1->2->3->4->5
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);

    cout << "Linked List: ";
    displayList();

    int middle = findMiddle();
    cout << "Middle Element: " << middle << endl;

    return 0;
}

