// https://www.geeksforgeeks.org/count-strings-can-formed-using-b-c-given-constraints/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// time: O(1), memory: O(1)
long long int countStr(long long int i) {
    if (i == 1) {
        return 3;
    }
    if (i == 2) {
        return 8;
    }
    long long int res = 1 + (2 * i) + (3 * i * (i - 1) / 2) + (i * (i - 1) * (i - 2) / 2);
    return res;
}
