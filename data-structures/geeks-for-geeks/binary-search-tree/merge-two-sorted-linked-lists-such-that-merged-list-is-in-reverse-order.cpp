// https://www.geeksforgeeks.org/merge-two-sorted-linked-lists-such-that-merged-list-is-in-reverse-order/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

// time: O(n + m), memory: O(1)
struct Node* mergeResult(Node* u, Node* v)
{
    struct Node* fake = 0;
    while(u || v) {
        if (u && v && u -> data < v -> data) {
            struct Node* temp = u -> next;
            u -> next = fake;
            fake = u;
            u = temp;
        } else if (u && v && u -> data >= v -> data) {
            struct Node* temp = v -> next;
            v -> next = fake;
            fake = v;
            v = temp;
        } else if (u) {
            struct Node* temp = u -> next;
            u -> next = fake;
            fake = u;
            u = temp;
        } else if (v) {
            struct Node* temp = v -> next;
            v -> next = fake;
            fake = v;
            v = temp;
        }
    }
    return fake;
}
