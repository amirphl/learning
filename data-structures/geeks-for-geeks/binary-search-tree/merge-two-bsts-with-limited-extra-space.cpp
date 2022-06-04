// https://www.geeksforgeeks.org/merge-two-bsts-with-limited-extra-space/

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



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    //Function to return a list of integers denoting the node
    //values of both the BST in a sorted order.
    // time: O(n + m), memory: O(1)
    vector<int> merge(Node* u, Node* v)
    {
        Node* x = forward_inorder(u);
        Node* y = forward_inorder(v);
        vector<int> res;
        while(x || y) {
            if (x && y && x -> data < y -> data) {
                res.push_back(x -> data);
                x = forward_inorder(u);
            } else if (x && y && x -> data >= y -> data) {
                res.push_back(y -> data);
                y = forward_inorder(v);
            } else if (x) {
                res.push_back(x -> data);
                x = forward_inorder(u);
            } else if (y) {
                res.push_back(y -> data);
                y = forward_inorder(v);
            }
        }
        return res;
    }
    Node* forward_inorder(Node*& curr) {
        Node* res = 0;
        while(curr) {
            if (curr -> left) {
                Node* r = curr -> left;
                while(r -> right && r -> right != curr) {
                    r = r -> right;
                }
                if (r -> right) {
                    r -> right = 0;
                    res = curr;
                    curr = curr -> right;
                    return res;
                } else {
                    r -> right = curr;
                    curr = curr -> left;
                }
            } else {
                res = curr;
                curr = curr -> right;
                return res;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for(int i=0; i<vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        ///cout<<"~"<<endl;
    }
    return 0;
}  // } Driver Code Ends
