// https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/

//{ Driver Code Starts
#include <bits/stdc++.h>
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
    Node *zigZag(Node* head)
    {
        bool flag = true;
        Node* h = head;
        Node* prv = new Node(INT_MIN);
        prv -> next = h;
        Node* new_head = prv;
        while(h) {
            // cout << h -> data << endl;
            if (h -> next) {
                if ((flag && h -> data <= h -> next -> data) || (!flag && h -> data > h -> next -> data)) {
                    prv = h;
                    h = h -> next;
                } else {
                    Node* t = h -> next -> next;
                    prv -> next = h -> next;
                    h -> next -> next = h;
                    h -> next = t;
                    prv = prv -> next;
                }
                flag = !flag;
            } else {
                break;
            }
        }
        return new_head -> next;
    }
};

//{ Driver Code Starts.


int main() {
    // your code goes here
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
                temp=temp->next;
            }
        }
        Solution ob;
        Node *ans = ob.zigZag(head);
        print(ans);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
