// https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    int geekNumber2(int n) {
        int c = 2, prv_fact = 1;
        while(n > 1) {
            if (n % c == 0) {
                if (prv_fact == c) {
                    return 0;
                }
                prv_fact = c;
                n /= c;
            } else {
                c++;
            }
        }
        return 1;
    }

    // time: O(sqrt(n)), memory: O(1)
    int geekNumber(int n) {
        if (n % 2 == 0) {
            n = n / 2;
        }
        if (n == 1) {
            return 1;
        }
        if (n % 2 == 0) {
            return 0;
        }

        int i = 3, s = sqrt(n);
        while(i <= s) {
            if (n % i == 0) {
                n = n / i;
            }
            if (n == 1) {
                return 1;
            }
            if (n % i == 0) {
                return 0;
            }
            i += 2;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;

        Solution ob;
        if(ob.geekNumber(N))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends
