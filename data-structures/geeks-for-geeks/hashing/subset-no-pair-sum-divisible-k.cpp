// https://www.geeksforgeeks.org/subset-no-pair-sum-divisible-k/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int subsetPairNotDivisibleByK(int arr[], int N, int K) ;

//  Driver code to test above methods
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n+5];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << subsetPairNotDivisibleByK(a, n, k) << "\n";
    }
    return 0;
}// } Driver Code Ends


int rem(int n, int k) {
    return (n > 0) ? n % k: k - (-n % k);
}

// time: O(n + k), memory: O(n + k)
int subsetPairNotDivisibleByK(int arr[], int n, int k) 
{
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++) {
        m[rem(arr[i], k)]++;
    }

    int res = 0;

    for(auto &it: m) {
        // cout << it.first << "    " << it.second << endl;
        // this is very important: it.first * 2 == k
        if (it.first == 0 || it.first * 2 == k) {
            res += 2;
        } else {
            // fuck! I'm actually modifying this map and it's undefined behaviour.
            // res += max({it.second, m[k - it.first]});
            if(m.find(k - it.first) != m.end()) {
                res += max({it.second, m.find(k - it.first) -> second});
            } else {
                res += 2 * it.second;
            }
        }
    }

    return res / 2;
}
