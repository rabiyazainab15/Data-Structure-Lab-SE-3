#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int search = 20;
     int index = 1;
   

    
    for(int i = 0; i < 3; i++){
        if(arr[i] == search){
            cout << "Element found at index " << i << endl;
        }
    }

     int newValue = 50;
    arr[index] = newValue;

    
    
    for(int i = 0; i < 3; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
