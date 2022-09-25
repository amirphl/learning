// https://www.geeksforgeeks.org/multiply-two-numbers-represented-linked-lists/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);

    return new_Node;
}


Node *reverse(Node **r)
{
    Node *prev =NULL;
    Node *cur = *r;
    Node *nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);

    /* link the old list off the new Node */
    new_Node->next = (*head_ref);

    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}


void freeList(struct Node *Node)
{
    struct Node* temp;
    while(Node != NULL)
    {

        temp=Node;
        Node = Node->next;
        free(temp);
    }

}


/* Multiply contents of two linked lists */
long long  multiplyTwoLists (struct Node*, struct Node*);

// A utility function to print a linked list
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Driver program to test above function */
int main(void)
{


    int t,n,m,i,x;
    cin>>t;
    while(t--)
    {

        struct Node* first = NULL;
        struct Node* second = NULL;
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>x;
            push(&first, x);
        }
        cin>>m;
        for(i=0; i<m; i++)
        {
            cin>>x;
            push(&second, x);
        }

        reverse(&first);
        reverse(&second);
        long long res = multiplyTwoLists(first,second);

        cout<<res<<endl;
        freeList(first);
        freeList(second);

    }
    return 0;
}

// } Driver Code Ends


/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/
// time: O(n*n), memory: O(1)
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    int mod = 1e9 + 7;
    Node* u = l2;
    Node* v = 0;
    while(u) {
        Node* temp = u -> next;
        u -> next = v;
        v = u;
        u = temp;
    }
    Node* v_backup = v;

    int n = 0;
    Node* t = l1;
    while(t) {
        t = t -> next;
        n++;
    }
    t = l1;
    long long res = 0;
    while(t) {
        n--;
        // cout << t -> data << ": ";
        int m = 0;
        while(v) {
            long long s = (v -> data) * (t -> data);
            long long z = 1;
            int i = 0;
            while(i < n + m) {
                z = ((z * 10) % mod);
                i++;
            }
            res = (res + (s * z)) % mod;
            m++;
            // cout << v -> data << "|" << s << "|" << z << " ";
            v = v -> next;
        }
        // cout << endl;
        v = v_backup;
        t = t -> next;
    }
    return res;
}
