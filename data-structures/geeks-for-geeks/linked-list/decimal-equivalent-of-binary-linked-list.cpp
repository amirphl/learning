// https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/

//{ Driver Code Starts
// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

long long unsigned int decimalValue(struct Node *head);

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin>>T;

    while(T--) {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

        cout << decimalValue(head) << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

// Should return decimal equivalent modulo 1000000007 of binary linked list
// time: O(n), memory: O(1)
long long unsigned int decimalValue(Node *head)
{
    Node* u = head;
    Node* prv = 0;
    while(u) {
        Node* t = u -> next;
        u -> next = prv;
        prv = u;
        u = t;
    }
    u = prv;

    long long unsigned int p = 1, res = 0;
    while(u) {
        if (u -> data) {
            res = (res + p) % MOD;
        }
        p = (p * 2) % MOD;
        u = u -> next;
    }
    return res;
}

