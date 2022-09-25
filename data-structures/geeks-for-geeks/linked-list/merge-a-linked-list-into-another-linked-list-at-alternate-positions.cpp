// https://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/

//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<'\n';
}

void mergeList(struct Node **head1, struct Node **head2);

// Driver program to test above functions
int main()
{
    int T;
    cin>>T;
    while(T--) {
        int n1, n2, tmp;
        struct Node *a = NULL;
        struct Node *b = NULL;
        cin>>n1;
        while(n1--) {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>n2;
        while(n2--) {
            cin>>tmp;
            push(&b, tmp);
        }
        mergeList(&a, &b);
        printList(a);
        printList(b);
    }
    return 0;
}

// } Driver Code Ends


/*
structure of the node of the linked list is
struct Node
{
	int data;
	struct Node *next;

	Node(int x){
	    data = x;
	    next = NULL;
	}
};
*/
// complete this function
// time: O(n), memory: O(1)
void mergeList(struct Node **h1, struct Node **h2)
{
    struct Node* p = *h1;
    struct Node* q = *h2;
    while(p || q) {
        if (p && q) {
            struct Node* temp = p -> next;
            p -> next = q;
            struct Node* dump = q -> next;
            q -> next = temp;
            p = p -> next -> next;
            q = dump;
        } else if (p) {
            *h2 = 0;
            return;
        } else if (q) {
            *h2 = q;
            return;
        }
    }
    *h2 = 0;
}
