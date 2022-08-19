// https://www.geeksforgeeks.org/maximize-elements-using-another-array/

#include<bits/stdc++.h>

using namespace std;

// time: O(nlogn + mlogm), memory: O(n + m)
int main() {
    int arr[] = {9, 49, 19, 40, 15, 39, 23, 34, 17, 26, 45, 19, 11, 44, 44, 23, 26, 25, 42, 17, 44, 20, 16, 42, 19, 9, 15, 46, 49, 14, 19, 46, 32, 48, 8, 22, 11, 4, 16, 3, 37, 6, 25, 45, 50, 25, 21, 10, 3, 24, 12, 24, 4, 18, 42, 42, 33, 11, 21, 1, 42, 50, 37, 35, 43, 19, 43, 40, 10, 27, 16, 26, 17, 46, 32, 7, 16, 17, 2, 29, 45, 8, 43, 43, 10, 9, 24, 11, 38, 39, 35, 33, 5, 34, 30, 9, 12, 29, 22, 49};
    int brr[] = {41, 20, 37, 31, 40, 48, 12, 19, 7, 10, 32, 12, 19, 28, 9, 31, 44, 1, 14, 18, 30, 5, 30, 34, 20, 39, 8, 8, 50, 9, 28, 43, 27, 30, 45, 20, 2, 32, 17, 38, 12, 29, 26, 16, 23, 14, 27, 11, 21, 47, 1, 42, 13, 11, 41, 17, 48, 5, 38, 39, 32, 34, 11, 30, 21, 35, 44, 49, 2, 13, 33, 19, 36, 8, 31, 24, 7, 13, 37, 48, 1, 21, 4, 11, 16, 20, 38, 49, 24, 8, 48, 22, 23, 22, 6, 16, 5, 12, 18, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(brr) / sizeof(brr[0]);
    int temp_arr[n];
    int temp_brr[m];
    memcpy(temp_arr, arr, sizeof(arr));
    memcpy(temp_brr, brr, sizeof(brr));
    sort(temp_arr, temp_arr + n);
    sort(temp_brr, temp_brr + m);
    unordered_set<int> s;
    int i = n - 1;
    int j = m - 1;
    int k = n - 1;
    while((i >= 0 || j >= 0) && k >= 0) {
        if (i >= 0 && s.find(temp_arr[i]) != s.end()) {
            i--;
            continue;
        }
        if (j >= 0 && s.find(temp_brr[j]) != s.end()) {
            j--;
            continue;
        }
        if (i >= 0 && j >= 0) {
            if (temp_arr[i] < temp_brr[j]) {
                cout << temp_brr[j] << " ";
                s.insert(temp_brr[j]);
                j--;
            } else {
                cout << temp_arr[i] << " ";
                s.insert(temp_arr[i]);
                i--;
            }
        } else if (i >= 0) {
            cout << temp_arr[i] << " ";
            s.insert(temp_arr[i]);
            i--;
        } else if (j >= 0) {
            cout << temp_brr[j] << " ";
            s.insert(temp_brr[j]);
            j--;
        } else {
        }
        k--;
    }
    cout << endl;
    j = 0;
    while(j < m) {
        if (s.find(brr[j]) != s.end()) {
            s.erase(brr[j]);
            cout << brr[j] << " ";
        }
        j++;
    }
    i = 0;
    while(i < n) {
        if (s.find(arr[i]) != s.end()) {
            s.erase(arr[i]);
            cout << arr[i] << " ";
        }
        i++;
    }

    return 0;
}
