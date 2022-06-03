// https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
// https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    // time: O(n), memory: O(logn)
    TNode* sortedListToBST(LNode *head) {
        int n = 1;
        LNode* tail = head;
        while(tail -> next) {
            tail = tail -> next;
            n++;
        }
        TNode* root = allocate(n);
        fill(root, head);
        return root;
    }

    // time: O(n), memory: O(logn)
    TNode* allocate(int n) {
        if (n == 0) {
            return 0;
        }
        TNode* t = new TNode(INT_MAX);
        t -> left = allocate(n / 2);
        t -> right = allocate(n - 1 - n / 2);
        return t;
    }

    // time: O(n), memory: O(1)
    void fill(TNode* root, LNode* head) {
        TNode* curr = root;
        while(curr) {
            if (curr -> left) {
                TNode* r = curr -> left;
                while(r -> right != 0 && r -> right != curr) {
                    r = r -> right;
                }
                if (r -> right) {
                    r -> right = 0;
                    curr -> data = head -> data;
                    head = head -> next;
                    curr = curr -> right;
                } else {
                    r -> right = curr;
                    curr = curr -> left;
                }
            } else {
                curr -> data = head -> data;
                head = head -> next;
                curr = curr -> right;
            }
        }
    }


    // time: O(nlogn), memory: O(logn)
    TNode* sortedListToBST2(LNode *head) {
        LNode* tail = head;
        while(tail -> next) {
            tail = tail -> next;
        }
        return sortedListToBSTRec(head, tail);
    }
    TNode* sortedListToBSTRec(LNode* left, LNode* right) {
        if (left == right) {
            TNode* new_node = new TNode(left -> data);
            return new_node;
        }
        if (left -> next == right) {
            TNode* new_node_1 = new TNode(left -> data);
            TNode* new_node_2 = new TNode(right -> data);
            new_node_2 -> left = new_node_1;
            return new_node_2;
        }
        LNode* u = left;
        LNode* v = left;
        LNode* prv;
        while(v != right) {
            prv = u;
            u = u -> next;
            v = v -> next;
            if (v != right) {
                v = v -> next;
            }
        }
        TNode* new_node = new TNode(u -> data);
        new_node -> left = sortedListToBSTRec(left, prv);
        new_node -> right = sortedListToBSTRec(u -> next, right);
        return new_node;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends
