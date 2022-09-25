// https://www.geeksforgeeks.org/sort-linked-list-already-sorted-absolute-values/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
    Node* next;
    int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
    Node* newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution
{
public:
    // time: O(n), memory: O(1)
    void sortList(Node** head)
    {
        Node* neg_tail = 0;
        Node* neg_head = 0;
        Node* pos_tail = 0;
        Node* pos_head = 0;
        Node* u = *head;
        while(u) {
            Node* t = u -> next;
            u -> next = 0;
            if (u -> data < 0) {
                if (!neg_tail) {
                    neg_head = neg_tail = u;
                } else {
                    u -> next = neg_head;
                    neg_head = u;
                }
            } else {
                if (!pos_tail) {
                    pos_head = pos_tail = u;
                } else {
                    pos_tail -> next = u;
                    pos_tail = u;
                }
            }
            u = t;
        }
        if (neg_head) {
            neg_tail -> next = pos_head;
            *head = neg_head;
        }
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

    int t = 0;
    int n = 0;
    cin >> t;
    while (t--)
    {
        Node* head = NULL;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            // push(&head, a);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            push(&head, arr[i]);
        }
        // printList(head);

        Solution ob;
        ob.sortList(&head);

        printList(head);

    }
    return 0;
}

// } Driver Code Ends
