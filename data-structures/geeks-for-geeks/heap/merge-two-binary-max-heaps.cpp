// https://www.geeksforgeeks.org/merge-two-binary-max-heaps/

// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n + m), memory: O(n + m)
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // a.reserve(a.size() + distance(b.begin(), b.end()));
        a.insert(a.end(), b.begin(), b.end());
        for(int i = (n + m - 2) / 2; i >= 0; i--) {
            heapify(a, n + m, i);
        }
        // for(int i = 0; i < n + m; i++) {
        //     cout << a[i] << " ";
        // }
        return a;
    }
    void heapify(vector<int> &v, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && v[left] > v[largest]) {
            largest = left;
        }
        if (right < n && v[right] > v[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = v[i];
            v[i] = v[largest];
            v[largest] = temp;
            heapify(v, n, largest);
        }
    }
};

// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged) {
    if (arr1.size() + arr2.size() != merged.size()) {
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy) {
        return false;
    }
    for(int i = 1; i<merged.size(); i++) {
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
// } Driver Code Ends
