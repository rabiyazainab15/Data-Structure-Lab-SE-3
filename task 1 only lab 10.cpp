#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int q[5] = {0, 0, 0, 0, 0};  // array
    int front = -1;
    int rear = -1;

    // -----  enQueue(10) -----
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    q[rear] = 10;
    cout << "After enQueue(10):" << endl;
    cout << "front = " << front << ", rear = " << rear << endl;
    cout << "Array: [ ";
    for (int i = 0; i < size; i++) cout << q[i] << " ";
    cout << "]" << endl;
    cout << "------------------------" << endl;

    // -----  enQueue(20) -----
    if ((rear + 1) % size == front) {
        cout << "Queue full! Cannot enQueue 20" << endl;
    } else {
        rear = (rear + 1) % size;
        q[rear] = 20;
    }
    cout << "After enQueue(20):" << endl;
    cout << "front = " << front << ", rear = " << rear << endl;
    cout << "Array: [ ";
    for (int i = 0; i < size; i++) cout << q[i] << " ";
    cout << "]" << endl;
    cout << "------------------------" << endl;

    // -----  enQueue(30) -----
    if ((rear + 1) % size == front) {
        cout << "Queue full! Cannot enQueue 30" << endl;
    } else {
        rear = (rear + 1) % size;
        q[rear] = 30;
    }
    cout << "After enQueue(30):" << endl;
    cout << "front = " << front << ", rear = " << rear << endl;
    cout << "Array: [ ";
    for (int i = 0; i < size; i++) cout << q[i] << " ";
    cout << "]" << endl;
    cout << "------------------------" << endl;

    // -----  deQueue() -----
    if (front == -1) {
        cout << "Queue empty! Cannot deQueue" << endl;
    } else if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }
    cout << "After deQueue():" << endl;
    cout << "front = " << front << ", rear = " << rear << endl;
    cout << "Array: [ ";
    for (int i = 0; i < size; i++) cout << q[i] << " ";
    cout << "]" << endl;
    cout << "------------------------" << endl;

    // -----  enQueue(40) -----
    if ((rear + 1) % size == front) {
        cout << "Queue full! Cannot enQueue 40" << endl;
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        q[rear] = 40;
    }
    cout << "After enQueue(40):" << endl;
    cout << "front = " << front << ", rear = " << rear << endl;
    cout << "Array: [ ";
    for (int i = 0; i < size; i++) cout << q[i] << " ";
    cout << "]" << endl;
    cout << "------------------------" << endl;

    // -----  enQueue(50) -----
    if ((rear + 1) % size == front) {
        cout << "Queue full! Cannot enQueue 50" << endl;
    } else {
        rear = (rear + 1) % size;
        q[rear] = 50;
    }
    cout << "After enQueue(50):" << endl;
    cout << "front = " << front << ", rear = " << rear << endl;
    cout << "Array: [ ";
    for (int i = 0; i < size; i++) cout << q[i] << " ";
    cout << "]" << endl;
    cout << "------------------------" << endl;

    // ----- enQueue(60) -----
    if ((rear + 1) % size == front) {
        cout << "Queue full! Cannot enQueue 60" << endl;
    } else {
        rear = (rear + 1) % size;
        q[rear] = 60;
    }
    cout << "After enQueue(60):" << endl;
    cout << "front = " << front << ", rear = " << rear << endl;
    cout << "Array: [ ";
    for (int i = 0; i < size; i++) cout << q[i] << " ";
    cout << "]" << endl;
    cout << "------------------------" << endl;

    return 0;
}