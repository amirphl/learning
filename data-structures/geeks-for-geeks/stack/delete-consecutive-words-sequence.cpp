// https://www.geeksforgeeks.org/delete-consecutive-words-sequence/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    int removeConsecutiveSame(vector<string > v)
    {
        stack<string> s;
        for(auto& it: v) {
            if (!s.empty() && s.top() == it) {
                s.pop();
            } else {
                s.push(it);
            }
        }
        return s.size();
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
        string s;
        vector<string> v;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        Solution ob;
        cout<< ob.removeConsecutiveSame(v) <<endl;
    }




    return 0;
}  // } Driver Code Ends
