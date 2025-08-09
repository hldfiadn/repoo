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
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the
// end of linked list using recursion.
Node* insertEnd(Node* head, int data)
{
    // If linked list is empty, create a
    // new node (Assuming newNode() allocates
    // a new node with given data)
    if (head == NULL)
        return newNode(data);
    // If we have not reached end, keep traversing
    // recursively.
    else
        head->next = insertEnd(head->next, data);
    return head;
}

/*void insertAfterKey(Node* p, int key, int data)
{
    if(p->data == key) {
        Node *q;
        q = newNode(data);
        q->next = p->next;
        p->next = q;
    }
    else if (p->next == NULL){
        insertEnd(p, data);
    }
    else {
        insertAfterKey(p->next, key, data);
    }
}

void deleteKey(Node* prev, Node* p, int key)
{
	//prev digunakan untuk menunjuk ke node sebelum node yang akan dihapus
	//p digunakan untuk menunjuk ke node yang akan dihapus
	p = prev->next;
    
    if (p->data == key) {
        prev->next = p->next;
        free(p);
    }
    else {
        deleteKey(prev->next, p, key);
    }
}*/

void traverse(Node* head)
{
    if (head == NULL)
        return;
    // If head is not NULL, print current node
    // and recur for remaining list
    cout << head->data << " ";
    traverse(head->next);
}

// Driver code
int main()
{
    Node* head = NULL;
    head = insertEnd(head, 6);
    head = insertEnd(head, 8);
    head = insertEnd(head, 10);
    head = insertEnd(head, 12);
    head = insertEnd(head, 14);
    traverse(head);
    insertAfterKey(head, 12, 13);
    insertAfterKey(head, 8, 9);
    insertAfterKey(head, 15, 16);
    cout << "\n";
    traverse(head);
    cout << "\n";
    deleteKey(head, head, 12);
    traverse(head);
    return 0;

}