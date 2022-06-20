// https://www.geeksforgeeks.org/find-next-smaller-next-greater-array/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    // int arr[] = {5, 1, 9, 2, 5, 1, 7};
    int arr[] = {4, 8, 2, 1, 9, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int smaller[n];
    smaller[n - 1] = -1;
    stack<int> s;
    s.push(arr[n - 1]);
    int i = n - 2;
    while(i >= 0) {
        if (arr[i] > arr[i + 1]) {
            smaller[i] = arr[i + 1];
        } else {
            while(!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                smaller[i] = -1;
            } else {
                smaller[i] = s.top();
            }
        }
        s.push(arr[i]);
        i--;
    }

    stack<int> res;
    res.push(-1);
    stack<vector<int>> s2;
    s2.push({arr[n - 1], smaller[n - 1]}); // -1
    i = n - 2;
    while(i >= 0) {
        if (arr[i] < arr[i + 1]) {
            res.push(smaller[i + 1]);
        } else {
            while(!s2.empty() && s2.top()[0] <= arr[i]) {
                s2.pop();
            }
            if (s2.empty()) {
                res.push(-1);
            } else {
                res.push(s2.top()[1]);
            }
        }
        s2.push({arr[i], smaller[i]});
        i--;
    }

    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }

    cout << endl;
    return 0;
}
