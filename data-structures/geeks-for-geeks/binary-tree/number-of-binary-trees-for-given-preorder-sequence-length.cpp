// https://www.geeksforgeeks.org/number-of-binary-trees-for-given-preorder-sequence-length/

#include<algorithm>
#include<iostream>
#include<cstring>

// time: O(n), memory: O(n)
int count(int dp[], int k) {
    if (dp[k] != -1)
        return dp[k];

    int sum = 0;
    for(int i = 0; i < k; i++) {
        sum += count(dp, i) * count(dp, k - i - 1);
    }

    dp[k] = sum;
    return sum;
}

int main() {
    int n = 10;
    int dp[n + 1] = {};
    memset(dp, -1, (n + 1) * sizeof(int));
    dp[0] = 1;
    count(dp, n);

    for(int i = 0; i < n + 1; i++) {
        std::cout << dp[i] << " ";
    }

    return 0;
}
