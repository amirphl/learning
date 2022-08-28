// https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(1)
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int i = 0;
        while(i < n && k > 0 && arr[i] < 0) {
            arr[i] *= -1;
            i++;
            k--;
        }
        int sum = 0;
        int j = 0;
        while(j < n) {
            sum += arr[j];
            j++;
        }
        if (k == 0) {
            return sum;
        }
        if (i == n) {
            if (k % 2 == 0) {
                return sum;
            } else {
                return sum - 2 * arr[n - 1];
            }
        }
        if (arr[i] == 0) {
            return sum;
        }
        if (k % 2 == 0) {
            return sum;
        }
        if (i > 0) {
            return sum - 2 * min(arr[i], arr[i - 1]);
        }
        return sum - 2 * arr[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        long long int a[n+5];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.maximizeSum(a, n, k)<<endl;
    }

    return 0;
}
// } Driver Code Ends
