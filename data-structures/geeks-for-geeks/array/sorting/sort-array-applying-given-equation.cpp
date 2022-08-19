// https://www.geeksforgeeks.org/sort-array-applying-given-equation/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<long long> sortArray(vector<long long>arr, int n, long long A, long long B, long long C);

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int a, b, c;
        cin >> a >> b >> c;
        int n;
        cin >> n;
        vector<long long int>arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long int>ans = sortArray(arr, n, a, b, c);
        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends

long long f(long long x, int a, int b, int c) {
    return a * x * x + b * x + c;
}

// time: O(n), memory: O(1)
vector<long long> sortArray(vector<long long> arr, int n, long long a, long long b, long long c) {
    int pivot = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), -1 * b / (2 * a)));
    vector<long long> res(n);
    int i = pivot;
    int j = pivot - 1;
    int k = 0;
    bool up = a > 0;

    while(i < n || j >= 0) {
        // cout << i << " " << j << endl;
        if (i < n && j >= 0) {
            long long p = f(arr[i], a, b, c);
            long long q = f(arr[j], a, b, c);
            if (p < q) {
                if (up) {
                    res[k] = p;
                    i++;
                } else {
                    res[k] = q;
                    j--;
                }
            } else {
                if (up) {
                    res[k] = q;
                    j--;
                } else {
                    res[k] = p;
                    i++;
                }
            }
        } else if (i < n) {
            long long p = f(arr[i], a, b, c);
            res[k] = p;
            i++;
        } else if (j >= 0) {
            long long q = f(arr[j], a, b, c);
            res[k] = q;
            j--;
        }
        k++;
    }

    if (!up)
        reverse(res.begin(), res.end());

    return res;
}
