// https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-that-a-given-value/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*n), memory: O(1)
    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long res = 0l;
        int i = 0;
        while(i < n) {
            int j = i + 1, k = n - 1, t = sum - arr[i];
            while(j < k) {
                if (arr[j] + arr[k] < t) {
                    res += k - j;
                    j++;
                } else {
                    k--;
                }
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
    cin >> t;
    while (t--)
    {
        int n;
        long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }




        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;


        cout << "\n";

    }
    return 0;
}


// } Driver Code Ends
