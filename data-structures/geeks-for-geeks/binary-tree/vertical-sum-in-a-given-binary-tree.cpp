// https://www.geeksforgeeks.org/vertical-sum-in-a-given-binary-tree/
// https://www.geeksforgeeks.org/vertical-sum-in-binary-tree-set-space-optimized/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/

class Solution {
public:
    // time: O(nlogn), memory: O(n)
    vector<int> verticalSum2(Node* root) {
        int hd = 0;
        map<int, int> m;
        vector<int> v;
        verticalSumRec(root, hd, m);
        for(auto it = m.begin(); it != m.end(); it++) {
            v.push_back(it -> second);
        }

        return v;
    }

    void verticalSumRec(Node *root, int hd, map<int, int> &m) {
        if (root -> left) {
            verticalSumRec(root -> left, hd - 1, m);
        }
        if (root -> right) {
            verticalSumRec(root -> right, hd + 1, m);
        }
        m[hd] += root -> data;
    }

    // time: O(n), memory: O(n)
    vector<int> verticalSum(Node* root) {
        int min_level = 0;
        vector<int> v;
        unordered_map<int, int> m;
        stack<pair<Node*, int>> s;
        s.push({root, 0});
        while(!s.empty()) {
            Node* u = s.top().first;
            int d = s.top().second;
            s.pop();
            min_level = min(min_level, d);
            m[d] += u -> data;
            if (u -> left) {
                s.push({u -> left, d - 1});
            }
            if (u -> right) {
                s.push({u -> right, d + 1});
            }
        }
        while(m.find(min_level) != m.end()) {
            v.push_back(m[min_level]);
            min_level++;
        }
        return v;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
}  // } Driver Code Ends
