#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void addBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert after 45
void addAfter45(int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != 45)
        temp = temp->next;

    if (temp == NULL) {
        cout << "45 not found\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete node after 45
void deleteAfter45() {
    Node* temp = head;

    while (temp != NULL && temp->data != 45)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Node not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;

    if (del->next != NULL)
        del->next->prev = temp;

    delete del;
}

// Display list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    int n, x;
    cout << "Enter number of marks: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        addBeginning(x);
    }

    cout << "List: ";
    display();

    addAfter45(99);
    cout << "After inserting after 45: ";
    display();

    deleteBeginning();
    cout << "After deleting beginning: ";
    display();

    deleteAfter45();
    cout << "After deleting after 45: ";
    display();

}