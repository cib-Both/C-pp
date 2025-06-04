#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int dataValue) : data(dataValue), next(nullptr) {}
};

// Given a node prev_node, insert a new node after the given prev_node
void insert(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    // Allocate new node
    Node* new_node = new Node(new_data);

    // Make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // Move the next of prev_node as new_node
    prev_node->next = new_node;
}

void addTail(Node** head_ref, int new_data) {

    Node* new_node = new Node(new_data);// Allocate new node
    
    // If the linked list is empty, make the new node the head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    
    // traverse to the last node
    Node* current = *head_ref;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    current->next = new_node; // new node to the end
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = new Node(11);
    Node* second = new Node(27);
    Node* third = new Node(23);
    Node* fourth = new Node(12);
    Node* fifth = new Node(99);
    Node* sixth = new Node(102);
    Node* seventh = new Node(56);
    Node* eighth = new Node(28);
    Node* ninth = new Node(10);
    Node* tenth = new Node(39);

    // Connect
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = nullptr;

    cout << "Original linked list: \n";
    display(head);

    insert(third, 74);
    cout << "\nAfter insert 74 at third link: \n";
    display(head);

    addTail(&head, 100);
    cout << "\nAfter adding 100 to tail: \n";
    display(head);

    return 0;
}



