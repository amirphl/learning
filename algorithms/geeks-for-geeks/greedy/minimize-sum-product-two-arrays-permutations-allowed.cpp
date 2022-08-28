// https://www.geeksforgeeks.org/minimize-sum-product-two-arrays-permutations-allowed/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(1)
    long long int minValue(int a[], int b[], int n)
    {
        long long int res = 0;
        sort(a, a + n);
        sort(b, b + n);
        int i = 0;
        while(i < n) {
            res += a[i] * b[n - i - 1];
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
        int n, i;
        cin>>n;
        int a[n], b[n];
        for(i=0; i<n; i++)
            cin>>a[i];
        for(i=0; i<n; i++)
            cin>>b[i];
        Solution ob;
        cout<< ob.minValue(a, b, n) <<endl;
    }

    return 0;
}
// } Driver Code Ends
