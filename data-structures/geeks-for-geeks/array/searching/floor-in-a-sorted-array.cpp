// https://www.geeksforgeeks.org/floor-in-a-sorted-array/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    // time: O(logn), memory: O(1)
    int findFloor(vector<long long> v, long long n, long long x) {
        if (n == 1) {
            if (v[0] <= x) {
                return 0;
            }
            return -1;
        }
        long long i = 0;
        long long j = n - 1;
        while(i < j) {
            if (i + 1 == j) {
                if (v[j] <= x) {
                    return j;
                }
                if (v[i] <= x) {
                    return i;
                }
                return -1;
            }
            long long mid = (i + j) / 2;
            if (x < v[mid]) {
                j = mid - 1;
            } else if (x == v[mid]) {
                return mid;
            } else {
                i = mid;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for(long long i = 0; i<n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;

    }

    return 0;
}
// } Driver Code Ends
