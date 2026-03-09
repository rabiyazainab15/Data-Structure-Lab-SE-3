#include <iostream>
using namespace std;

struct Node
{
    int rain;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// insert node at end
void insert(int value)
{
    Node* newNode = new Node();
    newNode->rain = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
}

int main()
{
    int rain;

    // input rainfall for 7 days
    for (int i = 1; i <= 7; i++)
    {
        cout << "Enter rainfall for day " << i << ": ";
        cin >> rain;

        if (rain < 0)
        {
            cout << "Negative value not allowed\n";
            i--;
            continue;
        }

        insert(rain);
    }

    int total = 0;
    int max = -1;
    int min = 999;
    int maxDay = 0;
    int minDay = 0;

    int day = 1;

    Node* temp = head;

    while (temp != NULL)
    {
        total = total + temp->rain;

        if (temp->rain > max)
        {
            max = temp->rain;
            maxDay = day;
        }

        if (temp->rain < min)
        {
            min = temp->rain;
            minDay = day;
        }

        temp = temp->next;
        day++;
    }

    cout << "\nTotal Rainfall = " << total << endl;
    cout << "Average Rainfall = " << total / 7.0 << endl;

    cout << "Highest Rainfall Day = Day " << maxDay << endl;
    cout << "Lowest Rainfall Day = Day " << minDay << endl;

    // rainfall after 5th node
    temp = head;

    for (int i = 1; i < 6; i++)
        temp = temp->next;

    if (temp != NULL)
        cout << "Rainfall after 5th node = " << temp->rain << endl;

}