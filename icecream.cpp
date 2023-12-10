#include <iostream>
#include <unordered_set>

using namespace std;

// Node structure for a linked list
struct Node {
    int rollNumber; // Assuming roll number is used as a unique identifier for students
    bool likesVanilla;
    bool likesButterscotch;
    Node* next;
};

// Function to insert a student into a linked list
void insert(Node*& head, int rollNumber, bool likesVanilla, bool likesButterscotch) {
    Node* newNode = new Node();
    newNode->rollNumber = rollNumber;
    newNode->likesVanilla = likesVanilla;
    newNode->likesButterscotch = likesButterscotch;
    newNode->next = head;
    head = newNode;
}

// Function to display the elements of a linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Roll Number: " << temp->rollNumber << ", Likes Vanilla: " << temp->likesVanilla
             << ", Likes Butterscotch: " << temp->likesButterscotch << endl;
        temp = temp->next;
    }
}

// Function to compute and display sets A, B, C, D, and E
void computeAndDisplaySets(Node* head) {
    unordered_set<int> setLikesVanilla;
    unordered_set<int> setLikesButterscotch;
    unordered_set<int> setLikesBoth;
    unordered_set<int> setLikesOnlyVanilla;
    unordered_set<int> setLikesOnlyButterscotch;
    unordered_set<int> setLikesNeither;

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->likesVanilla) {
            setLikesVanilla.insert(temp->rollNumber);
        }

        if (temp->likesButterscotch) {
            setLikesButterscotch.insert(temp->rollNumber);
        }

        if (temp->likesVanilla && temp->likesButterscotch) {
            setLikesBoth.insert(temp->rollNumber);
        }

        if (temp->likesVanilla && !temp->likesButterscotch) {
            setLikesOnlyVanilla.insert(temp->rollNumber);
        }

        if (!temp->likesVanilla && temp->likesButterscotch) {
            setLikesOnlyButterscotch.insert(temp->rollNumber);
        }

        setLikesNeither.insert(temp->rollNumber);

        temp = temp->next;
    }

    // Set A: Students who like either vanilla or butterscotch or both
    cout << "Set A: ";
    for (int rollNumber : setLikesVanilla) {
        cout << rollNumber << " ";
    }
    for (int rollNumber : setLikesButterscotch) {
        if (setLikesVanilla.find(rollNumber) == setLikesVanilla.end()) {
            cout << rollNumber << " ";
        }
    }
    cout << endl;

    // Set B: Students who like both vanilla and butterscotch
    cout << "Set B: ";
    for (int rollNumber : setLikesBoth) {
        cout << rollNumber << " ";
    }
    cout << endl;

    // Set C: Students who like only vanilla not butterscotch
    cout << "Set C: ";
    for (int rollNumber : setLikesOnlyVanilla) {
        cout << rollNumber << " ";
    }
    cout << endl;

    // Set D: Students who like only butterscotch not vanilla
    cout << "Set D: ";
    for (int rollNumber : setLikesOnlyButterscotch) {
        cout << rollNumber << " ";
    }
    cout << endl;

    // Set E: Number of students who like neither vanilla nor butterscotch
    cout << "Set E: " << setLikesNeither.size() << " students" << endl;
}

int main() {
    // Example student data
    Node* students = nullptr;

    // Insert student data (roll number, likesVanilla, likesButterscotch)
    insert(students, 1, true, false);
    insert(students, 2, false, true);
    insert(students, 3, true, true);
    insert(students, 4, false, false);

    // Display student data
    cout << "Student Data:\n";
    display(students);

    // Compute and display sets A, B, C, D, and E
    cout << "\nComputing and Displaying Sets A, B, C, D, and E:\n";
    computeAndDisplaySets(students);

    return 0;
}
