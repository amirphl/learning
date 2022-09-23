// https://www.geeksforgeeks.org/maximum-subarray-sum-modulo-m/

#include<bits/stdc++.h>

using namespace std;

int mod(int a, int n) {
    if (a > 0)
        return a % n;
    return n - (-a % n);
}

// This doesn't work!
// test cast:
// arr: { 3, 3, 9, 9, 5 };
// m = 12
// correct output: 11
// wrong output: 9
// time: O(n), memory: O(1)
int find(int arr[], int n, int m) {
    int cumm = arr[0];
    int res = mod(arr[0], m);
    int pre = arr[0];
    int i = 1;

    while(i < n) {
        cumm += arr[i];
        res = max({res, mod(cumm, m), mod(cumm - pre, m), mod(arr[i], m)});
        pre = (mod(pre, m) > mod(cumm, m)) ? cumm : pre;
        i++;
    }

    return res;
}

// geeks solution
// time: O(nlogn), memory: O(1)
// Return the maximum sum subarray mod m.
int maxSubarray(int arr[], int n, int m)
{
    int x, prefix = 0, maxim = 0;

    set<int> S;
    S.insert(0);

    // Traversing the array.
    for (int i = 0; i < n; i++)
    {
        // Finding prefix sum.
        prefix = (prefix + arr[i])%m;

        // Finding maximum of prefix sum.
        maxim = max(maxim, prefix);

        // Finding iterator pointing to the first
        // element that is not less than value
        // "prefix + 1", i.e., greater than or
        // equal to this value.
        auto it = S.lower_bound(prefix+1);

        if (it != S.end())
            maxim = max(maxim, prefix - (*it) + m );

        // Inserting prefix in the set.
        S.insert(prefix);
    }

    return maxim;
}

int main() {
    // int arr[] = {-7 ,-4 ,-7 ,-4 ,-2 ,-4 ,-4 ,-9 ,0 ,-9 ,-5 ,-3 ,10 ,5 ,5 ,-9 ,10 ,-9 ,-1 ,-6 ,3 ,4 ,-10 ,-3 ,-9 ,3 ,0 ,-5 ,-5 ,4 ,8 ,2 ,10 ,4 ,-10 ,-9 ,-9 ,3 ,-4 ,-4 ,0 ,0 ,1 ,6 ,4 ,9 ,1 ,9 ,3 ,0 ,1 ,-6 ,-7 ,-10 ,9 ,9 ,0 ,5 ,4 ,4 ,-4 ,0 ,1 ,-4 ,8 ,-10 ,9 ,10 ,-7 ,-7 ,10 ,-10 ,-8 ,1 ,0 ,9 ,3 ,-3 ,1 ,-6 ,-7 ,0 ,-1 ,-2 ,-9 ,8 ,-3 ,-1 ,3 ,-6 ,-4 ,2 ,5 ,7 ,10 ,2 ,10 ,7 ,3 ,10};
    int arr[] = { 3, 3, 9, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int a, b;
    for(int m = 1; m < 100; m++) {
        a = maxSubarray(arr, n, m);
        b = find(arr, n, m);
        if (a != b) {
            cout << a << " " << b << " " << m << endl;
        }
    }
    return 0;
}
