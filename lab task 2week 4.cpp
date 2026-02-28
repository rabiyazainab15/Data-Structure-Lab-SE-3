#include <iostream>
using namespace std;

// Structure
struct Profile {
    string name;
    int age;
    string email;
    Profile* next;
};

Profile* head = NULL;

// Create Profile function
void createProfile() {
    Profile* newProfile = new Profile();

    cout << "Enter Name: ";
    cin >> newProfile->name;

    cout << "Enter Age: ";
    cin >> newProfile->age;

    cout << "Enter Email: ";
    cin >> newProfile->email;

    newProfile->next = NULL;

    if(head == NULL) {
        head = newProfile;
    } else {
        Profile* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProfile;
    }

    cout << "Profile Created! " <<endl;
}

// Search Profile
void searchProfile() {
    string n;
    cout << "Enter Name to Search: " <<endl;
    cin >> n;

    Profile* temp = head;

    while(temp != NULL) {
        if(temp->name == n) {
            cout << "Profile Found: " <<endl;
            cout << temp->name << " | "
                 << temp->age << " | "
                 << temp->email << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Profile Not Found! " <<endl;
}

// Update Profile
void updateProfile() {
    string n;
    cout << "Enter Name to Update: " <<endl;
    cin >> n;

    Profile* temp = head;

    while(temp != NULL) {
        if(temp->name == n) {
            cout << "Enter New Age: " <<endl;
            cin >> temp->age;

            cout << "Enter New Email: " <<endl;
            cin >> temp->email;

            cout << "Profile Updated! " <<endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Profile Not Found! " <<endl;
}

// Delete Profile
void deleteProfile() {
    string n;
    cout << "Enter Name to Delete: ";
    cin >> n;

    if(head == NULL) {
        cout << "No Profiles Available! " <<endl;
        return;
    }

    if(head->name == n) {
        Profile* temp = head;
        head = head->next;
        delete temp;
        cout << "Profile Deleted! " <<endl;
        return;
    }

    Profile* temp = head;

    while(temp->next != NULL && temp->next->name != n) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        cout << "Profile Not Found! " <<endl;
    } else {
        Profile* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Profile Deleted! " <<endl;
    }
}

// Display All Profiles
void displayProfiles() {
    if(head == NULL) {
        cout << "No Profiles Available!" <<endl;
        return;
    }

    Profile* temp = head;

    while(temp != NULL) {
        cout << temp->name << " | "
             << temp->age << " | "
             << temp->email << endl;
        temp = temp->next;
    }
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n1. Create Profile "<<endl;
        cout << "2. Update Profile " <<endl;
        cout << "3. Delete Profile " <<endl;
        cout << "4. Search Profile " <<endl;
        cout << "5. View All Profiles " << endl;
        cout << "6. Exit " <<endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1)
            createProfile();
        else if(choice == 2)
            updateProfile();
        else if(choice == 3)
            deleteProfile();
        else if(choice == 4)
            searchProfile();
        else if(choice == 5)
            displayProfiles();

    } while(choice != 6);

    return 0;
}