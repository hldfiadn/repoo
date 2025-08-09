// Recursive CPP program to recursively insert
// a node and recursively print the list.
// Source: geeksforgeeks.com
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};

// Allocates a new node with given data
Node *newNode(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the
// end of linked list using recursion.
Node* insertEnd(Node* head, int data) {
    // If linked list is empty, create a
    // new node (Assuming newNode() allocates
    // a new node with given data)
    cout << "Melakukan pengecekan pada head apakah null atau tidak..." << endl;
    if (head == NULL){
        cout << "Head == NULL -> memasukkan data " << data << " pada linked list" << endl << endl;
        return newNode(data);
    }
    // If we have not reached end, keep traversing
    // recursively.
    else {
        cout << "Head == " << head->data << " -> lanjut melakukan travers" << endl;
        head->next = insertEnd(head->next, data);
    }
    return head;
}

void traverse(Node* head) {
    if (head == NULL)
    return;
    // If head is not NULL, print current node
    // and recur for remaining list
    cout << head->data << " ";
    traverse(head->next);
}

void insertAfterKey(Node* p, int key, int data) {
    
}


// Driver code
int main() {
    Node* head = NULL;
    head = insertEnd(head, 6);
    head = insertEnd(head, 8);
    head = insertEnd(head, 10);
    head = insertEnd(head, 12);
    head = insertEnd(head, 14);
    traverse(head);
}