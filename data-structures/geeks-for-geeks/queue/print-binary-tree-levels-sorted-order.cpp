// https://www.geeksforgeeks.org/print-binary-tree-levels-sorted-order/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    // time: O(nlogn), memory: O(1)
    vector<vector<int>> binTreeSortedLevels(int arr[], int n)
    {
        vector<vector<int>> v((int) log2(n) + 1);
        int i = 0;
        int k = 1;
        int j = min(n, (int) pow(2, k) - 1);
        do {
            v[k - 1] = vector<int>(arr + i, arr + j);
            sort(v[k - 1].begin(), v[k - 1].end());
            k++;
            i = j;
            j = min(n, (int) pow(2, k) - 1);
        } while(i < j);
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;

        vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
        for (int i = 0; i < res.size(); ++i)
        {
            for (int j = 0; j < res[i].size(); ++j)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
}

// Contributed By: Pranay Bansal  // } Driver Code Ends
