// insert a node at a given position
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

// Function to insert a new node at a given position
Node *insertAtPosition(Node *head, int pos, int new_data) {

    // Create a new node
    Node *new_node = new Node(new_data);

    // Insertion at the beginning
    if (pos == 1) {
        new_node->next = head;

        // If the linked list is not empty, set the prev of head to new node
        if (head != NULL)
            head->prev = new_node;

        // Set the new node as the head of linked list
        head = new_node;
        return head;
    }

    Node *curr = head;
    // Traverse the list to find the node before the
    // insertion point
    for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr->next;
    }

    // If the position is out of bounds
    if (curr == NULL) {
        cout << "Position is out of bounds." << endl;
        delete new_node;
        return head;
    }

    // Set the prev of new node to curr
    new_node->prev = curr;

    // Set the new of new node to next of curr
    new_node->next = curr->next;

    // Update the next of current node to new node
    curr->next = new_node;

    // If the new node is not the last node, update prev of next node to new node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;

    // Return the head of the doubly linked list
    return head;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // Create a harcoded doubly linked list:
    // 1 <-> 2 <-> 4 
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    // Print the original list
    cout << "Original Linked List: ";
    printList(head);

    // Insert new node with data 3 at position 3
    cout << "Inserting Node with data 3 at position 3: ";
    int data = 3;
    int pos = 3;
    head = insertAtPosition(head, pos, data);

    // Print the updated list
    printList(head);

    return 0;
}
