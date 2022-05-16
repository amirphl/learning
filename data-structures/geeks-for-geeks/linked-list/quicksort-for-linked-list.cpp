// https://www.geeksforgeeks.org/quicksort-for-linked-list/

// Note: Initial code (commented code) was written to swap nodes, not values! (It was a better approach)
// take a look at this one too: https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
// Quicksort can be implemented for Linked List only when we can pick a fixed point as the pivot (like the last element in the above implementation). Random QuickSort cannot be efficiently implemented for Linked Lists by picking random pivot.

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
/* a Node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

void swap(int* a, int* b )
{   
    int t = *a;
    *a = *b;
    *b = t;
}

Node* partition(Node *l, Node *h);

void _quickSort(struct Node* l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
void quickSort(struct Node *head)
{
    // Find last Node
    struct Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}

// A utility function to print contents of arr
void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}

 
/* Driver program to test above function */
int main()
{
    int t,x,n,i;
    scanf("%d",&t);
    while(t--)
    {
        /* Start with the empty list */
        struct Node *p,*temp,*head = NULL;
        scanf("%d",&n);
        scanf("%d",&x);
        head=new Node(x);
        p=head;
        for(i=0;i<n-1;i++){
            scanf("%d",&x);
            /* Let us create the doubly linked list 10<->8<->4<->2 */
        	temp=new Node(x);
        	p->next=temp;
        	temp->prev=p;
            p=p->next;
        }
    
    //printList(head); 
    /* delete Nodes from the doubly linked list */
	
    quickSort(head);
  
    /* Modified linked list will be NULL<-8->NULL */
    printList(head);           
    while(head->next!=NULL)
    {
	  temp=head;
	  head=head->next;
	  free(temp);
	}
	  free(head);
	}
    return 0;
}
// } Driver Code Ends


/* a Node of the doubly linked list */


/*
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/

void swap(Node* low, Node* high) {
    // Node* t = high -> prev;
    // Node* v = high -> next;
    // if (low -> next == high) {
    //     low -> next = v;
    //     if (v) {
    //         v -> prev = low;
    //     }
    //     high -> prev = low -> prev;
    //     if (low -> prev) {
    //         low -> prev -> next = high;
    //     }
    //     high -> next = low;
    //     low -> prev = high;
    //     return;
    // }
    // if (low -> prev) {
    //     low -> prev -> next = high;
    // }
    // high -> prev = low -> prev;
    // high -> next = low -> next;
    // if (low -> next) {
    //     low -> next -> prev = high;
    // }

    // // ------------

    // if (t) {
    //     t -> next = low;
    // }
    // low -> prev = t;
    // low -> next = v;
    // if (v) {
    //     v -> prev = low;
    // }
    int temp = low -> data;
    low -> data = high -> data;
    high -> data = temp;
}

// time: O(n), memory: O(1)
Node* partition(Node* head, Node* tail) {
    if (head == tail) {
        return head;
    }
    if (head -> next == tail) {
        if (head -> data > tail -> data) {
            // tail -> next = head;
            // tail -> prev = 0;
            // head -> prev = tail;
            // head -> next = 0;
            int temp = head -> data;
            head -> data = tail -> data;
            tail -> data = temp;
        }
        return tail;
    }
    Node* pivot = tail;
    Node* left = head;
    Node* right = tail -> prev;
    // right -> next = 0;

    while(left != right) {
        if (right -> data >= pivot -> data) {
            right = right -> prev;
            continue;
        }
        while(left != right && left -> data <= pivot -> data) {
            left = left -> next;
        }
        if (left == right) {
            break;
        }
        // Node* l = right;
        // Node* r = left;
        // swap(left, right);
        // left = l;
        // right = r;
        // right = right -> prev;
        swap(left, right);
        right = right -> prev;
    }
    // if (left -> next == 0) {
    //     if (pivot -> data > left -> data) {
    //         pivot -> next = 0;
    //         pivot -> prev = left;
    //         left -> next = pivot;
    //     } else {
    //         pivot -> next = left;
    //         pivot -> prev = left -> prev;
    //         left -> prev -> next = pivot;
    //         left -> prev = pivot;
    //     }
    // } else if (left -> prev == 0) {
    // if (left -> prev == 0)
    //     if (pivot -> data > left -> data) {
    //         pivot -> next = left -> next;
    //         left -> next -> prev = pivot;
    //         left -> next = pivot;
    //         pivot -> prev = left;
    //     } else {
    //         pivot -> prev = 0;
    //         pivot -> next = left;
    //         left -> prev = pivot;
    //     }
    // } else if (pivot -> data > left -> data) {
    //     pivot -> next = left -> next;
    //     left -> next -> prev = pivot;
    //     left -> next = pivot;
    //     pivot -> prev = left;
    // } else {
    //     pivot -> next = left;
    //     pivot -> prev = left -> prev;
    //     left -> prev -> next = pivot;
    //     left -> prev = pivot;
    // }
    if (left -> data > pivot -> data) {
        swap(left, pivot);
        pivot = left;
    } else {
        swap(left -> next, pivot);
        pivot = left -> next;
    }
    return pivot;
}
