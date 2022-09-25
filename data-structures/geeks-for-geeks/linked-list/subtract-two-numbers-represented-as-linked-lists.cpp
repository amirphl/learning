// https://www.geeksforgeeks.org/subtract-two-numbers-represented-as-linked-lists/

//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;

    Node* head = new Node(val);
    Node* tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;

        cin>>n;
        Node* first = buildList(n);

        cin>>m;
        Node* second = buildList(m);

        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

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

//You are required to complete this method
// time: O(n), memory: O(1)
Node* subLinkedList(Node* l1, Node* l2)
{
    while(l1 && l1 -> data == 0) {
        l1 = l1 -> next;
    }
    while(l2 && l2 -> data == 0) {
        l2 = l2 -> next;
    }
    if (!l1) {
        l1 = new Node(0);
    }
    if (!l2) {
        l2 = new Node(0);
    }

    Node* u = l1;
    int p_len = 0;
    Node* v = l2;
    int q_len = 0;

    while(u) {
        u = u -> next;
        p_len++;
    }
    while(v) {
        v = v -> next;
        q_len++;
    }

    if (q_len > p_len) {
        Node* temp = l1;
        l1 = l2;
        l2 = temp;
    } else if (q_len == p_len) {
        u = l1;
        v = l2;
        while(u) {
            if (u -> data > v -> data) {
                break;
            } else if (u -> data < v -> data) {
                Node* temp = l1;
                l1 = l2;
                l2 = temp;
                break;
            }
            u = u -> next;
            v = v -> next;
        }
    }

    Node* p = 0;
    Node* q = 0;
    u = l1;
    v = l2;

    while(u) {
        Node* temp = u -> next;
        u -> next = p;
        p = u;
        u = temp;
    }

    while(v) {
        Node* temp = v -> next;
        v -> next = q;
        q = v;
        v = temp;
    }

    Node* res = 0;
    int carry = 0;
    while(p) {
        int diff = carry + p -> data - (q == 0 ? 0 : q -> data);
        Node* temp = new Node((diff < 0 ? 10 : 0) + diff);
        temp -> next = res;
        res = temp;
        p = p -> next;
        if (q)
            q = q -> next;
        carry = (diff < 0 ? -1 : 0);
    }

    while(res) {
        if (res -> data == 0) {
            Node* t = res -> next;
            free(res);
            res = t;
        } else {
            break;
        }
    }

    if (!res) {
        res = new Node(0);
    }
    return res;
}
