#include <iostream>
using namespace std;

class Node
{
public:
    string title;
    float price;
    int edition;
    int pages;
    Node* next;
};

Node* top = NULL;

void push(string t, float p, int e, int pg)
{
    Node* n = new Node();

    n->title = t;
    n->price = p;
    n->edition = e;
    n->pages = pg;

    n->next = top;
    top = n;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Empty\n";
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack Empty\n";
        return;
    }

    cout << "\nTop Book:\n";
    cout << top->title << " "
         << top->price << " "
         << top->edition << " "
         << top->pages << endl;
}

void display()
{
    Node* temp = top;

    cout << "\nRemaining Books:\n";

    while (temp != NULL)
    {
        cout << temp->title << " "
             << temp->price << " "
             << temp->edition << " "
             << temp->pages << endl;

        temp = temp->next;
    }
}

int main()
{
    // Push 5 books
    push("C++", 500, 2, 300);
    push("DSA", 600, 3, 400);
    push("OOP", 450, 1, 250);
    push("Algo", 700, 2, 500);
    push("Prog", 550, 4, 350);

    // Find top
    peek();

    // Pop 2 books
    pop();
    pop();

    // Display remaining
    display();

    return 0;
}