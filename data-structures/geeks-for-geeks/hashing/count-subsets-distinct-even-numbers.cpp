// https://www.geeksforgeeks.org/count-subsets-distinct-even-numbers/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long countSubsets(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << countSubsets(a, n) << endl;
    }

    return 0;
}// } Driver Code Ends


// User function Template for C++

long long power(long long int x, long long int y) {
    long long int ans = 1;
    for(long long int i = 1; i <= y; i++) ans *= x;
    return ans;
}

long long countSubsets(int arr[], int n) {
    unsigned long long c = 0;

    unordered_set<int> s(arr, arr + n);

    for(auto &it: s) {
        if (it % 2 == 0) {
            c++;
        }
    }

    // unsigned long long res = pow(2, c) - 1;
    unsigned long long res = power(2, c) - 1;
    return res;
}
