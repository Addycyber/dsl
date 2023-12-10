#include <iostream>
#include <queue>

using namespace std;

class JobQueue {
private:
    queue<string> jobs;

public:
    // Function to add a job to the queue
    void addJob(const string& job) {
        jobs.push(job);
        cout << "Job \"" << job << "\" added to the queue.\n";
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (jobs.empty()) {
            cout << "Queue is empty. No job to delete.\n";
        } else {
            cout << "Job \"" << jobs.front() << "\" deleted from the queue.\n";
            jobs.pop();
        }
    }

    // Function to display the current jobs in the queue
    void displayJobs() {
        if (jobs.empty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Current Jobs in the Queue:\n";
            int count = 1;
            queue<string> tempQueue = jobs;

            while (!tempQueue.empty()) {
                cout << count << ". " << tempQueue.front() << endl;
                tempQueue.pop();
                count++;
            }
        }
    }
};

int main() {
    JobQueue jobQueue;
    int choice;

    do {
        cout << "\nJob Queue Simulation\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string newJob;
                    cout << "Enter the job name: ";
                    cin.ignore(); // Clear input buffer
                    getline(cin, newJob);
                    jobQueue.addJob(newJob);
                }
                break;
            case 2:
                jobQueue.deleteJob();
                break;
            case 3:
                jobQueue.displayJobs();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
