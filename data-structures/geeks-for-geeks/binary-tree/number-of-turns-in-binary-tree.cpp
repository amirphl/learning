// https://practice.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1/?page=1&difficulty[]=2&category[]=Tree&sortBy=submissions

// { Driver Code Starts
//Initial template for C++

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

    // Creating vector of strings from input string after spliting by space
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


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution {
public:
    // function should return the number of turns required to go from first node to second node
    // time: O(n), memory: O(n)
    int NumberOFTurns(struct Node* root, int first, int second)
    {
        if (first == second) {
            return 0;
        }

        Node** path_1 = new Node*[1000];
        Node** path_2 = new Node*[1000];
        memset(path_1, 0, sizeof(path_1));
        memset(path_2, 0, sizeof(path_2));
        int d, d1 = -1, d2 = -1;
        bool set_d1 = true, set_d2 = true;
        stack<pair<Node*, int>> s;
        s.push({root, 0});
        while(!s.empty() && (set_d1 || set_d2)) {
            Node* u = s.top().first;
            d = s.top().second;
            s.pop();
            if (set_d1) {
                path_1[d] = u;
                if (u -> data == first) {
                    set_d1 = false;
                    d1 = d;
                }
            }
            if (set_d2) {
                path_2[d] = u;
                if (u -> data == second) {
                    set_d2 = false;
                    d2 = d;
                }
            }
            if (u -> left) {
                s.push({u -> left, d + 1});
            }
            if (u -> right) {
                s.push({u -> right, d + 1});
            }
        }

        if (d1 == -1 || d2 == -1) {
            return 0;
        }
        // /This part is very important!
        if (d2 > d1) {
            Node** p = path_1;
            path_1 = path_2;
            path_2 = p;
            int temp = d1;
            d1 = d2;
            d2 = temp;
        }

        int i = 0;
        while(i <= min(d1, d2) && path_1[i] == path_2[i]) {
            i++;
        }
        i--;

        char prv;
        if (path_1[d1 - 1] -> left == path_1[d1]) {
            prv = '/';
        } else {
            prv = '\\';
        }
        int c = 0, j = d1 - 2;

        while(i <= j) {
            if (path_1[j] -> left == path_1[j + 1]) {
                if (prv == '\\') {
                    c++;
                    prv = '/';
                }
            } else {
                if (prv == '/') {
                    c++;
                    prv = '\\';
                }
            }
            j--;
        }
        j = i + 1;
        while(j <= d2) {
            if (path_2[j - 1] -> left == path_2[j]) {
                if (prv == '\\') {
                    c++;
                    prv = '/';
                }
            } else {
                if (prv == '/') {
                    c++;
                    prv = '\\';
                }
            }
            j++;
        }
        delete(path_1);
        delete(path_2);
        return c;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
// } Driver Code Ends
