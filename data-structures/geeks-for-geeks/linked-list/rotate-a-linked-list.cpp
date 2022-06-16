// https://www.geeksforgeeks.org/rotate-a-linked-list/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

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
    //Function to rotate a linked list.
    // time: O(n), memory: O(1)
    Node* rotate(Node* head, int k)
    {
        int n = 0;
        Node* u = head;
        Node* v = 0;
        while(u) {
            v = u;
            u = u -> next;
            n++;
        }
        if (k >= n || k == 0) {
            return head;
        }
        u = head;
        while(1 < k) {
            u = u -> next;
            k--;
        }
        // cout << u -> data << endl;
        // return head;
        Node* t = u -> next;
        u -> next = 0;
        v -> next = head;
        return t;
    }
};



// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;

        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;

        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin>> k;

        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
// } Driver Code Ends
