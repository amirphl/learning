// https://www.geeksforgeeks.org/find-pair-with-greatest-product-in-array/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    // time: O(n^1.5 + nlogn), memory: O(n)
    int findGreatest(int arr[], int n)
    {
        sort(arr, arr + n);
        unordered_map<int, int> m;
        int max = arr[n - 1];

        for(int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < i && arr[j] <= sqrt(arr[i]); j++) {
                if (arr[i] % arr[j] == 0) {
                    int elem = arr[i] / arr[j];

                    if (m.find(elem) != m.end() && m[elem] != i && m[elem] != j) {
                        return arr[i];
                    } 
                }
            }
        }

        return -1;
    }
};

// { Driver Code Starts.

// Drivers code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.findGreatest(a,n)<<endl;
    }
}
  // } Driver Code Ends
