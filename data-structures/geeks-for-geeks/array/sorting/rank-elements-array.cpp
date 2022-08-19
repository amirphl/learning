// https://www.geeksforgeeks.org/rank-elements-array/

#include<bits/stdc++.h>

using namespace std;

// time: O(nlogn), memory: O(n)
int main() {
    int arr[] = {45, 67, 62, 69, 56, 32, 21, 46, 32, 54, 48, 42, 9, 40, 64, 55, 38, 20, 16, 63, 34, 33, 9, 13, 69, 45, 58, 68, 58, 47, 22, 2, 38, 38, 47, 65, 4, 11, 44, 41, 14, 24, 26, 68, 49, 4, 58, 7, 56, 67, 52, 61, 32, 26, 66, 62, 16, 38, 21, 6, 11, 45, 18, 8, 18, 6, 5, 61, 10, 44, 35, 15, 20, 57, 26, 48, 61, 20, 2, 52, 29, 28, 24, 26, 4, 64, 41, 55, 29, 26, 58, 50, 36, 22, 7, 42, 64, 39, 63, 5, 64, 20, 1, 10, 25, 30, 57, 8, 24, 53, 47, 59, 25, 60, 47, 51, 62, 12, 1, 69, 41, 34, 8, 49, 40, 18, 62, 44, 5, 38, 22, 61, 59, 1, 6, 20, 9, 62, 34, 40, 42, 69, 65, 36, 3, 66, 22, 47, 2, 61, 6, 32, 54, 61, 23, 7, 21, 51, 28, 16, 47, 56, 21, 35, 58, 27, 18, 65, 53, 23, 21, 7, 44, 62, 38, 26, 24, 1, 9, 19, 1, 56, 60, 42, 13, 50, 67, 48, 46, 2, 21, 55, 43, 33, 5, 31, 57, 44, 39, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    map<int, pair<int, double>> m;
    int i = 0;
    while(i < n) {
        if (m.find(arr[i]) == m.end()) {
            m[arr[i]] = {1, -1.0};
        } else {
            m[arr[i]].first++;
        }
        i++;
    }
    int k = 1;
    for(auto& it: m) {
        int num = it.first;
        int freq = it.second.first;
        double rank = ((freq + k - 1) * (freq + k) - (k - 1) * (k)) / (2.0 * freq);
        m[num].second = rank;
        k += freq;
    }
    i = 0;
    while(i < n) {
        cout << m[arr[i]].second << " ";
        i++;
    }
    cout << endl;
    return 0;
}
