// https://www.geeksforgeeks.org/find-four-elements-a-b-c-and-d-in-an-array-such-that-ab-cd/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(n*n), memory: O(n*n)
    int findPairs(long long arr[], long long n)
    {
        unordered_map<int, pair<int, int>> m;
        int i = 0;
        while(i < n) {
            int j = i + 1;
            while(j < n) {
                int x = arr[i] + arr[j];
                if (m.find(x) == m.end()) {
                    m[x] = {arr[i], arr[j]};
                } else {
                    return 1;
                }
                j++;
            }
            i++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;

    cin >> t;

    while(t--) {
        long long n;
        cin >> n;
        long long a[n];
        for(long long i = 0; i<n; i++) {
            cin >> a[i];
            // um[a[i]]++;
        }
        Solution ob;
        cout << ob.findPairs(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
