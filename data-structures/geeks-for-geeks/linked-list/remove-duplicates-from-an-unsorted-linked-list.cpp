// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

// other methods:
// two loops: time: O(n*n), memory: O(1)
// sort + traverse: time: O(nlogn), memory: O(1) || O(n)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


 // } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    // time: O(nlogn), memory: O(n)
    Node * removeDuplicates(Node *head) {
        std::set<int> s;
        Node* prev = 0;
        Node* t = head;
        while(head) {
            if (s.find(head -> data) != s.end()) {
                prev -> next = head -> next;
                delete head;
                head = prev -> next;
                continue;
            }
            s.insert(head -> data);
            prev = head;
            head = head -> next;
        }
        return t;
    }
};


// { Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}  // } Driver Code Ends
