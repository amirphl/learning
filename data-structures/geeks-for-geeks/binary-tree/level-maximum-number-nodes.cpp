// https://www.geeksforgeeks.org/level-maximum-number-nodes/

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

int maxNodeLevel(Node *root);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int ans = maxNodeLevel(root);
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
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

// Return the level (0-indexed) with maximum number of nodes.
// time: O(n), memory: O(w)
int maxNodeLevel(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(0);
    int s = 0;
    int prv = 0;
    int res = 0;
    int lvl = 0;
    while(q.size() > 1) {
        Node* u = q.front();
        q.pop();
        if (!u) {
            q.push(0);
            if (s > prv) {
                res = lvl;
                prv = s;
            }
            lvl++;
            s = 0;
            continue;
        }
        s++;
        if (u -> left) {
            q.push(u -> left);
        }
        if (u -> right) {
            q.push(u -> right);
        }
    }
    if (s > prv) {
        res = lvl;
        prv = s;
    }
    return res;
}
