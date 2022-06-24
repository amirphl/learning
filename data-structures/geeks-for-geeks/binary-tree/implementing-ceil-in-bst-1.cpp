// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1/

// { Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define N 1000000

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNewNode(int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *tree, int val) {

    if (tree == NULL) {
        return createNewNode(val);
    }

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

struct Node *convert_str_to_num(char str[]) {
    char *token = strtok(str, " ");

    struct Node *root = NULL;

    char c[2] = {'N'};
    while (token != NULL) {
        if (strcmp(c, token) != 0) {
            int num = atoi(token);
            root = insert(root, num);
        }
        token = strtok(NULL, " ");
    }

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


// } Driver Code Ends
// User function Template for C

// time: O(h) || O(logn), memory: O(1)
int findCeil(struct Node* root, int key) {
    struct Node* curr = root;
    struct Node* prv = 0;
    while(curr) {
        if (curr -> data < key) {
            curr = curr -> right;
        } else if (curr -> data == key) {
            return key;
        } else {
            while(curr -> left && curr -> left -> data > key) {
                curr = curr -> left;
            }
            if (curr -> left) {
                if (curr -> left -> data == key) {
                    return key;
                } else {
                    prv = curr;
                    curr = curr -> left -> right;
                }
            } else {
                return curr -> data;
            }
        }
    }
    if (prv) {
        return prv -> data;
    }
    return -1;
}

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        while ((getchar()) != '\n')
            ;
        char str[N];
        scanf("%[^\n]s", str);

        int x;
        scanf("%d", &x);

        struct Node *root = NULL;

        root = convert_str_to_num(str);

        int ans = findCeil(root, x);

        printf("%d\n", ans);
    }

    return 0;
}
// } Driver Code Ends
