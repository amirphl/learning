// https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    // time: O(nlogn), memory: O(n)
    long long minCost(long long arr[], long long n) {
        if (n == 1) {
            return 0;
        }
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int i = 0;
        while(i < n) {
            pq.push(arr[i]);
            i++;
        }
        long long cost = 0;
        while(pq.size() > 1) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            cost += x + y;
            pq.push(x + y);
        }
        return cost;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
