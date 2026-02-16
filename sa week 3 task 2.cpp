#include <iostream>
using namespace std;

int main() {
    // Dynamic allocation
    char* ch = new char;

    // Store value
    cout << "Enter a character: ";
    cin >> *ch;

    // Display
    cout << "Stored character: " << *ch << endl;

    // Free memory
    delete ch;
    ch = nullptr;

    return 0;
}
