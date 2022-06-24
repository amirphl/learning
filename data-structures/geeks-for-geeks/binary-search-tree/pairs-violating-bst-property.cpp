// https://practice.geeksforgeeks.org/problems/pairs-violating-bst-property/1/

// { Driver Code Starts
//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int indx,ans;

struct Node {
    int data;
    Node *left,*right;

    Node(int d) {
        data=d;
        left=right=NULL;
    }
};
int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        indx=0;
        ans=0;
        Node *root=NULL;
        for(int j=0; j<n; j++) {
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL) {
                root=new Node(a);
                switch(ch) {
                case 'L':
                    root->left=new Node(b);
                    break;
                case 'R':
                    root->right=new Node(b);
                    break;
                }
            } else {
                insert(root,a,b,ch);
            }
        }
        cout<<pairsViolatingBST(root,n)<<"\n";
    }

    return 0;
}

void insert(Node *root,int a,int b,char ch) {
    if(root==NULL)return;
    if(root->data==a) {
        switch(ch) {
        case 'L':
            root->left=new Node(b);
            break;
        case 'R':
            root->right=new Node(b);
            break;
        }
    } else {
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}
// } Driver Code Ends


/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
}; */


/*You are required to complete below method */
// time: O(nlogn), memory: O(n)
int pairsViolatingBST(Node *root, int n) {
    set<int> s;
    int c = 0;
    Node* curr = root;

    while(curr) {
        if (curr -> right) {
            Node* l = curr -> right;
            while(l -> left && l -> left != curr) {
                l = l -> left;
            }
            if (l -> left) {
                l -> left = 0;
                s.insert(curr -> data);
                c += distance(s.begin(), s.lower_bound(curr -> data));
                curr = curr -> left;
            } else {
                l -> left = curr;
                curr = curr -> right;
            }
        } else {
            s.insert(curr -> data);
            c += distance(s.begin(), s.lower_bound(curr -> data));
            curr = curr -> left;
        }
    }

    return c;
}

