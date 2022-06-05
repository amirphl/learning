// https://www.geeksforgeeks.org/minimum-possible-value-ai-aj-k-given-array-k/

#include<bits/stdc++.h>

using namespace std;

// time: O(nlogn), memory: O(n)
void print_pairs(int arr[], int n, int k) {
    unordered_map<int, int> freq;
    unordered_map<int, vector<vector<int>>> diff;
    int i = 0, d = INT_MAX, x, y;
    while(i < n) {
        freq[arr[i]]++;
        i++;
    }
    sort(arr, arr + n);
    i = 0;
    while(i < n) {
        auto lower = lower_bound(arr, arr + n, k - arr[i]);
        if (lower - arr == n) {
            x = INT_MAX;
            y = arr[n - 1];
        } else if (lower - arr == 0) {
            x = arr[0];
            y = INT_MIN;
        } else {
            x = *lower;
            y = *(lower - 1);
        }
        if (abs(arr[i] + x - k) <= d && x != INT_MAX) {
            // cout << arr[i] << " " << x << " " << d << endl;
            d = abs(arr[i] + x - k);
            if (x == arr[i]) {
                diff[d].push_back({arr[i], x, freq[x] - 1});
            } else {
                diff[d].push_back({arr[i], x, freq[x]});
            }
        }
        if (abs(arr[i] + y - k) <= d && y != INT_MIN) {
            // cout << arr[i] << " " << y << " " << d << endl;
            d = abs(arr[i] + y - k);
            if (y == arr[i]) {
                diff[d].push_back({arr[i], y, freq[y] - 1});
            } else {
                diff[d].push_back({arr[i], y, freq[y]});
            }
        }
        i++;
    }

    int min_diff = INT_MAX;
    for(auto& p: diff) {
        min_diff = min(min_diff, p.first);
    }

    for(auto& v: diff[min_diff]) {
        cout << v[0] << ", " << v[1] << ", freq = " << v[2] << ", diff = " << abs(v[0] + v[1] - k) << endl;
    }
}

int main () {
    int arr[] = {0, 4, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 7;
    print_pairs(arr, n, k);

    return 0;
}
