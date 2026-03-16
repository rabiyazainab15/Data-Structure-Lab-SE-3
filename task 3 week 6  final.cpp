#include <iostream>
using namespace std;

class Node
{
public:
    string id,name,author,isbn;
    double price;
    Node* next;
};

Node* head=NULL;

void addBook(string id,string name,double price,string author,string isbn)
{
    Node* n=new Node();

    n->id=id;
    n->name=name;
    n->price=price;
    n->author=author;
    n->isbn=isbn;

    if(head==NULL)
    {
        head=n;
        n->next=head;
    }
    else
    {
        Node* temp=head;
        while(temp->next!=head)
            temp=temp->next;

        temp->next=n;
        n->next=head;
    }

    cout<<"Book Added " <<endl;
}

void removeBook(string id)
{
    Node *temp=head,*prev;

    if(head==NULL)
        return;

    if(head->id==id)
    {
        while(temp->next!=head)
            temp=temp->next;

        temp->next=head->next;
        head=head->next;

        cout<<"Book Deleted " <<endl;
        return;
    }

    prev=head;
    temp=head->next;

    while(temp!=head)
    {
        if(temp->id==id)
        {
            prev->next=temp->next;
            delete temp;
            cout<<"Book Deleted " <<endl;
            return;
        }

        prev=temp;
        temp=temp->next;
    }

    cout<<"Book not found\n";
}

void printBooks()
{
    Node* temp=head;

    if(head==NULL)
        return;

    do
    {
        cout<<temp->id<<" "
            <<temp->name<<" "
            <<temp->price<<" "
            <<temp->author<<" "
            <<temp->isbn<<endl;

        temp=temp->next;

    }while(temp!=head);
}

int main()
{
    addBook(" 1 "," C++ ", 500 ," Ali " , " 111 ");
    addBook(" 2 ", " DSA ", 600, " Ahmed " , " 222 ");
    addBook(" 3 "," OOP ",450,"Sara","333");
    addBook(" 4 "," Algo " , 700 , " Khan " , " 444 ");
    addBook(" 5 "," DB ",550,"Zara" , " 555 ");
    addBook(" 6 "," AI ", 650 , " Usman " , " 666 ");
    addBook(" 7 "," ML ", 750 , " Adeel " , " 777 ");
    addBook(" 8 "," Python ", 400 , " Hina " , " 888 ");
    addBook(" 9 " , " Java " , 480 , " Bilal " , " 999 ");
    addBook(" 10 " , " Web " , 520 , " Ahsan " , " 101 ");

    printBooks();

    removeBook(" 3 ");
    removeBook(" 50 ");

    printBooks();
}