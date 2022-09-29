// https://www.geeksforgeeks.org/construct-linked-list-2d-matrix/

//{ Driver Code Starts
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct Node
{
    int data;
    Node* right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};

void display(Node* head)
{
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if(Rp->right)cout << Rp->right->data << " ";
            else cout << "Null ";
            if(Rp->down)cout << Rp->down->data << " ";
            else cout << "Null ";
            Rp = Rp->right;
        }

        Dp = Dp->down;
    }
}
Node* constructLinkedMatrix(int mat[MAX][MAX], int n);

// driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[MAX][MAX];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        Node* head = constructLinkedMatrix(mat, n);
        if(!head)cout<<"-1";
        else display(head);
        cout<<"\n";
    }
    return 0;
}


// } Driver Code Ends


/*structure of the node of the linked list is as

struct Node
{
	int data;
	Node* right, *down;

	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};
*/
// n is the size of the matrix
// function must return the pointer to the first element
// of the in linked list i.e. that should be the element at arr[0][0]
// time: O(n*n), memory: O(1)
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head -> data = mat[0][0];
    int i = 1;
    struct Node* u = head;
    while(i < n) {
        u -> right = (struct Node*)malloc(sizeof(struct Node));
        u -> right -> data = mat[0][i];
        u = u -> right;
        i++;
    }
    i = 1;
    u = head;
    while(i < n) {
        u -> down = (struct Node*)malloc(sizeof(struct Node));
        u -> down -> data = mat[i][0];
        u = u -> down;
        i++;
    }
    i = 1;
    u = head -> down;
    while(i < n) {
        struct Node* v = u;
        int j = 1;
        while(j < n) {
            v -> right = (struct Node*)malloc(sizeof(struct Node));
            v -> right -> data = mat[i][j];
            v = v -> right;
            j++;
        }
        u = u -> down;
        i++;
    }
    i = 0;
    u = head;
    while(i < n - 1) {
        struct Node* v = u -> down;
        struct Node* w = u -> right;
        struct Node* z = v -> right;
        while(w && z) {
            w -> down = z;
            w = w -> right;
            z = z -> right;
        }
        u = v;
        i++;
    }

    return head;
}

