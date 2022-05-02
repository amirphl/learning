// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    // time: O(n) memory: O(n)
    int maxLen(vector<int> &arr, int n)
    {   
        int res = 0;
        unordered_map<int, int> m;
        int cum[n];
        cum[0] = arr[0];
        m[cum[0]] = 0;

        for(int i = 1; i < n; i++) {
            cum[i] = cum[i - 1] + arr[i];

            if(m.find(cum[i]) == m.end()) {
                m[cum[i]] = i;
            } else if (res < i - m[cum[i]]) {
                res = i - m[cum[i]];
            }

            if(cum[i] == 0 && res < i + 1) {
                res = i + 1;
            }
        }

        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
