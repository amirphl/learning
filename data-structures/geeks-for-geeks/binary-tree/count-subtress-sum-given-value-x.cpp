// https://www.geeksforgeeks.org/count-subtress-sum-given-value-x/

// { Driver Code Starts
//Initial Template for C++
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

// Your are required to complete this function
int countSubtreesWithSumX(Node* root, int x);

int main()
{
    int t;
    cin>>t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        int x;
        cin>>x;
        getchar();
        cout << countSubtreesWithSumX(root, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/

// This doesn't work.
int countSubtreesWithSumXStartFromHere_2(Node* root, int X)
{
    int sum = 0;

    // This part is intersting: root -> left == 0 && root -> right == 0
    if (root -> data == X && root -> left == 0 && root -> right == 0) {
        sum++;
    }

    if (root -> left) {
        sum += countSubtreesWithSumXStartFromHere_2(root -> left, X - root -> data);
    }
    if (root -> right) {
        sum += countSubtreesWithSumXStartFromHere_2(root -> right, X - root -> data);
    }

    if (root -> left && root -> right) {
        // This section is a wrong logic
        int left = countSubtreesWithSumXStartFromHere_2(root -> left, X - (root -> data) - (root -> right -> data));
        int right = countSubtreesWithSumXStartFromHere_2(root -> right, X - (root -> data) - (root -> left -> data));
        sum += left * right;
        // if (root -> left && root -> left -> data == -1) {
        //     cout << root -> data << " " << left << " " << right << " " << X << endl;
        // }
    }

    return sum;
}

void countSubtreesWithSumXStartFromHere(Node* root, map<Node*, vector<int>> &m)
{
    if(m.find(root) == m.end()) {
        vector<int> v;
        v.push_back(0);

        if (root) {
            countSubtreesWithSumXStartFromHere(root -> left, m);
            countSubtreesWithSumXStartFromHere(root -> right, m);

            int skip_first = root -> left || root -> right;

            // This section is very interesting for input:
            // -2 -2 4 -1 3 N -5 9 -2 5 5 N 5 -4
            // 5
            // because -2 -1 3 -2 5 5 is not a subtree!!!
            for(auto it = m[root -> left].begin(); it != m[root -> left].end(); it++) {
                for(auto it2 = m[root -> right].begin(); it2 != m[root -> right].end(); it2++) {
                    if (skip_first) {
                        skip_first = 0;
                        continue;
                    }
                    // if (*it + *it2 + root -> data == 3) {
                    //     cout << " ___ " << *it << " " << root -> data << " " << *it2 << endl;
                    // }

                    v.push_back(*it + *it2 + root -> data);
                }
            }
        }

        m[root] = v;
    }
}

// time: O(V*V*V), memory: O(V*V)
int countSubtreesWithSumXRec(Node* root, int X, map<Node*, vector<int>> &m)
{
    int sum = 0;

    if (root -> left) {
        sum += countSubtreesWithSumXRec(root -> left, X, m);
    }
    if (root -> right) {
        sum += countSubtreesWithSumXRec(root -> right, X, m);
    }

    countSubtreesWithSumXStartFromHere(root, m);

    int start = 1;

    for(auto it = m[root].begin(); it != m[root].end(); it++) {
        if (start) {
            start = 0;
            continue;
        }
        if (*it == X) {
            sum++;
        }
    }

    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
    map<Node*, vector<int>> m;
    int res = countSubtreesWithSumXRec(root, X, m);

    // for(auto it = m.begin(); it != m.end(); it++) {
    //     if (it -> first) {
    //         cout << it -> first -> data << " : ";
    //     } else {
    //         cout << it -> first << " : ";
    //     }

    //     for (auto it2 = (it -> second).begin(); it2 != (it -> second).end(); it2++) {
    //         cout << *it2 << " ";
    //     }

    //     cout << endl;
    // }

    return res;
}
