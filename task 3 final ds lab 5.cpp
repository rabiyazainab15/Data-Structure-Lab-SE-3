#include <iostream>
using namespace std;

struct Player
{
    string name;
    int score;
    Player* next;
    Player* prev;
};

Player* head = NULL;

// Add player in sorted order
void addPlayer(string n, int s)
{
    Player* newNode = new Player();
    newNode->name = n;
    newNode->score = s;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // insert at beginning if score is smallest
    if (s < head->score)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Player* temp = head;

    while (temp->next != NULL && temp->next->score < s)
        temp = temp->next;

    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
}

// display whole list
void display()
{
    Player* temp = head;

    cout << "\nPlayers List\n";

    while (temp != NULL)
    {
        cout << temp->name << "  " << temp->score << endl;
        temp = temp->next;
    }
}

// delete player by name
void deletePlayer(string n)
{
    Player* temp = head;

    while (temp != NULL && temp->name != n)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Player not found\n";
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

// lowest score player
void lowestScore()
{
    if (head != NULL)
        cout << "Lowest score player: " << head->name << " " << head->score << endl;
}

// players with same score
void sameScore(int s)
{
    Player* temp = head;

    cout << "Players with score " << s << endl;

    while (temp != NULL)
    {
        if (temp->score == s)
            cout << temp->name << endl;

        temp = temp->next;
    }
}

// display backward from player
void displayBackward(string n)
{
    Player* temp = head;

    while (temp != NULL && temp->name != n)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Player not found\n";
        return;
    }

    cout << "Players behind " << n << ":\n";

    temp = temp->prev;

    while (temp != NULL)
    {
        cout << temp->name << " " << temp->score << endl;
        temp = temp->prev;
    }
}

int main()
{
    addPlayer("Ali",70);
    addPlayer("Sara",65);
    addPlayer("Ahmed",80);
    addPlayer("Usman",70);

    display();

    lowestScore();

    sameScore(70);

    displayBackward("Ahmed");

    deletePlayer("Ali");

    cout << "\nAfter deleting Ali:\n";
    display();
}