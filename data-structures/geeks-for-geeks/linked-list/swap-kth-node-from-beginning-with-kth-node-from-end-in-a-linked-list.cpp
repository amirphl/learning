// https://www.geeksforgeeks.org/swap-kth-node-from-beginning-with-kth-node-from-end-in-a-linked-list/

// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp) {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--) {
        int num, K, firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++) {
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
// time: O(n), memory: O(1)
Node *swapkthnode(Node* head, int num, int K)
{
    if (head -> next == 0) {
        return head;
    }
    if (K > num) {
        return head;
    }
    if (K == num || K == 1) {
        if (head -> next -> next == 0) {
            head -> next -> next = head;
            Node* h = head -> next;
            head -> next = 0;
            return h;
        }
        Node* u = head;
        while(u -> next -> next) {
            u = u -> next;
        }
        Node* h = head;
        Node* temp = head -> next;
        head = u -> next;
        head -> next = temp;
        u -> next = h;
        h -> next = 0;
        // Node* p = head;
        // while(p) {
        //     cout << p -> data << endl;
        //     p = p -> next;
        // }
        return head;
    }
    if (K > num / 2) {
        K = num - K + 1;
    }
    Node* prv_u = 0;
    Node* prv_v = 0;
    Node* u = head;
    Node* v = head;
    int i = 1;
    while(i <= num - K) {
        if (i < K) {
            prv_u = u;
            u = u -> next;
        }
        prv_v = v;
        v = v -> next;
        i++;
    }
    // cout << u -> data << " " << v -> data << endl;
    if (u == v) {
    } else if (u -> next == v) {
        Node* temp = v -> next;
        prv_u -> next = v;
        v -> next = u;
        u -> next = temp;
    } else {
        Node* temp = v -> next;
        prv_u -> next = v;
        v -> next = u -> next;
        prv_v -> next = u;
        u -> next = temp;
    }
    return head;
}

