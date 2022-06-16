// https://www.cdn.geeksforgeeks.org/sum-of-two-linked-lists/

// { Driver Code Starts
// driver

#include <bits/stdc++.h>
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


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    //Function to add two numbers represented by linked list.
    // time: O(n), memory: O(1)
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* prv = 0;
        Node* u = first;
        while(u) {
            Node* t = u -> next;
            u -> next = prv;
            prv = u;
            u = t;
        }
        first = prv;
        prv = 0;
        u = second;
        while(u) {
            Node* t = u -> next;
            u -> next = prv;
            prv = u;
            u = t;
        }
        second = prv;
        // while(first) {
        //     cout << first -> data << " ";
        //     first = first -> next;
        // }
        // cout << endl;
        // while(second) {
        //     cout << second -> data << " ";
        //     second = second -> next;
        // }
        // cout << endl;

        u = first;
        Node* v = second;
        int c = 0;
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p -> data = 0;
        struct Node* head = p;
        while(u || v || c != 0) {
            if (u) {
                c += u -> data;
                u = u -> next;
            }
            if (v) {
                c += v -> data;
                v = v -> next;
            }
            p -> data = c % 10;
            p -> next = (struct Node*)malloc(sizeof(struct Node));
            p = p -> next;
            p -> data = 0;
            c = c / 10;
        }
        prv = 0;
        u = head;
        while(u) {
            Node* t = u -> next;
            u -> next = prv;
            prv = u;
            u = t;
        }
        head = prv;
        while(head && head -> data == 0) {
            Node* t = head -> next;
            delete(head);
            head = t;
        }
        return head;
    }
};


// { Driver Code Starts.

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
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends
