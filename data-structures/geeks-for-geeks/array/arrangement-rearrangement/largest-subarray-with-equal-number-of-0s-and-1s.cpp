// https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution {
public:
    // time: O(n), memory: O(n)
    int maxLen(int arr[], int n)
    {
        unordered_map<int, vector<int>> m;
        m[0].push_back(-1);
        int s = 0;
        int i = 0;
        while(i < n) {
            s += (arr[i] == 1 ? 1 : -1);
            if (m[s].size() < 2) {
                m[s].push_back(i);
            } else {
                m[s][1] = i;
            }
            i++;
        }
        int res = 0;
        for(auto& x: m) {
            if (x.second.size() == 2) {
                // cout << x.first << " " << x.second[0] << " " << x.second[1] << endl;
                res = max(res, x.second[1] - x.second[0]);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
