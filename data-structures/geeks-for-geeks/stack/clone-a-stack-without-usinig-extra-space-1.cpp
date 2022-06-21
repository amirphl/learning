// https://practice.geeksforgeeks.org/problems/clone-a-stack-without-usinig-extra-space/1

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n*n), memory: O(1)
    void clonestack(stack<int> s, stack<int>& cloned)
    {
        while(!s.empty()) {
            int t = s.top();
            s.pop();
            int i = 0;
            while(!cloned.empty()) {
                s.push(cloned.top());
                cloned.pop();
                i++;
            }
            cloned.push(t);
            while(i > 0) {
                cloned.push(s.top());
                s.pop();
                i--;
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        stack<int> st;
        vector<int> copy;
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
            st.push(arr[i]);
            copy.push_back(arr[i]);
        }

        reverse(copy.begin(), copy.end());

        Solution ob;
        stack<int> cloned;
        ob.clonestack(st,cloned);
        vector<int> check;
        while(cloned.size())
        {
            check.push_back(cloned.top());
            cloned.pop();
        }

        int flag = 0;
        if(check!=copy)
            flag = 1;

        cout<<1-flag<<endl;
    }
    return 0;
}
// } Driver Code Ends
