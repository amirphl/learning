// https://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/
// https://www.geeksforgeeks.org/construct-complete-binary-tree-given-array/

// { Driver Code Starts
#include <bits/stdc++.h>

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

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL) return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left) q.push(j->left);
        if (j->right) q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) cout << "-1\n";
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}
// } Driver Code Ends


/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

//Function to make binary tree from linked list.
// time: O(n), memory: O(n)
void convert(Node *head, TreeNode *&root) {
    int n = 0;
    Node* te = head;
    while(te) {
        n++;
        te = te -> next;
    }

    std::queue<TreeNode*> q;
    TreeNode* child = (TreeNode*)malloc(sizeof(TreeNode));
    child -> data = INT_MIN;
    child -> left = NULL;
    child -> right = NULL;
    n--;
    q.push(child);
    TreeNode* t = child;

    while(!q.empty()) {
        TreeNode* r = q.front();
        q.pop();
        r -> data = head -> data;
        head = head -> next;
        if (n > 0) {
            child = (TreeNode*)malloc(sizeof(TreeNode));
            child -> data = INT_MIN;
            child -> left = NULL;
            child -> right = NULL;
            r -> left = child;
            q.push(child);
            n--;
        }
        if (n > 0) {
            child = (TreeNode*)malloc(sizeof(TreeNode));
            child -> data = INT_MIN;
            child -> left = NULL;
            child -> right = NULL;
            r -> right = child;
            q.push(child);
            n--;
        }
    }

    root = t;
}
