// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1/

// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

// time: O(n + m), memory: O(min(n + m))
Node* findIntersection(Node* p, Node* q)
{
    Node* res = (struct Node*)malloc(sizeof(struct Node));
    res -> data = INT_MIN;
    Node* last = res;
    Node* n;

    while(p && q) {
        if (p -> data == q -> data) {
            if (p -> data != last -> data) {
                n = (struct Node*)malloc(sizeof(struct Node));
                n -> data = p -> data;
                n -> next = 0;
                last -> next = n;
                last = n;
            }
            p = p -> next;
            q = q -> next;
        } else if (p -> data < q ->data) {
            p = p -> next;
        } else {
            q = q -> next;
        }
    }

    return res -> next;
}
