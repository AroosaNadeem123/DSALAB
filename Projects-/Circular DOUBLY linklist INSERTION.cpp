////Circular DOUBLY linklist INSERTION at start middle end 
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

    // Insert at the beginning
    void insertAtStart(int value) {
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
            first->prev = newNode;
            last->next = newNode;
        }
    }

    // Insert at the end
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

    // Insert in the middle (after a specific position)
    void insertAtMiddle(int value, int position) {
        if (last == nullptr || position <= 0) {  // If list is empty or position is invalid
            insertAtStart(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = last->next;  // Start from the first node

        // Traverse to the given position or stop if we reach the end
        for (int i = 1; i < position && temp != last; i++) {
            temp = temp->next;
        }

        Node* nextNode = temp->next;
        newNode->next = nextNode;
        newNode->prev = temp;
        temp->next = newNode;
        nextNode->prev = newNode;

        if (temp == last) {  // Update last if new node is added at the end
            last = newNode;
        }
    }

    // Function to display the list
    void display() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
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

    // Inserting nodes to demonstrate
    cdl.insertAtEnd(10);
    cdl.insertAtEnd(20);
    cdl.insertAtStart(5);
    cdl.insertAtMiddle(15, 2);  // Insert 15 after the 2nd position
    cdl.insertAtEnd(30);

    cout << "Circular Doubly Linked List: ";
    cdl.display();

    return 0;
}
