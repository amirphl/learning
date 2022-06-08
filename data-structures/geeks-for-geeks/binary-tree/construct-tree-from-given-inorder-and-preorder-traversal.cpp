// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

// { Driver Code Starts
//

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


void printPostOrder(Node *root)
{
    if(root==NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:
    Node* buildTree(int in[],int pre[], int n)
    {
        std::unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
            m[in[i]] = i;
        return buildTreeRecu(in, pre, 0, n - 1, 0, n -1, m);
    }

    // time: O(n), memory: O(h)
    Node* buildTreeRecu(int in[], int pre[], int low, int high, int left, int right, std::unordered_map<int, int> &m) {
        if (low > high)
            return 0;

        Node* node = new Node(pre[left]);

        if (low == high) {
            return node;
        }

        int root_index = m[pre[left]];
        node -> left = buildTreeRecu(in, pre, low, root_index - 1, left + 1, left + root_index - low, m);
        node -> right = buildTreeRecu(in, pre, root_index + 1, high, left + root_index - low + 1, right, m);

        return node;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int inorder[n], preorder[n];
        for(int i=0; i<n; i++)
            cin>> inorder[i];
        for(int i=0; i<n; i++)
            cin>> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout<< endl;
    }
}
// } Driver Code Ends
