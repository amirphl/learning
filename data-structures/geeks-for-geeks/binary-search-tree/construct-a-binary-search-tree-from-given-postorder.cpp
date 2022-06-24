// https://www.geeksforgeeks.org/construct-a-binary-search-tree-from-given-postorder/

// { Driver Code Starts
#include<bits/stdc++.h>
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);


}

int main ()
{
    int t,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int post[n];
        for(int i=0; i<n; i++)
            scanf("%d",&post[i]);

        Node* root = constructTree(post, n);

        printInorder(root);
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* constructTreeRec(int post[], int& i, int low, int high) {
    // cout << post[i] << " " << low << " " << high << endl;
    if (low < post[i] && post[i] < high && -1 < i) {
        Node* u = new Node(post[i]);
        int x = post[i];
        i--;
        u -> right = constructTreeRec(post, i, x, high);
        u -> left = constructTreeRec(post, i, low, x);
        return u;
    }
    return 0;
}

// time: O(n), memory: O(h)
Node *constructTree(int post[], int n) {
    int i = n - 1;
    return constructTreeRec(post, i, INT_MIN, INT_MAX);
}

