// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;

    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }

    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
public:
    //Function to remove a loop in the linked list.
    // time: O(n), memory: O(1)
    void removeLoop(Node* head)
    {
        Node* u = head;
        Node* v = head;
        while(u && v) {
            //corner case
            // 6
            // 1 2 3 4 5 6
            // 1
            if (u -> next == head) {
                u -> next = 0;
                return;
            }
            u = u -> next;
            if (u) {
                //corner case
                // 6
                // 1 2 3 4 5 6
                // 1
                if (u -> next == head) {
                    u -> next = 0;
                    return;
                }
                u = u -> next;
            }
            v = v -> next;
            if (u == v) {
                break;
            }
        }
        if (!u || !v) {
            return;
        }
        // corner case
        // 6
        // 1 2 3 4 5 6
        // 6
        if (u -> next == u) {
            u -> next = 0;
            return;
        }
        // cout << " --> " << u -> data << endl;
        Node* prv = u;
        Node* nxt = u -> next;
        u -> next = 0;
        u = nxt;
        v = head;
        int n1 = 0;
        int n2 = 0;
        while(u) {
            // cout << u -> data << " _ ";
            u = u -> next;
            n1++;
        }
        while(v) {
            // cout << v -> data << " + ";
            v = v -> next;
            n2++;
        }
        // cout << n1 << " " << n2 << endl;
        u = nxt;
        v = head;
        if (n2 > n1) {
            while(n2 - n1 > 0) {
                v = v -> next;
                n2--;
            }
        } else {
            while(n1 - n2 > 0) {
                u = u -> next;
                n1--;
            }
        }
        // cout << u -> data << " " << v -> data << endl;
        // corner case
        if (u == v) {

        } else {
            while(u -> next != v -> next) {
                u = u -> next;
                v = v -> next;
            }
            // cout << u -> data << endl;
            u -> next = 0;
            prv -> next = nxt;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;

        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);

        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin>> pos;
        loopHere(head,tail,pos);

        Solution ob;
        ob.removeLoop(head);

        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
    return 0;
}
// } Driver Code Ends
