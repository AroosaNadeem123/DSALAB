//Circular singly linklist Deletion  at start middle end 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() : last(nullptr) {}

    // Function to insert at the end (for initial setup)
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (last == nullptr) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
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
            last->next = first->next;  // Update last's next to the second node
            delete first;
        }
    }

    // Function to delete from the end
    void deleteAtEnd() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = last->next;
        if (temp == last) {  // Only one node in the list
            delete last;
            last = nullptr;
        } else {
            while (temp->next != last) {  // Traverse to the second-last node
                temp = temp->next;
            }
            temp->next = last->next;  // Update second-last node's next to first node
            delete last;
            last = temp;  // Update last to the new last node
        }
    }

    // Function to delete from the middle (after a given position)
    void deleteAtMiddle(int position) {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = last->next;
        if (position == 1) {  // Position 1 is equivalent to deleteAtStart
            deleteAtStart();
            return;
        }

        // Traverse to the node just before the one to delete
        for (int i = 1; i < position - 1 && temp->next != last->next; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        if (toDelete == last->next) {  // Invalid position (greater than the list length)
            cout << "Position is out of bounds.\n";
            return;
        }

        temp->next = toDelete->next;  // Bypass the node to delete
        if (toDelete == last) {  // If we delete the last node, update `last`
            last = temp;
        }
        delete toDelete;
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
        } while (temp != last->next);  // Loop until we come back to the first node
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    // Inserting nodes to demonstrate deletions
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.insertAtEnd(50);

    cout << "Original List: ";
    cll.display();

    cll.deleteAtStart();
    cout << "After deleting at start: ";
    cll.display();

    cll.deleteAtEnd();
    cout << "After deleting at end: ";
    cll.display();

    cll.deleteAtMiddle(2);
    cout << "After deleting at position 2: ";
    cll.display();

    return 0;
}
