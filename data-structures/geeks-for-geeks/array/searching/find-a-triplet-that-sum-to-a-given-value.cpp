// https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    // time: O(n*n), memory: O(1)
    bool find3Numbers(int arr[], int n, int x)
    {
        sort(arr, arr + n);
        int i = 0;
        while(i < n) {
            int k = 0;
            int j = n - 1;
            while(k < j) {
                if (k == i) {
                    k++;
                    continue;
                }
                if (j == i) {
                    j--;
                    continue;
                }
                if (arr[k] + arr[j] + arr[i] == x) {
                    return true;
                }
                if (arr[k] + arr[j] + arr[i] < x) {
                    k++;
                } else {
                    j--;
                }
            }
            i++;
        }
        return false;
    }


};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,X;
        cin>>n>>X;
        int i,A[n];
        for(i=0; i<n; i++)
            cin>>A[i];
        Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends
