//Deletion AT MIDDLE
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Function to delete a node at a given position
Node* deleteNode(Node* head, int position)
{
    // previous of node to be deleted
    Node* prev;
    Node* temp = head;

    // Base case if linked list is empty
    if (temp == NULL)
        return head;

    // Case 1: Head is to be deleted
    if (position == 1) {
        // make next node as head and free old head
        head = temp->next;
        free(temp);
        return head;
    }
// Case 2: Node to be deleted is in middle
    // Traverse till given position
    for (int i = 1; i != position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If given position is found, delete node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    // If given position is not present
    else {
        cout << "Data not present\n";
    }

    return head;
}


void printList(Node* head)
{
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    // Creating a static linked list
    // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Deleting node at position 2
    int position = 2;
    head = deleteNode(head, position);

    cout << "List after deletion : ";
    printList(head);

    return 0;
}
