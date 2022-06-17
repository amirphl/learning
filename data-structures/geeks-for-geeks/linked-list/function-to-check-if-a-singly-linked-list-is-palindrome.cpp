// https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
// We can also use Stack. Also recursion is possible.

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
public:
    //Function to check whether the list is palindrome.
    // time: O(n), memory: O(1)
    bool isPalindrome(Node *head)
    {
        Node* t = head;
        Node* u = head;
        int n = 0;
        while(u) {
            u = u -> next;
            n++;
            if (u) {
                u = u -> next;
                n++;
            } else {
                break;
            }
            t = t -> next;
        }

        if (n == 1)
            return true;
        if (n == 2)
            return head -> data == head -> next -> data;
        if (n % 2 == 0) {
            u = reverse(t);
        } else {
            u = reverse(t -> next);
        }

        while(head != t) {
            if (head -> data != u -> data)
                return false;
            head = head -> next;
            u = u -> next;
        }
        return true;
    }

    Node* reverse(Node *head) {
        Node* prev = 0;
        Node* t;
        Node* u;
        while(head) {
            t = head;
            u = head -> next;
            head -> next = prev;
            head = u;
            prev = t;
        }
        return prev;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends
