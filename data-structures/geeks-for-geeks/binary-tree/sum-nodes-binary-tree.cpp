// https://www.geeksforgeeks.org/sum-nodes-binary-tree/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

Node* make_tree()
{
    int n;
    cin>>n;

    Node* head=NULL;
    queue <Node*> q;

    for( ; n>0 ; n-=2 )
    {
        int a,b;
        char c;
        cin>> a >> b >> c;

        if(!head)
        {
            head = new Node(a);
            q.push(head);
        }

        Node* pick = q.front();
        q.pop();

        if(c == 'L')
        {
            pick->left = new Node(b);
            q.push( pick->left );
        }


        cin>> a >> b >> c;

        if(c == 'R')
        {
            pick->right = new Node(b);
            q.push( pick->right );
        }
    }
    return head;
}

long int sumBT(Node* root);


int main()
{
    int t;
    cin>>t;
    while(t--) {

        Node* head = make_tree();

        cout<<sumBT(head)<<endl;
    }
    return 1;
}
// } Driver Code Ends


/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/
// Function should return the sum of all the elements
// of the binary tree
// time: O(n), memory: O(1)
long int sumBT(Node* root)
{
    long int s = 0;
    Node* curr = root;
    while(curr) {
        if (curr -> left) {
            Node* r = curr -> left;
            while(r -> right && r -> right != curr) {
                r = r -> right;
            }
            if (r -> right) {
                r -> right = 0;
                s += curr -> key;
                curr = curr -> right;
            } else {
                r -> right = curr;
                curr = curr -> left;
            }
        } else {
            s += curr -> key;
            curr = curr -> right;
        }
    }
    return s;
}
