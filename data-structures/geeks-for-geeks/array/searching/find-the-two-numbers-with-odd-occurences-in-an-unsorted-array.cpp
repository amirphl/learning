// https://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    // time: O(n), memory: O(1)
    vector<int> twoOddNum(int arr[], int n)
    {
        int x = 0;
        int i = 0;
        while(i < n) {
            x ^= arr[i];
            i++;
        }
        int set_bit = x & (-x);
        int p = 0, q = 0;
        i = 0;
        while(i < n) {
            if ((set_bit & arr[i]) == set_bit) {
                p ^= arr[i];
            } else {
                q ^= arr[i];
            }
            i++;
        }
        if (p > q) {
            return {p, q};
        }
        return {q, p};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int Arr[N];
        for(int i = 0; i < N; i++)
            cin>>Arr[i];
        Solution ob;
        vector<int>ans=ob.twoOddNum(Arr,N);
        for(int i=0; i<ans.size(); i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
