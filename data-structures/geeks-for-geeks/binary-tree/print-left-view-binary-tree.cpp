// https://www.geeksforgeeks.org/print-left-view-binary-tree/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView2(Node *root)
{
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    q.push(0);
    bool first = true;
    while(q.size() > 1) {
        Node* u = q.front();
        q.pop();
        if (!u) {
            q.push(0);
            first = true;
            continue;
        }
        if (first) {
            v.push_back(u -> data);
            first = false;
        }
        if (u -> left) {
            q.push(u -> left);
        }
        if (u -> right) {
            q.push(u -> right);
        }
    }
    return v;
}

void fill(Node* root, int h, int w, map<int, vector<int>> &m) {
    if (!root) {
        return;
    }
    // cout << root -> data << " " << h << " " << w << endl;
    // if (m.find(h) != m.end()) {
    //     if (m[h][0] < w) {
    //         m[h] = {w, root -> data};
    //     }
    // } else {
    m[h] = {w, root -> data};
    // }
    fill(root -> right, h + 1, w - 1, m);
    fill(root -> left, h + 1, w + 1, m);
}

// time: O(n), memory: O(h)
vector<int> leftView(Node *root)
{
    map<int, vector<int>> m;
    fill(root, 0, 0, m);
    vector<int> v(m.size());
    int i = 0;
    for(auto& it : m) {
        v[i] = (it.second)[1];
        i++;
    }
    return v;
}
