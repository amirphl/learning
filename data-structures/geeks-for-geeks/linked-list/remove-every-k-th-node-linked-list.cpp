// https://www.geeksforgeeks.org/remove-every-k-th-node-linked-list/

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

Node *deleteK(Node *,int);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;

    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;
    cin>>T;
    while(T--) {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        int K;
        cin>>K;
        Node *res = deleteK(head,K);
        Node *temp = res;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* Link list Node

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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
// time: O(n), memory: O(1)
Node* deleteK(Node *head, int k)
{
    if (k == 0) {
        return head;
    }
    if (k == 1) {
        // delete all nodes
        return 0;
    }
    Node* u = head;
    while(u) {
        int n = k;
        while(n > 2 && u) {
            u = u -> next;
            n--;
        }
        if (!u) {
            break;
        }
        Node* t = u -> next;
        if (!t) {
            break;
        }
        Node* v = t -> next;
        // free(t);
        u -> next = v;
        u = v;
    }
    return head;
}

