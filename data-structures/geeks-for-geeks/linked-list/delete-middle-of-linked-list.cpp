// https://www.geeksforgeeks.org/delete-middle-of-linked-list/

// { Driver Code Starts
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

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data <<" ";
        node = node->next;
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        head = deleteMid(head);
        printList(head);
    }
    return 0;
}


// } Driver Code Ends


/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
// time: O(n), memory: O(1)
Node* deleteMid(Node* head)
{
    if (head -> next == 0) {
        delete(head);
        return 0;
    }
    Node* v = 0;
    Node* u = head;
    while(u -> next) {
        u = u -> next;
        if (u -> next) {
            u = u -> next;
        }
        if (!v) {
            v = head;
        } else {
            v = v -> next;
        }
    }
    Node* t = v -> next;
    v -> next = v -> next -> next;
    delete(t);
    return head;
}
