// https://www.geeksforgeeks.org/find-duplicate-subtrees/

// { Driver Code Starts
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

void preorder(Node* root) {
    if(!root) {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


// } Driver Code Ends
//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/

struct hashFunction
{
    size_t operator()(const vector<int>
                      &myVector) const
    {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector)
        {
            answer ^= hasher(i) + 0x9e3779b9 +
                      (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};

// time: O(n*n), memory: O(n*n)
void rec(Node* root, vector<int>& pre, unordered_map<vector<int>, int, hashFunction>& s, vector<Node*>& res) {
    if (!root) {
        pre.push_back(INT_MAX);
        return;
    }

    vector<int> pre_left, pre_right;
    rec(root -> left, pre_left, s, res);
    rec(root -> right, pre_right, s, res);
    pre.push_back(root -> data);
    pre.insert(pre.begin(), pre_left.begin(), pre_left.end());
    pre.insert(pre.begin(), pre_right.begin(), pre_right.end());
    if (s.find(pre) != s.end()) {
        if (s[pre] == 1) {
            res.push_back(root);
        }
    }
    s[pre]++;
}

// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree
vector<Node*> printAllDups(Node* root)
{
    vector<int> pre;
    unordered_map<vector<int>, int, hashFunction> s;
    vector<Node*> res;
    rec(root, pre, s, res);
    return res;
}

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
        vector<Node*> res = printAllDups(root);

        for(int i=0; i<res.size(); i++) {
            preorder(res[i]);
            cout<<endl;
        }
    }
    return 0;
}


// } Driver Code Ends
