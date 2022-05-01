// https://www.geeksforgeeks.org/clone-binary-tree-random-pointers/

// TODO(amirphl) second approach

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};
int checkcloned(Node* a, Node *b)
{
	if ((a == NULL and b == NULL))
		return 1;

	if (a != NULL && b != NULL)
	{
		int t = (a->data == b->data && checkcloned(a->left, b->left) && checkcloned(a->right, b->right));

		if (a->random != NULL && b->random != NULL)
			return (t && a->random->data == b->random->data);
		if (a->random == b->random)
			return t;

		return 0;
	}

	return 0;

}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

 // } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution{
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
    // time: O(V), memory: O(V)
    Node* cloneTree(Node* tree) {
        unordered_map<Node*, Node*> m;
        Node* new_node = cloneTreeRec(tree, m);
        fixRec(tree, new_node, m);
        return new_node;
    }
    Node* cloneTreeRec(Node* root, unordered_map<Node*, Node*> &m) {
        if(!root) {
            return 0;
        }
        Node* new_node = new Node(root -> data);
        new_node -> left = cloneTreeRec(root -> left, m);
        new_node -> right = cloneTreeRec(root -> right, m);
        m[root] = new_node;
        return new_node;
    }
    void fixRec(Node* old_root, Node* new_root, unordered_map<Node*, Node*> &m) {
        if(!old_root) {
            return;
        }
        new_root -> random = m[old_root -> random];
        fixRec(old_root -> left, new_root -> left, m);
        fixRec(old_root -> right, new_root -> right, m);
    }
};


// { Driver Code Starts.
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }
     Solution obj;
     Node *t = obj.cloneTree(root);
     if(t==root)
        cout<<0<<endl;
     else
     cout<<checkcloned(root,t);
     cout<<"\n";
  }
  return 0;
}

  // } Driver Code Ends
