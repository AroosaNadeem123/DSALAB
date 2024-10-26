//Deletion AT END 
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

// Function to remove the last node
// of the linked list
Node* removeLastNode(struct Node* head)
{
    // If the list is empty, return nullptr
    if (head == nullptr) {
        return nullptr;
    }

    // If the list has only one node, delete it and return
    // nullptr
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != nullptr) {
        second_last = second_last->next;
    }

    // Delete the last node
    delete (second_last->next);

    // Change next of second last
    second_last->next = nullptr;

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

    // Removing the last node
    head = removeLastNode(head);

    cout << "List after removing the last node: ";
    printList(head);

    return 0;
}


