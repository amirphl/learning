// https://www.geeksforgeeks.org/construct-bst-given-level-order-traversal/

// Note: inorder traversal can also be used!

// other method:
// 1) First pick the first element of the array and make it root. 
// 2) Pick the second element, if it’s value is smaller than root node value make it left child, 
// 3) Else make it right child 
// 4) Now recursively call the step (2) and step (3) to make a BST from its level Order Traversal.

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++
// time: O(n^2), memory: O(n) || O(logn) (in case of balanced BST)
Node* constructBstRec(int arr[], int n, int low, int high)
{
    int root_idx = 0;
    for(; root_idx < n; root_idx++) {
        if (low <= arr[root_idx] && arr[root_idx] <= high) {
            break;
        }
    }
    if (root_idx == n) {
        return 0;
    }
    Node* t = new Node(arr[root_idx]);
    t -> left = constructBstRec(arr, n, low, arr[root_idx] - 1);
    t -> right = constructBstRec(arr, n, arr[root_idx] + 1, high);
    return t;
}

//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    return constructBstRec(arr, n, INT_MIN, INT_MAX);
}
