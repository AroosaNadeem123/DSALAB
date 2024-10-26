//	insertInMiddle
#include <iostream>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
// Function to insert a node at the middle
// of the linked list
Node *insertInMiddle(Node *head, int x) {

    // If the list is empty
    if (head == nullptr) {
        return new Node(x);
    }
    Node *newNode = new Node(x);
    Node *currNode = head;
    int len = 0;
    // Calculate the length of the linked list
    while (currNode != nullptr) {
        len++;
        currNode = currNode->next;
    }
    // Calculate the position to insert the new node
      int mid;
    if (len % 2 == 0) {
        mid = len / 2;
    }
    else {
        mid = (len + 1) / 2;
    }
    currNode = head;
    // Move to the position before where
    // the new node will be inserted
    while (mid > 1) {
        currNode = currNode->next;
          mid--;
    }
    // Insert the new node and adjust the links
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
}
void printList(Node *head) {
      Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    // Creating the list 1->2->4->5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    int x = 30;
    head = insertInMiddle(head, x);
    printList(head);
    return 0;
}
