//delete a node from the end
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

// Function to delete the last node of
// the doubly linked list
Node* delLast(Node* head) {

    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Traverse to the last node
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    // Update the previous node's next pointer
    if (curr->prev != nullptr) {
        curr->prev->next = nullptr;
    }

    // Delete the last node
    delete curr; 

    // Return the updated head
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    // Create a hardcoded doubly linked list: 1 <-> 2 <-> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head = delLast(head);
    printList(head);

    return 0;
}