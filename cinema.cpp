#include <iostream>
#include <string>
using namespace std;

// Node class to represent each seat in the theater
class Node {
public:
    Node* next;
    Node* prev;
    int seat;
    string id;
    int status;  // 0: Available, 1: Booked
};

// Cinemax class to manage the theater booking system
class Cinemax {
public:
    Node* head, *tail, *temp;

    Cinemax() {
        head = NULL;
    }

    // Initialize the circular linked list representing the theater seats
    void createList();

    // Display the current status of all seats in the theater
    void display();

    // Book a seat with the specified seat number and user ID
    void book();

    // Cancel the booking for a seat with the specified seat number and user ID
    void cancel();

    // Display the available seats in the theater
    void available();
};

void Cinemax::createList() {
    int i = 1;
    temp = new Node;
    temp->seat = 1;
    temp->status = 0;
    temp->id = "null";
    tail = head = temp;

    for (int i = 2; i <= 70; i++) {
        Node* p = new Node;
        p->seat = i;
        p->status = 0;
        p->id = "null";
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = head;
        head->prev = tail;
    }
}

void Cinemax::display() {
    int r = 1;
    temp = head;
    int count = 0;

    cout << "\n---------------------------------------------\n";
    cout << "              Cinemax Theater               \n";
    cout << "---------------------------------------------\n";

    while (temp->next != head) {
        cout << "S" << (temp->seat < 10 ? "0" : "") << temp->seat << " : ";

        if (temp->status == 0)
            cout << "|___| ";
        else
            cout << "|_B_| ";

        count++;
        if (count % 7 == 0) {
            cout << endl;
            r++;
        }
        temp = temp->next;
    }

    cout << "S" << temp->seat << " :";

    if (temp->status == 0)
        cout << "|___| ";
    else
        cout << "|_B_| ";
}

void Cinemax::book() {
    int x;
    string y;

label:
    cout << "\n\nEnter seat number to be booked\n";
    cin >> x;
    cout << "Enter your ID number\n";
    cin >> y;

    if (x < 1 || x > 70) {
        cout << "Enter correct seat number to book (1-70)\n";
        goto label;
    }

    temp = head;
    while (temp->seat != x) {
        temp = temp->next;
    }

    if (temp->status == 1)
        cout << "Seat already booked!\n";
    else {
        temp->status = 1;
        temp->id = y;
        cout << "Seat " << x << " booked!\n";
    }
}

void Cinemax::cancel() {
    int x;
    string y;

label1:
    cout << "Enter seat number to cancel booking\n";
    cin >> x;
    cout << "Enter your ID\n";
    cin >> y;

    if (x < 1 || x > 70) {
        cout << "Enter correct seat number to cancel (1-70)\n";
        goto label1;
    }

    temp = head;
    while (temp->seat != x) {
        temp = temp->next;
    }

    if (temp->status == 0) {
        cout << "Seat not booked yet!!\n";
    }
    else {
        if (temp->id == y) {
            temp->status = 0;
            cout << "Seat Cancelled!\n";
        }
        else
            cout << "Wrong User ID!!! Seat cannot be cancelled!!!\n";
    }
}

void Cinemax::available() {
    temp = head;
    int count = 0;

    cout << "\n---------------------------------------------\n";
    cout << "          Available Seats in Cinemax          \n";
    cout << "---------------------------------------------\n";

    while (temp->next != head) {
        cout << "S" << (temp->seat < 10 ? "0" : "") << temp->seat << " : ";

        if (temp->status == 0)
            cout << "|___| ";
        else if (temp->status == 1)
            cout << " ";

        count++;
        if (count % 7 == 0) {
            cout << endl;
        }
        temp = temp->next;
    }

    if (temp->status == 0) {
        cout << "S" << temp->seat << " :";

        if (temp->status == 0)
            cout << "|___| ";
    }
}

int main() {
    Cinemax obj;
    obj.createList();
    int ch;
    char c = 'y';

    while (c == 'y') {
        obj.display();
        cout << "\n---------------------------------------------\n";
        cout << "          CINEMAX MOVIE THEATRE               \n";
        cout << "---------------------------------------------\n";
        cout << "Enter Choice\n1. Current Seat Status\n2. Book Seat \n3. Available Seat\n4. Cancel Seat\n";
        cin >> ch;

        switch (ch) {
        case 1:
            obj.display();
            break;
        case 2:
            obj.book();
            break;
        case 3:
            obj.available();
            break;
        case 4:
            obj.cancel();
            break;
        default:
            cout << "Wrong choice input\n";
        }

        cout << "\nDo you want to perform any other operation? (y/n)\n";
        cin >> c;
    }

    return 0;
}
