// https://www.geeksforgeeks.org/number-n-digits-non-decreasing-integers/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    int n = 5;
    int dp[n + 1][10];
    int i = 1;
    while(i < n + 1) {
        int j = 9;
        while(j >= 0) {
            if (i == 1) {
                dp[i][j] = 1;
            } else {
                int s = 0;
                int k = j;
                while(k < 10) {
                    s += dp[i - 1][k];
                    k++;
                }
                dp[i][j] = s;
            }
            j--;
        }
        i++;
    }
    i = 1;
    while(i < n + 1) {
        int j = 0, res = 0;
        while(j < 10) {
            res += dp[i][j];
            j++;
        }
        cout << i << " : " << res << endl;
        i++;
    }
    return 0;
}
