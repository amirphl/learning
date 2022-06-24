// https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1/

// { Driver Code Starts
//Author- SAJAL AGRAWAL
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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

Node *insert(Node *r,int num);
int sumOfLeafNodes(Node *r);
void preOrderDisplay(Node *r);
void inOrderDisplay(Node *r);
void postOrderDisplay(Node *r);
int search(Node *r, int num);

int main(void) {
    int t,n,data;
    scanf("%d",&t);
    while(t--) {
        Node *root=NULL;
        scanf("%d",&n);
        //printf("n=%d\n",n);
        while(n--) {
            scanf("%d",&data);
            //printf("data=%d\n",data);
            root=insert(root,data);
        }
        //inOrderDisplay(root);
        printf("%d\n",sumOfLeafNodes(root));
    }
    return 0;
}

Node *insert(Node *r,int num) {
    if(r==NULL) {
        r = new Node(num);
    } else {
        if(num<r->data) {
            r->left=insert(r->left,num);
        } else {
            r->right=insert(r->right,num);
        }
    }
    return r;
}

void preOrderDisplay(Node *r) {
    if(r!=NULL) {
        printf("%d ",r->data);
        preOrderDisplay(r->left);
        preOrderDisplay(r->right);
    }
}

void inOrderDisplay(Node *r) {
    if(r!=NULL) {
        inOrderDisplay(r->left);
        printf("%d ",r->data);
        inOrderDisplay(r->right);
    }
}

void postOrderDisplay(Node *r) {
    if(r!=NULL) {
        postOrderDisplay(r->left);
        postOrderDisplay(r->right);
        printf("%d ",r->data);
    }
}

int search(Node *r,int num) {
    if(r==NULL)return 0;
    else if(r->data==num)return 0;
    else if(r->data > num)
        search(r->left,num);
    else
        search(r->right,num);
}// } Driver Code Ends


/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */


/*You are required to complete below method */
// time: O(n), memory: O(1)
int sumOfLeafNodes(Node* root) {
    int s = 0;
    Node* curr = root;
    while(curr) {
        if (curr -> left) {
            Node* r = curr -> left;
            while(r -> right && r -> right != curr) {
                r = r -> right;
            }
            if (r -> right) {
                r -> right = 0;
                if (r -> left == 0) {
                    s += r -> data;
                }
                curr = curr -> right;
            } else {
                r -> right = curr;
                curr = curr -> left;
            }
        } else {
            if (curr -> right == 0) {
                s += curr -> data;
            }
            curr = curr -> right;
        }
    }
    return s;
}
