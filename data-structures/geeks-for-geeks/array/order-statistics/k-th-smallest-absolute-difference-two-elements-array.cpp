// https://www.geeksforgeeks.org/k-th-smallest-absolute-difference-two-elements-array/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


struct hashFunction
{
    size_t operator()(const pair<int, int> &x) const
    {
        return x.first ^ x.second;
    }
};

// This code returns the kth ** largest ** absolute difference
int kthDiff2(int arr[], int n, int k)
{   for(int j = 1; j < 10; j++) {
    k = j;
    sort(arr, arr + n);
    priority_queue<vector<int>> pq;
    unordered_set<pair<int, int>, hashFunction> hashset;
    pq.push({abs(arr[0] - arr[n - 1]), 0, n - 1});
    vector<int> t;
    pair<int, int> u;
    int s, e;
    while(k > 1) {
        t = pq.top();
        pq.pop();
        s = t[1];
        e = t[2];
        u = {s + 1, e};
        if (hashset.find(u) == hashset.end()) {
            pq.push({abs(arr[s + 1] - arr[e]), s + 1, e});
        }
        u = {s, e - 1};
        if (hashset.find(u) == hashset.end()) {
            pq.push({abs(arr[s] - arr[e - 1]), s, e - 1});
        }
        k--;
    }
    cout << arr[pq.top()[1]] << " - " << arr[pq.top()[2]] << endl;}
    // return pq.top()[0];
    return 1;
}

int num_pairs_abs_diff_less_equal_m(int arr[], int n,int m) {
    int res = 0;
    int i = 0, j;
    while(i < n) {
        res += upper_bound(arr + i, arr + n, arr[i] + m) - arr - i - 1;
        i++;
    }
    return res;
}

// time: O(nlogn + log(max_elem - min_elem) * nlogn)
// memory: O(1)
int kthDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int max_diff = arr[n - 1] - arr[0];
    int min_diff = INT_MAX;
    int i = n - 1;
    while(i > 0) {
        min_diff = min(min_diff, arr[i] - arr[i - 1]);
        i--;
    }
    while(min_diff < max_diff) {
        int mid = (min_diff + max_diff) / 2;
        int x = num_pairs_abs_diff_less_equal_m(arr, n, mid);
        if (x < k) {
            min_diff = mid + 1;
        } else {
            max_diff = mid;
        }
    }
    return min_diff;
}
