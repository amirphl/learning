// https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    // time: O(n), memory: O(1)
    Node* divide(int N, Node *head){
        Node* t = head;
        Node* dummy = (struct Node*)malloc(sizeof(struct Node));
        dummy -> next = head;
        Node* prv = dummy;
        Node* temp = dummy;
        while(t && t -> data % 2 == 0) {
            prv = t;
            t = t -> next;
        }
        if (!t)
            return head;
        dummy = prv;
        
        while(t) {
            if (t -> data % 2 == 0) {
                prv -> next = t -> next;
                t -> next = dummy -> next;
                dummy -> next = t;
                dummy = t;
                t = prv -> next;
            } else {
                prv = t;
                t = t -> next;
            }            
        }
        return temp -> next;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends
