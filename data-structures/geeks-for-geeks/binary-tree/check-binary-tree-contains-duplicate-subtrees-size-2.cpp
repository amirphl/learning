// https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

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

class Solution {
public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        unordered_set<vector<int>, hashFunction> seri;
        vector<int> pre;
        vector<int> in;
        bool found = supSub(root, seri, pre, in);
        // for(auto& it: seri) {
        //     for(auto& it2: it) {
        //         cout << it2 << " ";
        //     }
        //     cout << endl;
        // }
        return found;
    }

    // time: O(nlogh), memory: O(n*n)
    bool supSub(Node* root, unordered_set<vector<int>, hashFunction>& seri, vector<int>& pre, vector<int>& in) {
        if (!root) {
            pre.push_back(-2);
            in.push_back(-2);
            return false;
        }
        vector<int> left_pre;
        vector<int> left_in;
        bool found = supSub(root -> left, seri, left_pre, left_in);
        if (found) {
            return true;
        }
        vector<int> right_pre;
        vector<int> right_in;
        found = supSub(root -> right, seri, right_pre, right_in);
        if (found) {
            return true;
        }
        pre.push_back(root -> data);
        pre.insert(pre.end(), left_pre.begin(), left_pre.end());
        pre.insert(pre.end(), right_pre.begin(), right_pre.end());
        in.insert(in.end(), left_in.begin(), left_in.end());
        in.push_back(root -> data);
        in.insert(in.end(), right_in.begin(), right_in.end());
        vector<int> x;
        x.insert(x.end(), pre.begin(), pre.end());
        x.push_back(-1);
        x.insert(x.end(), in.begin(), in.end());
        if (x.size() > 7 && seri.find(x) != seri.end()) {
            return true;
        }
        seri.insert(x);
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    //cout << t << "\n";
    while (t--)
    {
        string treeString;
        getline(cin >> ws, treeString);
        struct Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.dupSub(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends
