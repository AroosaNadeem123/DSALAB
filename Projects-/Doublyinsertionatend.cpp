//  insert a node at the end 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;

    Node(int new_data) {
        data = new_data;
        next = prev = nullptr;
    }
};

// Function to insert a new node at the end of doubly linked list
Node *insertEnd(Node *head, int new_data) {

    // Create a new node
    Node *new_node = new Node(new_data);

    // If the linked list is empty, set the new node as the head of linked list
    if (head == NULL) {
        head = new_node;
    }
    else {
          Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        // Set the next of last node to new node
        curr->next = new_node;

        // Set prev of new node to last node
        new_node->prev = curr;
    }

    // Return the head of the doubly linked list
    return head;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // Create a hardcoded doubly linked list:
    // 1 <-> 2 <-> 3 
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Print the original list
    cout << "Original Linked List: ";
    printList(head);

    // Insert a new node with data 4 at the end
    cout << "Inserting Node with data 4 at the end: ";
    int data = 4;
    head = insertEnd(head, data);

    // Print the updated list
    printList(head);

    return 0;
}
