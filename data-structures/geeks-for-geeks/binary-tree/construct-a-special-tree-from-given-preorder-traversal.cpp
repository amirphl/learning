// https://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/

// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder (struct Node* node)
{
    if (node == NULL)return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/

// time: O(n), memory: O(n)
struct Node *constructTree(int n, int pre[], char preLN[])
{
    stack<struct Node*> s;
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root -> left = 0;
    root -> right = 0;
    struct Node* u = root;
    s.push(u);
    int i = 0;
    while(i < n && !s.empty()) {
        u = s.top();
        s.pop();
        u -> data = pre[i];
        if (preLN[i] == 'N') {
            struct Node* left = (struct Node*)malloc(sizeof(struct Node));
            struct Node* right = (struct Node*)malloc(sizeof(struct Node));
            left -> left = 0;
            left -> right = 0;
            right -> left = 0;
            right -> right = 0;
            s.push(right);
            s.push(left);
            u -> left = left;
            u -> right = right;
        }
        i++;
    }
    return root;
}
