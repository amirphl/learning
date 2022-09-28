// https://www.geeksforgeeks.org/alternating-split-of-a-given-singly-linked-list/

//{ Driver Code Starts

#include <iostream>
#include <stdio.h>
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

void append(struct Node** headRef, int newData)
{
    struct Node* new_node = new Node(newData);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)last = last->next;
    last->next = new_node;
}

void printList(struct Node *node)
{
    while(node!=NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}

void alternatingSplitList(struct Node*);

struct Node* a;
struct Node* b;

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        a=b=NULL;
        struct Node* head = NULL;


        int n, k;
        cin>>n;

        while(n--)
        {
            cin>>k;
            append(&head, k);
        }

        alternatingSplitList(head);
        printList(a);
        printList(b);
    }
    return 0;
}




// } Driver Code Ends


/*
structure of node is as
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


/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list

*/
// time: O(n), memory: O(1)
void alternatingSplitList(struct Node* head)
{
    a = 0;
    b = 0;
    struct Node* a_tail = 0;
    struct Node* b_tail = 0;
    bool f = true;
    while(head) {
        struct Node* t = head -> next;
        if (f) {
            if (a) {
                a_tail -> next = head;
                a_tail = a_tail -> next;
                a_tail -> next = 0;
            } else {
                a = a_tail = head;
                a_tail -> next = 0;
            }
        } else {
            if (b) {
                b_tail -> next = head;
                b_tail = b_tail -> next;
                b_tail -> next = 0;
            } else {
                b = b_tail = head;
                b_tail -> next = 0;
            }
        }
        f = !f;
        head = t;
    }
}


