#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;   // ? NULL works with all compilers
    }
};

Node* head = NULL;

// (a) Insert at beginning
void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at beginning.\n";
}

// (b) Insert at end
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
    cout << "Inserted " << val << " at end.\n";
}

// (c) Insert before or after a node with specific value
void insertBeforeAfter(int val, int target, bool after) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // Insert before head
    if (!after && head->data == target) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " before " << target << ".\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Target node " << target << " not found.\n";
        delete newNode;
        return;
    }

    if (after) {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " after " << target << ".\n";
    } else {
        newNode->next = temp;
        prev->next = newNode;
        cout << "Inserted " << val << " before " << target << ".\n";
    }
}

// (d) Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from beginning.\n";
    delete temp;
}

// (e) Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    cout << "Deleted " << temp->data << " from end.\n";
    prev->next = NULL;
    delete temp;
}

// (f) Delete specific node
void deleteSpecific(int target) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == target) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted node " << target << ".\n";
        delete temp;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node " << target << " not found.\n";
        return;
    }
    prev->next = temp->next;
    cout << "Deleted node " << target << ".\n";
    delete temp;
}

// (g) Search node and display position
void searchNode(int target) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            cout << "Node " << target << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << target << " not found.\n";
}

// (h) Display all nodes
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val, target;
    bool after;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3: {
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter target value: ";
            cin >> target;
            cout << "1. After target\n2. Before target\n";
            int op;
            cin >> op;
            after = (op == 1);
            insertBeforeAfter(val, target, after);
            break;
        }
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> target;
            deleteSpecific(target);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> target;
            searchNode(target);
            break;
        case 8:
            displayList();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}



