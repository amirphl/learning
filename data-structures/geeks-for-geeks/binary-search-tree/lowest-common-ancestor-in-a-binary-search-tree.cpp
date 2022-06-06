// https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
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

Node* LCA(Node * root, int l, int h);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l, h;
        getline(cin,s);
        scanf("%d ",&l);
        scanf("%d ",&h);
        Node* root = buildTree(s);
        cout<<LCA(root,  l,  h)->data<<endl;
    }
    return 1;
}// } Driver Code Ends




// Function to find the lowest common ancestor in a BST.
// time: O(n) || O(logn) (in case of balanced BST)
// memory: O(1)
Node* LCA(Node *root, int n1, int n2)
{
    Node* u = root;
    while(u) {
        if (n1 < u -> data && n2 < u -> data) {
            u = u -> left;
        } else if (n1 > u -> data && n2 > u -> data) {
            u = u -> right;
        } else {
            return u;
        }
    }
    return 0;
}
