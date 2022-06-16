// https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// time: O(n), memory: O(1)
void reorderList(Node* head) {
    if (head -> next == 0) {
        return;
    }
    Node* u = head;
    Node* v = 0;
    int n = 0;
    while(u -> next) {
        if (v) {
            v = v -> next;
        } else {
            v = head;
        }
        u = u -> next;
        if (u -> next) {
            u = u -> next;
            n++;
        }
        n++;
    }
    if (n % 2 == 0) {
        v = v -> next;
    }
    Node* prv = v -> next;
    v -> next = 0;
    v = prv;
    v = v -> next;
    prv -> next = 0;
    while(v) {
        Node* temp = v -> next;
        v -> next = prv;
        prv = v;
        v = temp;
    }
    v = prv;
    u = head;
    while(u && v) {
        Node* temp = u -> next;
        u -> next = v;
        u = v;
        v = v -> next;
        u -> next = temp;
        u = u -> next;
    }
}
