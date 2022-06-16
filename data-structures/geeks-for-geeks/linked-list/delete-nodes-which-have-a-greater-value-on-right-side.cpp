// https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    // time: O(n), memory: O(1)
    Node *compute(Node *head)
    {
        Node* prv = 0;
        Node* u = head;
        while(u) {
            Node* t = u -> next;
            u -> next = prv;
            prv = u;
            u = t;
        }
        head = prv;
        u = prv -> next;
        while(u) {
            if (u -> data < prv -> data) {
                Node* t = u -> next;
                prv -> next = t;
                delete(u);
                u = t;
            } else {
                prv = u;
                u = u -> next;
            }
        }
        prv = 0;
        u = head;
        while(u) {
            Node* t = u -> next;
            u -> next = prv;
            prv = u;
            u = t;
        }
        return prv;
    }
};



// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int K;
        cin>>K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for(int i=0; i<K; i++) {
            int data;
            cin>>data;
            if(head==NULL)
                head=temp=new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
// } Driver Code Ends
