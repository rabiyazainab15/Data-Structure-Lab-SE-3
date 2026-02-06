#include <iostream>
using namespace std;

// function to swap number using pointer
void swapNumbers(int *a , int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
	
} 
int main(){
	int x = 5;
	int y = 6;
	
	cout<<"Before Swapping : " <<endl;
	cout<< " x = " << x << " y = " << y << endl;
	
	swapNumbers(&x , &y);  // pass address to print swap numbers
	cout<<" After swapping :" <<endl;
	cout<< " x = " << x << " y = " << y << endl;
return 0;	
} 
