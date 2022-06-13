// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/

// { Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    // https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/
    // time: O(nlogn), memory: O(n)
    vector<int> KDistanceNodes(Node* root, int target, int k)
    {
        vector<int> v;
        vector<Node*> path(1000, NULL);
        stack<pair<Node*, int>> s;
        s.push({root, 0});
        Node* u = 0;
        int d;

        while(!s.empty()) {
            u = s.top().first;
            d = s.top().second;
            s.pop();
            path[d] = u;
            if (u -> data == target) {
                break;
            }
            if (u -> left) {
                s.push({u -> left, d + 1});
            }
            if (u -> right) {
                s.push({u -> right, d + 1});
            }
        }

        if (u -> data != target) {
            return v;
        }
        if (k == 0) {
            v.push_back(target);
            return v;
        }

        vector<int> temp;
        if (u -> left) {
            find_at(u -> left, k - 1, temp);
            v.insert(v.end(), temp.begin(), temp.end());
            temp.clear();
        }
        if (u -> right) {
            find_at(u -> right, k - 1, temp);
            v.insert(v.end(), temp.begin(), temp.end());
            temp.clear();
        }
        Node* prv = u;
        d--;
        k--;
        while(d >= 0) {
            u = path[d];
            if (k == 0) {
                v.push_back(u -> data);
                break;
            }
            if (u -> left == prv) {
                find_at(u -> right, k - 1, temp);
                v.insert(v.end(), temp.begin(), temp.end());
                temp.clear();
            } else {
                find_at(u -> left, k - 1, temp);
                v.insert(v.end(), temp.begin(), temp.end());
                temp.clear();
            }
            prv = u;
            d--;
            k--;
        }
        sort(v.begin(), v.end());
        return v;
    }
    void find_at(Node* u, int k, vector<int>& v) {
        if (!u || k < 0) {
            return;
        }
        if (k == 0) {
            v.push_back(u -> data);
            return;
        }
        find_at(u -> left, k - 1, v);
        find_at(u -> right, k - 1, v);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();

    Solution x = Solution();

    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);

        int target, k;
        cin>> target >> k;
        getchar();

        vector <int> res = x.KDistanceNodes(head, target, k);

        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
