// https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


// } Driver Code Ends
//User function Template for C

//Function to insert a node at the begin of the linked list.
struct Node *insertAtBegining(struct Node *head, int x) {
    struct Node* h = (struct Node*)malloc(sizeof(struct Node));
    h -> data = x;
    h -> next = head;
    return h;
}


//Function to insert a node at the end of the linked list.
struct Node *insertAtEnd(struct Node *head, int x)  {
    struct Node* u = head;
    struct Node* h = (struct Node*)malloc(sizeof(struct Node));
    h -> data = x;
    if (!u) {
        return h;
    }
    while(u -> next) {
        u = u -> next;
    }
    u -> next = h;
    return head;
}


// { Driver Code Starts.

void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            scanf("%d", &data);
            scanf("%d", &indicator);
            if (indicator)
                head = insertAtEnd(head, data);
            else
                head = insertAtBegining(head, data);
        }
        printList(head);
    }
    return 0;
}  // } Driver Code Ends
