//Circular singly linklist inertion at start middle end 
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

    // Insert at the beginning
    void insertAtStart(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (last == nullptr) {  // If list is empty
            newNode->next = newNode;  // Point to itself
            last = newNode;
        } else {
            newNode->next = last->next;  // Point new node to first node
            last->next = newNode;        // Update last's next to new node
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (last == nullptr) {  // If list is empty
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;  // Link new node to first node
            last->next = newNode;        // Update last's next to new node
            last = newNode;              // Make new node the last node
        }
    }

    // Insert after a given position
    void insertAtMiddle(int value, int position) {
        if (last == nullptr || position <= 0) {  // If empty or position is zero, insert at start
            insertAtStart(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = last->next;  // Start from the first node

        // Traverse to the given position or stop at the end
        for (int i = 1; i < position && temp != last; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;  // Link new node to the next node
        temp->next = newNode;        // Link previous node to new node

        if (temp == last) {  // Update last if inserted at the end
            last = newNode;
        }
    }

    // Display the list
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
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtStart(5);
    cll.insertAtMiddle(15, 2);  // Insert 15 after 2nd position
    cll.insertAtEnd(30);

    cout << "Circular Linked List: ";
    cll.display();

    return 0;
}
