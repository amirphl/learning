// https://www.geeksforgeeks.org/check-whether-bst-contains-dead-end-not/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
               getCountOfNode(root->right, l, h);

    else if (root->data < l)
        return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
        //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0; i<N; i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }


        cout<<isDeadEnd(root);
        cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
// time: O(n), memory: O(h)
bool isDeadEnd(Node *root)
{
    stack<Node*> s;
    stack<int> mini;
    stack<int> maxi;
    s.push(root);
    mini.push(0);
    maxi.push(INT_MAX);
    while(!s.empty()) {
        Node* u = s.top();
        s.pop();
        int lower = mini.top();
        mini.pop();
        int upper = maxi.top();
        maxi.pop();
        if (upper - lower == 2) {
            return true;
        }
        // cout << u -> data << " " << lower << " " << upper << endl;
        if (u -> right) {
            s.push(u -> right);
            mini.push(u -> data);
            maxi.push(upper);
        }
        if (u -> left) {
            s.push(u -> left);
            mini.push(lower);
            maxi.push(u -> data);
        }
    }
    // cout << endl;
    return false;
}
