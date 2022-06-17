// https://www.geeksforgeeks.org/sorted-insert-for-circular-linked-list/

// { Driver Code Starts
#include<bits/stdc++.h>
/* structure for a Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};
 */

// This function should return head of
// the modified list
class Solution
{
public:
    // time: O(n), memory: O(1)
    Node *sortedInsert(Node* head, int data)
    {
        Node* v = new Node(data);
        if (!head) {
            head = v;
            head -> next = head;
            return head;
        }
        if (head -> data > data) {
            v -> next = head;
            Node* u = head -> next;
            while(u -> next != head) {
                u = u -> next;
            }
            u -> next = v;
            return v;
        }
        Node* prv = head;
        Node* u = head -> next;
        while(u != head) {
            if (u -> data > data) {
                break;
            }
            prv = u;
            u = u -> next;
        }
        //   std::cout << u -> data << std::endl;
        if (u == head) {
            if (head -> data > data) {
                prv -> next = v;
                v -> next = u;
                return v;
            } else {
                Node* t = u -> next;
                u -> next = v;
                v -> next = t;
            }
        } else {
            prv -> next = v;
            v -> next = u;
        }
        return head;
    }
};

// { Driver Code Starts.

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
    struct Node *temp;

    if(start != NULL)
    {
        temp = start;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != start);
        printf("\n");
    }
}
/* Driver program to test above functions */
int main()
{
    int t,n,x;
    scanf("%d",&t);
    int arr;
    while(t--) {
        scanf("%d",&n);
        int list_size, i;

        /* start with empty linked list */
        struct Node *start = NULL;
        struct Node *temp,*r;


        /* Create linked list from the array arr[].
        Created linked list will be 1->2->11->56->12 */
        if(n>0) {
            scanf("%d",&arr);

            temp = new Node(arr);
            start=temp;
            r=start;
        }
        for (i = 0; i<n-1; i++)
        {
            scanf("%d",&arr);
            temp = new Node(arr);
            r->next=temp;
            r=r->next;
        }

        if(n>0)
            temp->next=start;

        scanf("%d",&x);
        Solution ob;
        start = ob.sortedInsert(start,x);
        printList(start);
        r=start;
        while(r!=start->next)
        {

            temp=start;
            start=start->next;
            free(temp);
        }
        free(start);
    }
    return 0;
}
// } Driver Code Ends
