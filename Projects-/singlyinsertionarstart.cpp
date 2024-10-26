//insertion at start
#include <iostream>
using namespace std;
// Define a node in the linked list
struct Node {
    int data; // Data stored in the node
    Node* next; // Pointer to the next node in the list
    // Constructor to initialize the node
    Node(int new_data)
    {
        data = new_data;
        next = nullptr; // Set next to null
    }
};
// Function to insert a new node at the beginning of the
// list
Node* insertAtFront(Node* head, int new_data)
{
    // Create a new node with the given data
    Node* new_node = new Node(new_data);
    // Make the next of the new node point to the current
    // head
    new_node->next = head;

    // Return the new node as the new head of the list
    return new_node;
}
// Function to print the contents of the linked list
void printList(Node* head)
{
    // Start from the head of the list
    Node* curr = head;
    // Traverse the list
    while (curr != nullptr) {
        // Print the current node's data
        cout << " " << curr->data;
        // Move to the next node
        curr = curr->next;
    }
    // Print a newline at the end
    cout << endl;
}
// Driver code to test the functions
int main()
{
    // Create the linked list 2->3->4->5
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    // Print the original list
    cout << "Original Linked List:";
    printList(head);
    // Insert a new node at the front of the list
    cout << "After inserting Nodes at the front:";
    int data = 1;
    head = insertAtFront(head, data);
    // Print the updated list
    printList(head);
    return 0;
}
