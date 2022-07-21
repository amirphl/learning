// https://www.geeksforgeeks.org/count-ways-build-street-given-constraints/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    int n = 100;
    cin >> n;
    if (n == 1) {
        cout << 3 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 7 << endl;
        return 0;
    }
    int f[n + 1];
    int f_prime[n + 1];
    f[n] = 3;
    f[n - 1] = 7;
    f_prime[n] = 2;
    f_prime[n - 1] = 5;
    int i = n - 2;
    while(i >= 1) {
        f[i] = f[i + 1] + f[i + 2] + f_prime[i + 1] + f_prime[i + 2];
        f_prime[i] = f[i + 1] + f_prime[i + 1];
        i--;
    }
    cout << f[1] << endl;

    return 0;
}
