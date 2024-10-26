//inset at start 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;

    Node(int new_data) {
        data = new_data;
        next = prev = NULL;
    }
};

// Function to insert a new node at the front of doubly
// linked list
Node *insertAtFront(Node *head, int new_data) {

    // Create a new node
    Node *new_node = new Node(new_data);

    // Make next of new node as head
    new_node->next = head;

    // change prev of head node to new node
    if (head != NULL)
        head->prev = new_node;

    // Return the new node as the head of the doubly linked list
    return new_node;
}

void printList(Node *head) {

    Node *curr = head;
    while (curr != NULL) {
        cout << " " << curr->data;
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // Create a harcoded doubly linked list:
    // 2 <-> 3 <-> 4 
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    // Print the original list
    cout << "Original Linked List:";
    printList(head);

    // Insert a new node at the front of the list
    cout << "After inserting Node at the front:";
    int data = 1;
    head = insertAtFront(head, data);

    // Print the updated list
    printList(head);

    return 0;
}
