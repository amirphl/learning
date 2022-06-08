// https://www.geeksforgeeks.org/construct-tree-inorder-level-order-traversals-set-2/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);

}
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int in[n],level[n];
        for(int i=0; i<n; i++) {
            cin>>in[i];
        }
        for(int i=0; i<n; i++) {
            cin>>level[i];
        }
        Node *root=NULL;
        root = buildTree(in, level, 0, n - 1,n);
        printPreorder(root);
        cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

// time: O(n*n), memory: O(n)
Node* buildTreeRec(int in[], int lvl[], int low, int high, int left, int right, unordered_map<int, int>& m) {
    if (low > high) {
        return 0;
    }
    Node* node = new Node(lvl[left]);
    if (low == high) {
        return node;
    }
    int root_index = m[lvl[left]];
    int s1 = root_index - low;
    int s2 = high - root_index;
    int a[s1];
    int b[s2];
    int i = 0, j = 0;
    for(int k = left + 1; k <= right;  k++) {
        if (m[lvl[k]] < root_index) {
            a[i] = lvl[k];
            i++;
        } else {
            b[j] = lvl[k];
            j++;
        }
    }
    node -> left = buildTreeRec(in, a, low, root_index - 1, 0, s1 - 1, m);
    node -> right = buildTreeRec(in, b, root_index + 1, high, 0, s2 - 1, m);
    return node;
}

Node* buildTree(int in[], int lvl[], int iStart, int iEnd,int n)
{
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
        m[in[i]] = i;
    return buildTreeRec(in, lvl, 0, n - 1, 0, n - 1, m);
}
