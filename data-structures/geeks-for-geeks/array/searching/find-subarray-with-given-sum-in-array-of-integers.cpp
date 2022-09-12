// https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/

// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(n), memory: O(n)
    int subArraySum(int arr[], int n, int sum)
    {
        int count = 0, x;
        unordered_map<int, int> m;
        if (arr[0] == sum) {
            count++;
        }
        m[arr[0]]++;
        for(int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
            if (arr[i] == sum) {
                count++;
            }
            x = arr[i] - sum;
            count += m[x];
            m[arr[i]]++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cin>>sum;
        Solution ob;
        cout<<ob.subArraySum(arr, n, sum);
        cout<<'\n';
    }
    return 0;
}  // } Driver Code Ends
