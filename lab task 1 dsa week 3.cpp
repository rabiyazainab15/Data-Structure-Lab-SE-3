#include <iostream>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    // Dynamic allocation
    Product* products = new Product[n];

    // Input of product
    for (int i = 0; i < n; i++) {
        cout << " Enter details of product " << i + 1 << endl;
        cout << " Name: "<<endl;
        cin >> products[i].name;
        cout << " Code: "<<endl;
        cin >> products[i].code;
        cout << " Price: "<<endl;
        cin >> products[i].price;
    }

    // Output of product
    cout << " Product List: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Product: " << i + 1 <<endl;
        cout << products[i].name << ", ";
        cout << products[i].code << ", ";
        cout << products[i].price << endl;
    }

    // Free memory
    delete[] products;
   

    return 0;
}
