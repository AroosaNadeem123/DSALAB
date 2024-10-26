//deletion at secific position 
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int d) {
        data = d;
        prev = next = nullptr;
    }
};

// Deletes a node at a specific position (1-based index) in the list
Node* deleteAtPosition(Node* head, int position) {
    if (head == nullptr || position <= 0) {
        return head; // Invalid position or empty list
    }

    Node* curr = head;
    int count = 1;

    // Traverse to the node at the given position
    while (curr != nullptr && count < position) {
        curr = curr->next;
        count++;
    }

    // If the node to be deleted is not found (position is greater than list length)
    if (curr == nullptr) {
        cout << "Position out of bounds" << endl;
        return head;
    }

    // If the node is the head
    if (curr == head) {
        head = curr->next;
    }

    // Adjust the pointers of the previous and next nodes
    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    // Free the memory of the node to be deleted
    delete curr;

    return head;
}

// Prints the doubly linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Create a hardcoded doubly linked list:
    // 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    printList(head);

    // Delete node at position 3 (middle)
    head = deleteAtPosition(head, 3);
    cout << "After deletion at position 3: ";
    printList(head);

    return 0;
}
