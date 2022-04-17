// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

// TODO(amirphl) third approach

// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// time: O(VlogV), memory: O(V)    
Node* buildTreeRecu(int in[], int post[], int low, int high, int left, int right, std::map<int, int> &m) {    
  if (low > high)
      return 0;

  Node* node = new Node(post[right]);

  if (low == high) {
      return node;
  }

  int root_index = m[post[right]];
  node -> left = buildTreeRecu(in, post, low, root_index - 1, left, left + root_index - low - 1, m);
  node -> right = buildTreeRecu(in, post, root_index + 1, high, left + root_index - low, right - 1, m);

  return node;
}


Node* buildTree(int in[],int post[], int n) {
  std::map<int, int> m;
  for(int i = 0; i < n; i++)
      m[in[i]] = i;
  return buildTreeRecu(in, post, 0, n - 1, 0, n -1, m);
}
