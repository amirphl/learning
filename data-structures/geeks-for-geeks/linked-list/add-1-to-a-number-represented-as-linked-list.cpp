// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout<<"\n";
}


// } Driver Code Ends
//User function template for C++

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

class Solution
{
public:
    // time: O(n), memory: O(1)
    Node* addOne(Node *head)
    {
        Node* prv = 0;
        Node* u = head;
        while(u) {
            Node* t = u -> next;
            u -> next = prv;
            prv = u;
            u = t;
        }
        head = prv;
        u = head;
        while(u) {
            if (u -> data == 9) {
                u -> data = 0;
                u = u -> next;
            } else {
                (u -> data)++;
                break;
            }
        }
        Node* c = 0;
        if (!u) {
            c = new Node(1);
            c -> next = 0;
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
        if (c) {
            c -> next = prv;
            head = c;
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
        string s;
        cin>>s;

        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends
