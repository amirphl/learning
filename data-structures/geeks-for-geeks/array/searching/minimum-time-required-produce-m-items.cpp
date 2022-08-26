// https://www.geeksforgeeks.org/minimum-time-required-produce-m-items/

#include<bits/stdc++.h>

using namespace std;

// time: O((m + n)logn), memory: O(n)
int main() {
    int m = 11256;
    int arr[] = {11, 7, 14, 5, 20, 9, 6, 17, 10, 2, 1, 4, 16, 15, 3, 8, 12, 18, 19, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int i = 0;
    while(i < n) {
        pq.push({arr[i], arr[i]});
        i++;
    }
    while(m > 0) {
        int curr = pq.top()[0];
        int rate = pq.top()[1];
        pq.pop();
        if (m == 1) {
            cout << curr << endl;
        }
        pq.push({curr + rate, rate});
        m--;
    }
    return 0;
}
