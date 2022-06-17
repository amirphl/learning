// https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};
*/

class Solution {
public:
    //Function to merge K sorted linked list.
    // time: O(nklogk), memory: O(k)
    Node * mergeKLists2(Node *arr[], int K)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int i = 0;
        while(i < K) {
            pq.push({arr[i] -> data, i});
            struct Node* t = arr[i] -> next;
            delete(arr[i]);
            arr[i] = t;
            i++;
        }
        struct Node* fake = (struct Node*)malloc(sizeof(struct Node));
        struct Node* prv = fake;
        int c = 0;
        while(!pq.empty()) {
            prv -> next = (struct Node*)malloc(sizeof(struct Node));
            prv -> next -> next = 0;
            prv -> next -> data = pq.top()[0];
            prv = prv -> next;
            int idx = pq.top()[1];
            pq.pop();
            if (arr[idx]) {
                pq.push({arr[idx] -> data, idx});
                // cout << " _" << arr[idx] -> data << "_ ";
                struct Node* t = arr[idx] -> next;
                delete(arr[idx]);
                arr[idx] = t;
            }
            c++;
            if (c == 40) {
                break;
            }
        }
        return fake -> next;
    }

    // time: O(nklogk), memory: O(k)
    Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        int i = 0;
        while(i < K) {
            pq.push({arr[i] -> data, arr[i] -> next});
            i++;
        }
        struct Node* fake = (struct Node*)malloc(sizeof(struct Node));
        struct Node* prv = fake;
        while(!pq.empty()) {
            prv -> next = (struct Node*)malloc(sizeof(struct Node));
            prv -> next -> next = 0;
            prv -> next -> data = pq.top().first;
            prv = prv -> next;
            struct Node* nxt = pq.top().second;
            pq.pop();
            if (nxt) {
                pq.push({nxt -> data, nxt -> next});
            }
        }
        return fake -> next;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        struct Node *arr[N];
        for(int j=0; j<N; j++)
        {
            int n;
            cin>>n;

            int x;
            cin>>x;
            arr[j]=new Node(x);
            Node *curr = arr[j];
            n--;

            for(int i=0; i<n; i++)
            {
                cin>>x;
                Node *temp = new Node(x);
                curr->next =temp;
                curr=temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr,N);
        printList(res);

    }

    return 0;
}
// } Driver Code Ends
