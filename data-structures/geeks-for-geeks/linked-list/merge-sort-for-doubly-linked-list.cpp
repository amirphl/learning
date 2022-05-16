// https://www.geeksforgeeks.org/merge-sort-for-doubly-linked-list/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */

// time: O(nlogn), memory: O(logn)
void sortDoublyRec(struct Node*& head, struct Node*& tail)
{
    if (head == tail) {
        return;
    }
    if (head -> next == tail) {
        if (head -> data < tail -> data) {
            return;
        }
        tail -> next = head;
        tail -> prev = 0;
        head -> prev = tail;
        head -> next = 0;
        Node* temp = head;
        head = tail;
        tail = head;
        return;
    }
    Node* u = head;
    Node* mid = head;
    while (u && u != tail) {
        mid = mid -> next;
        u = u -> next;
        if (u && u != tail) {
            u = u -> next;
        }
    }
    Node* mid_next = mid -> next;
    mid -> next = 0;
    mid_next -> prev = 0;
    sortDoublyRec(head, mid);
    sortDoublyRec(mid_next, tail);
    Node* v;
    Node* h;
    if (head -> data < mid_next -> data) {
        v = head;
        h = head;
        head = head -> next;
    } else {
        v = mid_next;
        h = mid_next;
        mid_next = mid_next -> next;
    }
    int a, b;
    while(head || mid_next) {
        a = (head) ? (head -> data) : INT_MAX;
        b = (mid_next) ? (mid_next -> data) : INT_MAX;
        if (a < b) {
            v -> next = head;
            head -> prev = v;
            head = head -> next;
        } else {
            v -> next = mid_next;
            mid_next -> prev = v;
            mid_next = mid_next -> next;
        }
        v = v -> next;
    }
    head = h;
    tail = v;
}

//Function to sort the given doubly linked list using Merge Sort.
struct Node* sortDoubly(struct Node* head)
{
    Node* tail = head;
	while (tail -> next) {
	    tail = tail -> next;
	}
	sortDoublyRec(head, tail);
	return head;
}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends
