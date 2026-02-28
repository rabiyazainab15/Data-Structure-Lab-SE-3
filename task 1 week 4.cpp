#include <iostream>
using namespace std;

// Structure of mobile
struct Mobile {
    string brand;
    int stock;
    int price;
    Mobile* next;
};

Mobile* head = NULL;

// Add Mobile function
void addMobile() {
    Mobile* newMobile = new Mobile();

    cout << "Enter Brand Name: ";
    cin >> newMobile->brand;

    cout << "Enter Stock: ";
    cin >> newMobile->stock;

    cout << "Enter Price: ";
    cin >> newMobile->price;

    newMobile->next = NULL;

    if(head == NULL) {
        head = newMobile;
    } else {
        Mobile* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMobile;
    }

    cout << "Mobile Added! " <<endl;
}

// Delete Mobile 
void deleteMobile() {
    string name;
    cout << "Enter Brand to Delete: ";
    cin >> name;

    if(head == NULL) {
        cout << "List Empty! " <<endl;
        return;
    }

    if(head->brand == name) {
        Mobile* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted! " <<endl;
        return;
    }

    Mobile* temp = head;
    while(temp->next != NULL && temp->next->brand != name) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        cout << "Not Found! "  <<endl;
    } else {
        Mobile* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Deleted! " <<endl;
    }
}

// Display Mobiles
void display() {
    if(head == NULL) {
        cout << "No Mobiles Available! " <<endl;
        return;
    }

    Mobile* temp = head;
    while(temp != NULL) {
        cout << temp->brand << " | "
             << temp->stock << " | "
             << temp->price << endl;
        temp = temp->next;
    }
}

// Main
int main() {
    int choice;

    do {
        cout << " 1. Add Mobile " <<endl;
        cout << "2. Delete Mobile "<<endl;
        cout << "3. Display Mobiles"<<endl;
        cout << "4. Exit "<<endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1) {
            addMobile();
        }
        else if(choice == 2) {
            deleteMobile();
        }
        else if(choice == 3) {
            display();
        }

    } while(choice != 4);

    return 0;
}