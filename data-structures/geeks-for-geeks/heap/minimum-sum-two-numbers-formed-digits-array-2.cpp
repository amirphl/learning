// https://www.geeksforgeeks.org/minimum-sum-two-numbers-formed-digits-array-2/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    long long int minSum(int arr[], int n)
    {
        sort(arr, arr + n);
        long long sum_1 = 0;
        long long sum_2 = 0;
        int m = n;
        if (n % 2 == 1) {
            n--;
        }
        long long p;
        for(int i = 0; i < n; i += 2) {
            p = pow(10, (n - i) / 2 - 1);
            sum_1 += arr[i] * p;
            sum_2 += arr[i + 1] * p;
        }
        if (m % 2 == 0) {
            return sum_1 + sum_2;
        } else {
            if (sum_1 < sum_2) {
                sum_1 *= 10;
            } else {
                sum_2 *= 10;
            }
            return sum_2 + arr[m - 1] + sum_1;
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
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
