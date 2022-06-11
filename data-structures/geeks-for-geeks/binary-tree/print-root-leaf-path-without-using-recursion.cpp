// https://www.geeksforgeeks.org/print-root-leaf-path-without-using-recursion/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector<vector<int>> Paths(Node *root);

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<vector<int>> paths = Paths(root);
        for(int i = 0; i<paths.size(); i++) {
            for(int j = 0; j<paths[i].size(); j++) {
                cout<<paths[i][j]<<" ";
            }
            cout<<"#";
        }
        cout<<"\n";
    }
    return 0;
}


// } Driver Code Ends


/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
// time: O(n*n), memory: O(n)
vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> res;
    unordered_map<Node*, Node*> m;
    stack<Node*> s;
    Node* curr = root;
    while(curr) {
        if (curr -> left == 0 && curr -> right == 0) {
            vector<int> v;
            v.push_back(curr -> data);
            Node* u = curr;
            while(m.find(u) != m.end()) {
                u = m[u];
                v.push_back(u -> data);
            }
            reverse(v.begin(), v.end());
            res.push_back(v);
        }
        if (curr -> right) {
            m[curr -> right] = curr;
            s.push(curr -> right);
        }
        m[curr -> left] = curr;
        curr = curr -> left;
        if (!curr && !s.empty()) {
            curr = s.top();
            s.pop();
        }
    }
    return res;
}
