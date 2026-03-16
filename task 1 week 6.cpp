#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBefore(int value)
{
    Node* n = new Node();
    n->data = value;

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
    head = n;
}

// Insert at end
void insertAfter(int value)
{
    Node* n = new Node();
    n->data = value;

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}

// Delete node
void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List Empty " <<endl;
        return;
    }

    Node *temp = head, *prev;

    // delete head
    if (head->data == value)
    {
        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        head = head->next;

        cout << "Node Deleted " <<endl;
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head)
    {
        if (temp->data == value)
        {
            prev->next = temp->next;
            delete temp;
            cout << "Node Deleted " <<endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Value not found " <<endl;
}

// Display list
void display()
{
    if (head == NULL)
        return;

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main()
{
    insertBefore(10);
    insertBefore(5);
    insertAfter(20);
    insertAfter(30);

    display();

    deleteNode(20);

    display();
}