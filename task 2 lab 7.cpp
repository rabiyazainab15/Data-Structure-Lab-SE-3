#include <iostream>
using namespace std;

class Inventory
{
public:
    int serialNum;
    int manufactYear;
    int lotNum;
};

class Node
{
public:
    Inventory part;
    Node* next;
};

Node* top = NULL;

void push(Inventory p)
{
    Node* n = new Node();

    n->part = p;
    n->next = top;
    top = n;

    cout << "Part Added to Inventory " <<endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Inventory Empty " <<endl;
        return;
    }

    Node* temp = top;

    cout << " Part Removed: " <<endl;
    cout << "Serial Number: " << temp->part.serialNum << endl;
    cout << "Manufacture Year: " << temp->part.manufactYear << endl;
    cout << "Lot Number: " << temp->part.lotNum << endl;

    top = top->next;
    delete temp;
}

void display()
{
    Node* temp = top;

    cout << " Remaining Inventory: " <<endl;

    while (temp != NULL)
    {
        cout << "Serial Number: " << temp->part.serialNum << endl;
        cout << "Manufacture Year: " << temp->part.manufactYear << endl;
        cout << "Lot Number: " << temp->part.lotNum << endl;
        cout << "-------------------";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << " 1. Add Part " <<endl;
        cout << " 2. Remove Part " <<endl;
        cout << " 3. Exit " <<endl;
        cout << " Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Inventory p;

            cout << "Enter Serial Number: ";
            cin >> p.serialNum;

            cout << "Enter Manufacture Year: ";
            cin >> p.manufactYear;

            cout << "Enter Lot Number: ";
            cin >> p.lotNum;

            push(p);
        }

        else if (choice == 2)
        {
            pop();
        }

    } while (choice != 3);

    display();

    return 0;
}