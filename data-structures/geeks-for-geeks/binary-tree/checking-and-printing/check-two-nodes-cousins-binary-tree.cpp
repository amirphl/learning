// https://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree/

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

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}// } Driver Code Ends


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

void inorder(Node* root) {
    if (root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
// time: O(V), memory: O(V)
bool isCousins(Node *root, int a, int b)
{
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // return true;
    queue<Node*> q;
    q.push(root);
    q.push(0);

    int find;
    bool start = false;
    Node* parent = 0;

    while(q.size() > 1) {
        Node* u = q.front();
        q.pop();

        if (u == 0) {
            if (start) {
                return false;
            }
            q.push(0);
            continue;
        }

        if (u -> data == find && start && parent -> left != u && parent -> right != u) {
            return true;
        }

        if (u -> data == a && !start) {
            find = b;
            start = true;
        }

        if (u -> data == b && !start) {
            find = a;
            start = true;
        }

        if (u -> left) {
            if ((u -> left -> data == a || u -> left -> data == b) && parent == 0) {
                parent = u;
            }
            q.push(u -> left);
        }
        if (u -> right) {
            if ((u -> right -> data == a || u -> right -> data == b) && parent == 0) {
                parent = u;
            }
            q.push(u -> right);
        }
    }

    return false;
}
