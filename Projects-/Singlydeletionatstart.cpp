//Deletion AT START
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

// Function to delete the head node
Node* deleteHead(Node* head)
{
    // Base case if linked list is empty
    if (head == nullptr)
        return nullptr;
  
    // Change the head pointer to the next node
    // and free the original head 
    Node* temp = head;
    head = head->next;
    delete temp;
  
    // Return the new head
    return head;
}

void printList(Node* head)
{ while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    // Creating a linked list
    // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);
    // Deleting the head node
    head = deleteHead(head);
    cout << "List after deleting the head: ";
    printList(head);

    return 0;
}
