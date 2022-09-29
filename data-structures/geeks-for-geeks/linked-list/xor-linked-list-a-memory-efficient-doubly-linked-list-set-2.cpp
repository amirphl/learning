// https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-2/

//{ Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> printList(struct Node *head);

int main() {
    int t;
    cin >> t;
    while (t--) {
        struct Node *head = NULL;
        int n, tmp;
        cin >> n;
        while (n--) {
            cin >> tmp;
            head = insert(head, tmp);
        }
        vector<int> vec = printList(head);
        for (int x : vec) cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = data;
    if (head == 0) {
        new_node -> npx = XOR((uintptr_t) 0, (uintptr_t) 0);
        return new_node;
    }
    struct Node* head_next = XOR((uintptr_t) 0, head -> npx);
    head -> npx = XOR(new_node, head_next);
    new_node -> npx = XOR((uintptr_t) 0, head);
    return new_node;
}

vector<int> printList(struct Node *head) {
    struct Node* prv = (struct Node*) 0;
    vector<int> res;
    while(head) {
        res.push_back(head -> data);
        struct Node* nxt = XOR(prv, head -> npx);
        prv = head;
        head = nxt;
    }
    return res;
}

