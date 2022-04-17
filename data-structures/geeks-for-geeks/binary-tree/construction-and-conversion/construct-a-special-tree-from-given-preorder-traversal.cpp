// https://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
// https://www.geeksforgeeks.org/construct-full-k-ary-tree-preorder-traversal/

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
	
	Node(int x){
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

// time: O(V*V), memory: O(V)
struct Node* constructTreeRec(int pre[], char preLN[], int low, int high) {
    if (low > high) {
        return 0;
    }

    Node* node = new Node(pre[low]);

    if (low == high) {
        return node;
    }

    int s = 2, i = low + 1;

    // TODO use DP
    for (; i <= high && s != 1; i++) {
        if (preLN[i] == 'N') {
            s += 1;
        } else {
            s -= 1;
        }
    }

    node -> left = constructTreeRec(pre, preLN, low + 1, i - 1);
    node -> right = constructTreeRec(pre, preLN, i, high);

    return node;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    return constructTreeRec(pre, preLN, 0, n - 1);
}
