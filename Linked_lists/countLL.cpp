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

// Function to insert node at end
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

// Function to display linked list
void displayList() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

// Function to count and delete all occurrences of key
int deleteOccurrences(int key) {
    int count = 0;

    // Delete occurrences from beginning if key is at head
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Traverse and delete occurrences in remaining list
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
            count++;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return count;
}

int main() {
    // Example: 1->2->1->2->1->3->1
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(3);
    insertAtEnd(1);

    cout << "Original Linked List: ";
    displayList();

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    int count = deleteOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    displayList();

    return 0;
}

