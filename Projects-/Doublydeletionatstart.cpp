// C++ Program to delete a node from the beginning
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
// Deletes the first node (head) of the list 
// and returns the new head
Node* delHead(Node* head) {
    // If the list is empty, return nullptr
    if (head == nullptr) {
        return nullptr;
    }
    // Store the current head node to delete
    Node* temp = head;
    // Move head to the next node
    head = head->next;
    // Set the previous pointer of the
      // new head to nullptr
    if (head != nullptr) {
        head->prev = nullptr;
    }

    // Free the memory of the old head node
    delete temp;

    // Return the new head of the list
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
    // Create a hardcoded doubly linked list:
    // 1 <-> 2 <-> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head = delHead(head);
    printList(head);
    return 0;
}
