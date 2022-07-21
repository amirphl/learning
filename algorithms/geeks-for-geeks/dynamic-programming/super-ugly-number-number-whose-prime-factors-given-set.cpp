// https://www.geeksforgeeks.org/super-ugly-number-number-whose-prime-factors-given-set/

#include<bits/stdc++.h>

using namespace std;

int main() {
    int primes[] = {2, 3, 5, 11, 17};
    int m = sizeof(primes) / sizeof(primes[0]);
    int n;
    cin >> n;
    vector<int> res;
    res.push_back(1);
    // cout << "0:1 ";
    cout << "1 ";
    unordered_set<int> s;
    s.insert(1);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int i = 0;
    while(i < m) {
        pq.push({primes[i] * res[0], i, 0});
        i++;
    }
    i = 1;
    while(i < n) {
        int num = pq.top()[0];
        int p = pq.top()[1];
        int q = pq.top()[2];
        pq.pop();
        if (s.find(num) == s.end()) {
            res.push_back(num);
            s.insert(num);
            // cout << i << ":" << num << " ";
            cout << num << " ";
            i++;
        }
        pq.push({primes[p] * res[q + 1], p, q + 1});
    }
    cout << endl;

    return 0;
}
