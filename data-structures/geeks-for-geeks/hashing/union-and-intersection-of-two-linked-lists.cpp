// https://www.geeksforgeeks.org/union-and-intersection-of-two-linked-lists/

//{ Driver Code Starts
#include<bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;

    Node* head = new Node(val);
    Node* tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;

        cin>>n;
        Node* first = buildList(n);

        cin>>m;
        Node* second = buildList(m);

        printList(makeUnion(first,second));
    }
    return 0;
}

// } Driver Code Ends


/*
// structure of the node is as follows

struct node
{
	int data;
	struct node* next;

	node(int x){
	    data = x;
	    next = NULL;
	}

};

*/
// time: O(nlogn), memory: O(n)
struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int> s;
    struct Node* u = head1;
    struct Node* prv = 0;
    while(u) {
        if (s.find(u -> data) != s.end()) {
            prv -> next = u -> next;
            free(u);
            u = prv -> next;
        } else {
            s.insert(u -> data);
            prv = u;
            u = u -> next;
        }
        if (u == 0 && head2) {
            prv -> next = head2;
            u = head2;
            head2 = 0;
        }
    }
    u = head1;
    for(auto& x: s) {
        u -> data = x;
        u = u -> next;
    }
    return head1;
}

