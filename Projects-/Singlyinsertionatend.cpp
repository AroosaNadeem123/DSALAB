//	Insert at END
#include <iostream>
using namespace std;
// A linked list node
class Node {
public:
    int data;
    Node* next;
    // Constructor to initialize a new node with data
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};
// Given the head of a list and an int, appends
// a new node at the end and returns the head.
Node* append(Node* head, int new_data) {
    // Create a new node
    Node* new_node = new Node(new_data);
    // If the Linked List is empty, make
    // the new node as the head and return
    if (head == nullptr) {
        return new_node;
    }
    // Store the head reference in a temporary variable
    Node* last = head;

    // Traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }
    // Change the next pointer of the last node 
    // to point to the new node
    last->next = new_node;
    // Return the head of the list
    return head;
}
// This function prints the contents 
// of the linked list starting from the head
void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}
// Driver code
int main() {
    // Create a hard-coded linked list:
    // 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);

    cout << "Created Linked list is:";
    printList(head);
    // Example of appending a node at the end
    head = append(head, 1);
    cout << "\nAfter inserting 1 at the end:";
    printList(head);
    return 0;
}
