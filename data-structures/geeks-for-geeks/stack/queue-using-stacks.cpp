// https://www.geeksforgeeks.org/queue-using-stacks/
// https://www.geeksforgeeks.org/implement-stack-using-queue/

// Implemented with an explicit Stack and the Stack of the memory.
// We can implement a Stack with two queues.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> s;
public:
    // time: O(n), memory: O(1)
    void enqueue(int x) {
        if (s.empty())
            s.push(x);
        else {
            int t = s.top();
            s.pop();
            enqueue(x);
            s.push(t);
        }
    }

    // time: O(1), memory: O(1)
    int dequeue() {
        int t = s.top();
        s.pop();
        return t;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--) {
            int QueryType=0;
            cin>>QueryType;
            if(QueryType==1)
            {
                int a;
                cin>>a;
                ob.enqueue(a);
            }
            else if(QueryType==2)
            {
                cout<<ob.dequeue()<<" ";

            }
        }
        cout<<endl;
    }
}
// } Driver Code Ends

