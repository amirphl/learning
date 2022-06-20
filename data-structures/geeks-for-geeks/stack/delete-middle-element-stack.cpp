// https://www.geeksforgeeks.org/delete-middle-element-stack/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    void deleteMid(stack<int>&s, int n)
    {
        deleteMid(n / 2, s);
    }

    void deleteMid(int n, stack<int>&s)
    {
        // std::cout << n << "\n";
        if (s.empty())
            return;
        if (n == 0) {
            s.pop();
            return;
        }
        int a = s.top();
        s.pop();
        deleteMid(n - 1, s);
        s.push(a);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;

    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;

        stack<int> myStack;

        for(int i=0; i<sizeOfStack; i++)
        {
            int x;
            cin>>x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack,myStack.size());
        while(!myStack.empty())
        {
            cout<<myStack.top()<<" ";
            myStack.pop();
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
