// https://www.geeksforgeeks.org/rearrange-a-linked-list-such-that-all-even-and-odd-positioned-nodes-are-together/

// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

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

class Solution
{
public:
    // time: O(n), memory: O(1)
    void rearrangeEvenOdd(Node *head)
    {
        Node* odd = new Node(1);
        Node* even = new Node(2);
        Node* curr_odd = odd;
        Node* curr_even = even;

        Node* u = head;
        int i = 1;
        while(u) {
            Node* t = u -> next;
            if (i % 2 == 0) {
                curr_even -> next = u;
                curr_even = u;
            } else {
                curr_odd -> next = u;
                curr_odd = u;
            }
            u -> next = 0;
            u = t;
            i++;
        }
        curr_odd -> next = even -> next;
        delete(odd);
        delete(even);
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {
                head = temp = new Node(l);

            }
            else
            {   temp->next = new Node(l);
                temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends
