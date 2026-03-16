#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node* next;
};

Node* head = NULL;

void addEmployee(string name)
{
    Node* n = new Node();
    n->name = name;

    if (head == NULL)
    {
        head = n;
        n->next = head;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    cout << "Added successfully\n";
}

void deleteEmployee(string name)
{
    if (head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    Node *temp = head, *prev;

    if (head->name == name)
    {
        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        head = head->next;

        cout << "Deleted successfully\n";
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head)
    {
        if (temp->name == name)
        {
            prev->next = temp->next;
            delete temp;
            cout << "Deleted successfully\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Employee not found\n";
}

void searchEmployee(string name)
{
    Node* temp = head;

    if (head == NULL)
        return;

    do
    {
        if (temp->name == name)
        {
            cout << "Found successfully\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Employee not found\n";
}

void updateEmployee(string oldName, string newName)
{
    Node* temp = head;

    do
    {
        if (temp->name == oldName)
        {
            temp->name = newName;
            cout << "Updated successfully\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Employee not found\n";
}

int main()
{
    addEmployee("Ali");
    addEmployee("Sara");
    addEmployee("Ahmed");

    searchEmployee("Sara");

    updateEmployee("Sara","Sana");

    deleteEmployee("Ali");
}