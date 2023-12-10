#include <iostream>
#include <list>

using namespace std;

// Class representing an item in the priority queue
template <typename T>
class PriorityQueueItem {
public:
    T data;
    int priority;

    PriorityQueueItem(const T& item, int priority) : data(item), priority(priority) {}
};

// Operator overloading to compare PriorityQueueItems based on priority
template <typename T>
bool operator<=(const PriorityQueueItem<T>& lhs, const PriorityQueueItem<T>& rhs) {
    return lhs.priority <= rhs.priority;
}

// Class representing a Priority Queue using an ordered list
template <typename T>
class PriorityQueue {
private:
    list<PriorityQueueItem<T>> itemList;

public:
    // Function to add an item to the priority queue
    void enqueue(const T& item, int priority) {
        PriorityQueueItem<T> newItem(item, priority);

        // Find the correct position based on priority
        auto it = itemList.begin();
        while (it != itemList.end() && !(newItem <= *it)) {
            ++it;
        }

        // Insert the item at the correct position
        itemList.insert(it, newItem);

        cout << "Item \"" << item << "\" with priority " << priority << " added to the queue.\n";
    }

    // Function to remove the highest-priority item from the queue
    void dequeue() {
        if (itemList.empty()) {
            cout << "Queue is empty. No item to dequeue.\n";
        } else {
            cout << "Dequeued item \"" << itemList.front().data << "\" with priority "
                 << itemList.front().priority << ".\n";
            itemList.pop_front();
        }
    }

    // Function to display the items in the priority queue
    void displayQueue() {
        if (itemList.empty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Priority Queue Contents:\n";
            for (const auto& item : itemList) {
                cout << "Item: " << item.data << ", Priority: " << item.priority << endl;
            }
        }
    }
};

int main() {
    // Example usage of the PriorityQueue class with integer data type
    PriorityQueue<int> intPriorityQueue;

    intPriorityQueue.enqueue(10, 2);
    intPriorityQueue.enqueue(20, 1);
    intPriorityQueue.enqueue(30, 3);

    intPriorityQueue.displayQueue();

    intPriorityQueue.dequeue();

    intPriorityQueue.displayQueue();

    return 0;
}
