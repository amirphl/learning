// https://www.geeksforgeeks.org/next-smaller-element/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

public:
    // time: O(n), memory: O(n)
    vector<int> help_classmate(vector<int> arr, int n)
    {
        vector<int> v(n);
        v[n - 1] = -1;
        stack<int> s;
        s.push(arr[n - 1]);
        int i = n - 2;
        while(i >= 0) {
            if (arr[i] > arr[i + 1]) {
                v[i] = arr[i + 1];
            } else {
                while(!s.empty() && s.top() >= arr[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    v[i] = -1;
                } else {
                    v[i] = s.top();
                }
            }
            s.push(arr[i]);
            i--;
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution obj;
        vector<int> result = obj.help_classmate(array,n);
        for (int i = 0; i < n; ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

// } Driver Code Ends
