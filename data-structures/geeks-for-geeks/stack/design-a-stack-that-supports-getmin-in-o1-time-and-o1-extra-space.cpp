// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

// } Driver Code Ends
//User function Template for C++

int minimum = INT_MAX;

//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
    stack<int> s;
    s.push(INT_MAX);
    int i = 0;
    while(i < n) {
        if (minimum <= arr[i]) {
            s.push(arr[i]);
        } else {
            s.push(arr[i] - minimum);
            minimum = arr[i];
        }
        i++;
    }
    return s;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s)
{
    while(s.size() > 1) {
        cout << minimum << " ";
        if (minimum > s.top()) {
            minimum -= s.top();
        }
        s.pop();
    }
}

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        stack<int>mys=_push(arr,n);
        _getMinAtPop(mys);

        cout<<endl;

    }
    return 0;
}

// } Driver Code Ends
