// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    // time: O(n), memory: O(n)
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        k = min(n, k);
        k = max(k, 1);
        vector<int> v(n - k + 1);
        deque<int> q;
        int i = k - 1;
        int cand = INT_MIN;
        while(-1 < i) {
            if (arr[i] >= cand) {
                cand = arr[i];
                q.push_back(i);
            }
            i--;
        }
        i = k;
        while(i < n) {
            v[i - k] = arr[q.back()];
            if (q.back() == i - k) {
                q.pop_back();
            }
            while(!q.empty() && arr[q.front()] < arr[i]) {
                q.pop_front();
            }
            q.push_front(i);
            i++;
        }
        v[i - k] = arr[q.back()];
        return v;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        Solution ob;
        vector <int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;

    }

    return 0;
}  // } Driver Code Ends
