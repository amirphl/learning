// https://www.geeksforgeeks.org/how-to-sort-a-linked-list-that-is-sorted-alternating-ascending-and-descending-orders/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data =x;
        next = NULL;
    }
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
    struct Node* new_node = new Node(newData);
    struct Node *last = *headRef;
    if (*headRef == NULL)
    {
        *headRef = new_node;
        *tailRef = *headRef;
        return;
    }

    (*tailRef) -> next = new_node;
    *tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        struct Node* head = NULL;
        struct Node* tail = NULL;
        int n, k;
        cin>>n;
        for(int i=0; i<n ; i++) {
            cin>>k;
            append(&head, &tail, k);
        }
        sort(&head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;

	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
// time: O(n), memory: O(1)
void sort(Node **head)
{
    if ((*head) -> next == 0) {
        return;
    }
    Node* f = 0;
    Node* h = *head;
    while(h && h -> next) {
        Node* mid = h -> next;
        h -> next = h -> next -> next;
        mid -> next = f;
        f = mid;
        if (h -> next == 0) {
            break;
        }
        h = h -> next;
    }
    h = *head;
    Node* g = new Node(INT_MAX);
    *head = g;
    while(h || f) {
        if (h && f) {
            if (h -> data < f -> data) {
                g -> next = h;
                g = h;
                h = h -> next;
            } else {
                g -> next = f;
                g = f;
                f = f -> next;
            }
        } else if (h) {
            g -> next = h;
            g = h;
            h = h -> next;
        } else if (f) {
            g -> next = f;
            g = f;
            f = f -> next;
        }
    }
    g -> next = 0;
    g = (*head) -> next;
    free(*head);
    *head = g;
}
