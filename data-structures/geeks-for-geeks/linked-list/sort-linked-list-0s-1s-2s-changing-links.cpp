// https://www.geeksforgeeks.org/sort-linked-list-0s-1s-2s-changing-links/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    // time: O(n), memory: O(1)
    Node* segregate(Node *head) {
        Node* zero = new Node(3);
        zero -> next = 0;
        Node* one = new Node(3);
        one -> next = 0;
        Node* two = new Node(3);
        two -> next = 0;
        Node* curr_0 = zero;
        Node* curr_1 = one;
        Node* curr_2 = two;

        Node* u = head;
        while(u) {
            Node* t = u -> next;
            if (u -> data == 0) {
                curr_0 -> next = u;
                curr_0 = u;
            } else if (u -> data == 1) {
                curr_1 -> next = u;
                curr_1 = u;
            } else {
                curr_2 -> next = u;
                curr_2 = u;
            }
            u -> next = 0;
            u = t;
        }

        Node* tail;
        if (curr_0 != zero) {
            head = zero -> next;
            tail = curr_0;
        } else {
            head = 0;
            tail = 0;
        }
        if (curr_1 != one) {
            if (!head) {
                head = one -> next;
            } else {
                tail -> next = one -> next;
            }
            tail = curr_1;
        }
        if (curr_2 != two) {
            if (!head) {
                head = two -> next;
            } else {
                tail -> next = two -> next;
            }
            tail = curr_2;
        }
        delete(zero);
        delete(one);
        delete(two);
        return head;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends
