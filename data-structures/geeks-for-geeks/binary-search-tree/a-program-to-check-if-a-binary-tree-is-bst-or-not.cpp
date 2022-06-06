// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

// method 4: Do inorder then check whether the result is sorted or not. time: O(n), memory: O(1) (in case of iterative approach)
// No need to use an extra array. Simply use a pointer to the previously visited element.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends
class Solution
{
public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root)
    {
        int min_, max_;
        return isBSTRec(root, min_, max_);
    }
    // time: O(n) || O(logn) (in case of balanced BST)
    // memory: O(n) || O(logn) (in case of balanced BST)
    bool isBSTRec(Node* root, int& min_, int& max_)
    {
        if (!root) {
            min_ = INT_MAX;
            max_ = INT_MIN;
            return true;
        }
        bool bst;
        int min_elem_left, max_elem_left;
        int min_elem_right, max_elem_right;
        bst = isBSTRec(root -> left, min_elem_left, max_elem_left);
        if (!bst || max_elem_left > root -> data) {
            return false;
        }
        bst = isBSTRec(root -> right, min_elem_right, max_elem_right);
        if (!bst || min_elem_right < root -> data) {
            return false;
        }
        min_ = min({min_elem_left, min_elem_right, root -> data});
        max_ = max({max_elem_left, max_elem_right, root -> data});
        return true;
    }
};




// { Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        if(ob.isBST(root))
            cout<<"1\n";

        else
            cout<<"0\n";
    }
    return 0;
}


//Position this line where user code will be pasted
// } Driver Code Ends
