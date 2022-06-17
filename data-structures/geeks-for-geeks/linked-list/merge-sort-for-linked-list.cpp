// https://www.geeksforgeeks.org/merge-sort-for-linked-list/

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution {
public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        Node* tail = head;
        while(tail -> next) {
            tail = tail -> next;
        }
        mergeSortRec(head, tail);
        return head;
    }
    // time: O(nlogn), memory: O(logn)
    void mergeSortRec(Node*& head, Node*& tail) {
        if (head == tail) {
            return;
        }
        if (head -> next == tail) {
            if (head -> data < tail -> data) {
                return;
            }
            Node* u = tail;
            tail = head;
            head = u;
            tail -> next = 0;
            head -> next = tail;
            return;
        }
        Node* u = head;
        Node* mid = head;
        while (u && u != tail) {
            mid = mid -> next;
            u = u -> next;
            if (u && u != tail) {
                u = u -> next;
            }
        }
        // cout << u -> data << " + " << mid -> data << endl;
        Node* midnext = mid -> next;
        mid -> next = 0;
        mergeSortRec(head, mid);
        mergeSortRec(midnext, tail);
        // Node* t = midnext;
        // while(t) {
        //     cout << t -> data << " ++ ";
        //     t = t -> next;
        // }
        // cout << endl;
        Node* v;
        if (head -> data < midnext -> data) {
            v = head;
            head = head -> next;
        } else {
            v = midnext;
            midnext = midnext -> next;
        }
        Node* h = v;
        int a, b;
        while(head || midnext) {
            a = (head) ? (head -> data) : INT_MAX;
            b = (midnext) ? (midnext -> data) : INT_MAX;
            if (a < b) {
                v -> next = head;
                v = v -> next;
                head = head -> next;
            } else {
                v -> next = midnext;
                v = v -> next;
                midnext = midnext -> next;
            }
        }
        head = h;
        tail = v;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
