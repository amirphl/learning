// https://www.geeksforgeeks.org/modify-contents-linked-list/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

struct Node* modifyTheList(struct Node *head);

void push(struct Node **head_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node *head)
{
    if (!head)
        return;
    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        struct Node *head = NULL;
        while(n--) {
            int a;
            cin>>a;
            push(&head, a);
        }
        head = modifyTheList(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


/*Complete the function below
Node is as follows:
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

// time: O(n), memory: O(1)
struct Node* modifyTheList(struct Node *head)
{
    struct Node* v = 0;
    struct Node* u = head;
    while(u) {
        u = u -> next;
        if (u) {
            u = u -> next;
        }
        if (!v) {
            v = head;
        } else {
            v = v -> next;
        }
    }
    // cout << v -> data << " _ " << endl;
    struct Node* backup = v;
    Node* w = v -> next;
    v -> next = 0;
    v = w;
    struct Node* prv = 0;
    while(v) {
        w = v -> next;
        v -> next = prv;
        prv = v;
        v = w;
    }
    v = prv;
    u = head;
    while(u && v) {
        u -> data -= v -> data;
        u = u -> next;
        v = v -> next;
    }
    v = prv;
    prv = 0;
    while(v) {
        w = v -> next;
        v -> next = prv;
        prv = v;
        v = w;
    }
    v = prv;
    backup -> next = v;
    return head;
}
