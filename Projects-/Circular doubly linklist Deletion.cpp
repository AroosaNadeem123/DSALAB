//Circular doubly linklist Deletion  at start middle end 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularDoublyLinkedList {
private:
    Node* last;

public:
    CircularDoublyLinkedList() : last(nullptr) {}

    // Function to insert at the end (for initial setup)
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (last == nullptr) {  // If list is empty
            newNode->next = newNode;
            newNode->prev = newNode;
            last = newNode;
        } else {
            Node* first = last->next;
            newNode->next = first;
            newNode->prev = last;
            last->next = newNode;
            first->prev = newNode;
            last = newNode;  // Update last to new node
        }
    }

    // Function to delete from the beginning
    void deleteAtStart() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* first = last->next;
        if (first == last) {  // Only one node in the list
            delete first;
            last = nullptr;
        } else {
            Node* second = first->next;
            last->next = second;
            second->prev = last;
            delete first;
        }
    }

    // Function to delete from the end
    void deleteAtEnd() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* first = last->next;
        if (first == last) {  // Only one node in the list
            delete last;
            last = nullptr;
        } else {
            Node* secondLast = last->prev;
            secondLast->next = first;
            first->prev = secondLast;
            delete last;
            last = secondLast;  // Update last to the new last node
        }
    }

    // Function to delete from the middle (after a given position)
    void deleteAtMiddle(int position) {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (position <= 0) {  // Position is 0 or less, treat as deleteAtStart
            deleteAtStart();
            return;
        }

        Node* temp = last->next;  // Start from the first node

        // Traverse to the node at the given position or stop if we reach the end
        for (int i = 1; i < position && temp != last; i++) {
            temp = temp->next;
        }

        if (temp == last) {  // If deleting at the end, call deleteAtEnd
            deleteAtEnd();
        } else {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            toDelete->next->prev = temp;

            if (toDelete == last) {  // If we are deleting the last node, update last
                last = temp;
            }

            delete toDelete;
        }
    }

    // Function to display the list
    void display() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = last->next;  // Start from the first node
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);  // Loop until we return to the first node
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedList cdl;

    // Inserting nodes to demonstrate deletions
    cdl.insertAtEnd(10);
    cdl.insertAtEnd(20);
    cdl.insertAtEnd(30);
    cdl.insertAtEnd(40);
    cdl.insertAtEnd(50);

    cout << "Original List: ";
    cdl.display();

    cdl.deleteAtStart();
    cout << "After deleting at start: ";
    cdl.display();

    cdl.deleteAtEnd();
    cout << "After deleting at end: ";
    cdl.display();

    cdl.deleteAtMiddle(2);  // Delete node after the 2nd position
    cout << "After deleting at position 2: ";
    cdl.display();

    return 0;
}
