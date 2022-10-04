// https://www.geeksforgeeks.org/print-binary-tree-vertical-order/
// https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
// https://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/

// another approach: (horizontal distance) (30 bits) + (vertical distance) (30 bits) : time O(VlogV) || O(V), memory: O(V)
// another approach: queue + unordered_mnap : time: O(V), memory: O(V)

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root) {
        map<int, multimap<int, int>> m;
        vector<int> res;
        verticalOrderRec(root, 0, 0, m);
        int c = 1;

        for (auto it = m.begin(); it != m.end(); it++, c++) {
            for (auto it2 = (it -> second).begin(); it2 != (it -> second).end(); it2++) {
                // if (3 < c < 5) {
                //     cout << it2 -> second << " ";
                // }

                res.push_back(it2 -> second);
            }

            // if (3 < c < 5) {
            //     cout << endl;
            // }
        }

        return res;
    }

    // time: O(VlogV), memory: O(V)
    void verticalOrderRec(Node* root, int d, int level, map<int, multimap<int, int>> &m) {
        if (!root) {
            return;
        }

        if (m.find(d) == m.end()) {
            m[d] = multimap<int, int>();
        }

        m[d].insert(pair<int, int> (level, root -> data));
        verticalOrderRec(root -> left, d - 1, level + 1, m);
        verticalOrderRec(root -> right, d + 1, level + 1, m);
    }
};



// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
        Node* root = buildTree(s);

        vector <int> res = obj.verticalOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
