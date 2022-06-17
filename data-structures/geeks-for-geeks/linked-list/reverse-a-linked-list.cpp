// https://www.geeksforgeeks.org/reverse-a-linked-list/
// https://www.geeksforgeeks.org/recursively-reversing-a-linked-list-a-simple-implementation/

// { Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
public:
    //Function to reverse a linked list.
    // time: O(n), memory: O(1)
    struct Node* reverseList(struct Node *head)
    {
        Node* u = head -> next;
        Node* v = head;
        v -> next = 0;
        while(u) {
            Node* temp = u -> next;
            u -> next = v;
            v = u;
            u = temp;
        }
        return v;
    }

};



// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;

        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob. reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
