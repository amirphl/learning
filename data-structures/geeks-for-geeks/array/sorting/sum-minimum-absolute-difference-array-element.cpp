// https://www.geeksforgeeks.org/sum-minimum-absolute-difference-array-element/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(nlogn), memory: O(1)
    int sumOfMinAbsDifferences(int arr[], int n)
    {
        if (n == 0) {
            return 0;
        }
        sort(arr, arr + n);
        int res = 0;
        int i = 0;
        while(i < n) {
            if (i == 0) {
                res += abs(arr[i] - arr[i + 1]);
            } else if (i < n - 1) {
                res += min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
            } else {
                res += abs(arr[i] - arr[i - 1]);
            }
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; ++i)
            cin>>a[i];
        Solution ob;
        cout<<ob.sumOfMinAbsDifferences(a,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
