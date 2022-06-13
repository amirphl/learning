// https://www.geeksforgeeks.org/tree-isomorphism-problem/

// { Driver Code Starts
#include<bits/stdc++.h>
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

class Solution {
public:
    // Return True if the given trees are isomotphic. Else return False.
    // time: O(n), memory: O(n)
    bool isIsomorphic(Node *root1, Node *root2)
    {
        stack<pair<Node*, Node*>> s;
        s.push({root1, root2});
        while(!s.empty()) {
            Node* u = s.top().first;
            Node* v = s.top().second;
            s.pop();
            // cout << u -> data << " " << v -> data << endl;
            if (u -> data != v -> data) {
                return false;
            }
            if (u -> left && u -> right && v -> left && v -> right) {
                if (u -> left -> data == v -> left -> data) {
                    if (u -> right -> data == v -> right -> data) {
                        if (u -> left -> data == u -> right -> data) {
                            // testcase:
                            // 4 6 6 N 8 5 7 N 7 4 8
                            // 4 6 6 7 5 8 N N N 8 4 7
                            int a = m_xor(u -> left -> left, u -> left -> right);
                            int b = m_xor(v -> left -> left, v -> left -> right);
                            if (a == b) {
                                s.push({u -> left, v -> left});
                                s.push({u -> right, v -> right});
                            } else {
                                s.push({u -> left, v -> right});
                                s.push({u -> right, v -> left});
                            }
                        } else {
                            s.push({u -> left, v -> left});
                            s.push({u -> right, v -> right});
                        }
                    } else {
                        return false;
                    }
                } else if (u -> left -> data == v -> right -> data) {
                    if (u -> right -> data == v -> left -> data) {
                        s.push({u -> left, v -> right});
                        s.push({u -> right, v -> left});
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else if (u -> left && u -> right && (v -> left || v -> right)) {
                return false;
            } else if (u -> left && u -> right) {
                return false;
            } else if ((u -> left || u -> right) && v -> left && v -> right) {
                return false;
            } else if ((u -> left || u -> right) && (v -> left || v -> right)) {
                Node* x = u -> left ? u -> left : u -> right;
                Node* y = v -> left ? v -> left : v -> right;
                if (x -> data != y -> data) {
                    return false;
                } else {
                    s.push({x, y});
                }
            } else if (u -> left || u -> right) {
                return false;
            } else if (v -> left && v -> right) {
                return false;
            } else if (v -> left || v -> right) {
                return false;
            } else {
                // skip
            }
        }
        return true;
    }

    int m_xor(Node* u, Node* v) {
        if (u && v) {
            return u -> data ^ v -> data;
        } else if (u) {
            return u -> data;
        } else if (v) {
            return v -> data;
        } else {
            return INT_MAX;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        Node* root1 = buildTree(s1);
        Node* root2 = buildTree(s2);
        Solution obj;
        if(obj.isIsomorphic(root1,root2))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
// } Driver Code Ends
