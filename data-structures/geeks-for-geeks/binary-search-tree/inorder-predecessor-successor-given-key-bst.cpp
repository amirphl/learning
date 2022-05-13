// https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/

// { Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
// time: O(n), memory: O(1)
void findPreSuc(Node* curr, Node*& pre, Node*& suc, int key)
{
    pre = 0;
    suc = 0;
    bool first = 1;
    while (curr) {
        // cout << curr -> key << " + ";
        if (curr -> left) {
            Node* u = curr -> left;
            while (u -> right && u -> right != curr) {
                u = u -> right;
            }
            if (u -> right == curr) {
                u -> right = 0;
                if (curr -> key < key) {
                    pre = curr;
                }
                if (curr -> key > key && first) {
                    suc = curr;
                    first = 0;
                }
                // cout << curr -> key << " _ ";
                curr = curr -> right;
            } else {
                u -> right = curr;
                curr = curr -> left;
            }
        } else if (curr -> right) {
            if (curr -> key < key) {
                pre = curr;
            }
            if (curr -> key > key && first) {
                suc = curr;
                first = 0;
            }
            // cout << curr -> key << " _ ";
            curr = curr -> right;
        } else {
            if (curr -> key < key) {
                pre = curr;
            }
            if (curr -> key > key && first) {
                suc = curr;
                first = 0;
            }
            // cout << curr -> key << " _ ";
            curr = 0;
        }
    }
}
