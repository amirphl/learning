// https://www.geeksforgeeks.org/maximum-sum-increasing-order-elements-n-arrays/

//{ Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>arr[i][j];

        cout << maximumSum(n,m,arr)<<endl;

    }
    return 0;

}

// } Driver Code Ends

// time: O(n*m), memory: O(1)
int maximumSum(int n,int m, vector<vector<int>>& arr) {
    int sum = 0;
    int pre = INT_MAX;
    int i = n - 1;
    while(i >= 0) {
        int val = INT_MIN;
        int j = 0;
        while(j < m) {
            if (val < arr[i][j] && arr[i][j] < pre) {
                val = arr[i][j];
            }
            j++;
        }
        if (val != INT_MIN) {
            sum += val;
            pre = val;
        } else {
            return 0;
        }
        i--;
    }
    return sum;
}
