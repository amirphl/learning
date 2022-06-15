// https://practice.geeksforgeeks.org/problems/burning-tree/1/?page=1&difficulty[]=2&category[]=Tree&sortBy=submissions#

// { Driver Code Starts
//Initial Template for C++

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


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    int minTime(Node* root, int target)
    {
        Node* path[10000];
        memset(path, 0, sizeof(path));
        int lvl = 0;
        stack<pair<Node*, int>> s;
        s.push({root, lvl});
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
        if (!u || u -> data != target) {
            return 0;
        }
        int min_time = 0;
        min_time = max(find_max_h(u -> left), min_time);
        min_time = max(find_max_h(u -> right), min_time);
        Node* prv = u;
        d--;
        int i = 1;
        while(d >= 0) {
            if (path[d] -> left == prv) {
                u = path[d] -> right;
            } else {
                u = path[d] -> left;
            }
            int mid = i + find_max_h(u);
            // cout << path[d] -> data << " " << u -> data << " " << mid << " " << min_time << endl;
            min_time = max(min_time, mid);
            i++;
            prv = path[d];
            d--;
        }
        return min_time;
    }

    int find_max_h(Node* u) {
        if (!u) {
            return 0;
        }
        return max(find_max_h(u -> left), find_max_h(u -> right)) + 1;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n";

        cin.ignore();

    }


    return 0;
}
// } Driver Code Ends
