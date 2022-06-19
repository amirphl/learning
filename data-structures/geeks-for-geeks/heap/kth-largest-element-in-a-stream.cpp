// https://www.geeksforgeeks.org/kth-largest-element-in-a-stream/

// method 2: using temp array: time O(n*k), memory O(k)
// method 3: using self balancing BST: time O(nlogk), memory: O(k)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogk), memory: O(k)
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        while(i < n) {
            if (i < k - 1) {
                pq.push(arr[i]);
                v.push_back(-1);
                i++;
                continue;
            }
            if (i == k - 1) {
                pq.push(arr[i]);
            }
            else if (pq.top() < arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
            v.push_back(pq.top());
            i++;
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
