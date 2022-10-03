// https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
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

// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    //Function to find the height of a binary tree.
    // postorder traversal
    // time: O(n), memory: O(h)
    int height2(struct Node* root) {
        stack<pair<struct Node*, int>> s;
        s.push(pair<struct Node*, int> (root, 1));
        int res = 1;
        while(!s.empty()) {
            pair<struct Node*, int> top = s.top();
            s.pop();
            res = max(res, top.second);
            if (top.first -> right) {
                s.push(pair<struct Node*, int> (top.first -> right, top.second + 1));
            }
            if (top.first -> left) {
                s.push(pair<struct Node*, int> (top.first -> left, top.second + 1));
            }
        }
        return res;
    }
    // level order traversal
    // time: O(n), memory: O(h)
    int height(struct Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(0);
        int res = 0;
        while(q.size() > 1) {
            struct Node* u = q.front();
            q.pop();
            if (u == 0) {
                res++;
                q.push(0);
                continue;
            }
            if(u -> left) {
                q.push(u -> left);
            }
            if(u -> right) {
                q.push(u -> right);
            }
        }
        return res + 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string treeString;
        getline(cin,treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        cout<<ob.height(root)<<endl;
    }
    return 0;
}  // } Driver Code Ends
