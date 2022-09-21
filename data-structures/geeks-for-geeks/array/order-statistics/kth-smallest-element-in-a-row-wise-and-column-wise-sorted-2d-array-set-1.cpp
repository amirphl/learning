// https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/

//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}

// } Driver Code Ends


// time: O((n + k)logn), memory: O(n)
int kthSmallest(int arr[MAX][MAX], int n, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int i = 0;
    while(i < n) {
        pq.push({arr[i][0], i, 0});
        i++;
    }
    i = 0;
    while(i < k - 1) {
        int row = pq.top()[1];
        int col = pq.top()[2];
        pq.pop();
        if (col + 1 < n) {
            pq.push({arr[row][col + 1], row, col + 1});
        }
        i++;
    }
    return pq.top()[0];
}
