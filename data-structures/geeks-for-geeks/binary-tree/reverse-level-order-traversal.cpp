// https://www.geeksforgeeks.org/reverse-level-order-traversal/

// other approaches:
// 1- Using Queue and Stack

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

vector<int> reverseLevelOrder(Node* root);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}// } Driver Code Ends


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// time: O(n), memory: O(n)
vector<int> reverseLevelOrder(Node *root)
{
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    std::vector<Node*> vec;

    while(q.size() > 1) {
        Node* front = q.front();
        q.pop();
        vec.push_back(front);

        if (front) {
            if (front -> left)
                q.push(front -> left);
            if (front -> right)
                q.push(front -> right);
        } else {
            q.push(NULL);
        }
    }

    std::vector<int> vvv;

    for(int i = vec.size() - 1; i >= 0; i--) {
        if (i == 0 || !vec[i]) {
            if (i == 0)
                i--;
            int j = i + 1;
            while(j < vec.size() && vec[j]) {
                vvv.push_back(vec[j] -> data);
                j++;
            }
        }
    }

    return vvv;
}

// time: O(n), memory: O(n)
vector<int> reverseLevelOrder2(Node *root)
{
    queue<Node*> q;
    q.push(root);
    vector<int> vec;
    while(!q.empty()) {
        Node* u = q.front();
        q.pop();
        vec.push_back(u -> data);
        if (u -> right) {
            q.push(u -> right);
        }
        if (u -> left) {
            q.push(u -> left);
        }
    }
    reverse(vec.begin(), vec.end());
    return vec;
}
