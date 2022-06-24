// https://practice.geeksforgeeks.org/problems/0f02fb492c69c094d94e806cba6ff8d8cd04d630/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

Node* path[100000];

class Solution {

public:
    // time: O(n), memory: O(n)
    int sum_at_distK(Node* root, int target, int k)
    {
        stack<pair<Node*, int>> s;
        s.push({root, 0});
        Node* u;
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
        int sum = u -> data;
        add(u -> left, k, sum);
        add(u -> right, k, sum);
        d--;

        while(-1 < d && 0 < k) {
            u = path[d];
            sum += u -> data;
            if (u -> right == path[d + 1]) {
                add(u -> left, k - 1, sum);
            }
            if (u -> left == path[d + 1]) {
                add(u -> right, k - 1, sum);
            }
            d--;
            k--;
        }
        return sum;
    }

    void add(Node* u, int k, int& sum) {
        if (k < 1 || u == 0) {
            return;
        }
        sum += u -> data;
        add(u -> left, k - 1, sum);
        add(u -> right, k - 1, sum);
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();

    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
    return 0;
}

// } Driver Code Ends
