// https://www.geeksforgeeks.org/second-repeated-word-sequence/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // time: O(nlogn*max(si)), memory: O(1)
    string secFrequent(string arr[], int n)
    {
        sort(arr, arr + n);
        int most_rep = INT_MIN;
        int sec_most_rep = INT_MIN;
        int most_idx = -1;
        int sec_most_idx = -1;
        int i = 0, f = 1;
        while(i < n - 1) {
            if (i == n - 2 || arr[i] != arr[i + 1]) {
                if (most_rep <= f) {
                    sec_most_rep = most_rep;
                    sec_most_idx = most_idx;
                    most_rep = f;
                    most_idx = i;
                } else if (sec_most_rep <= f) {
                    sec_most_rep = f;
                    sec_most_idx = i;
                }
                f = 1;
            } else {
                f++;
            }
            i++;
        }
        return arr[sec_most_idx];
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
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
