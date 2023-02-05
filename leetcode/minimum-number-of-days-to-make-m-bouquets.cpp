// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    // TLE
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int total = m * k;

        if (total > n) {
            return -1;
        }

        if (total == n) {
            return *max_element(arr.begin(), arr.end());
        }

        if (total < n / 2) {
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

            for(int i = 0; i < n; i++) {
                pq.push({arr[i], i});
            }

            int elem, pos, c = 0;

            while(!pq.empty()) {
                elem = pq.top()[0];
                pos = pq.top()[1];
                pq.pop();
                arr[pos] = -1;
                c++;

                if (total <= c) {
                    int b = 0;
                    for(int i = 0, j = 0; i < n; i++) {
                        if (arr[i] == -1) {
                            j++;
                        } else {
                            j = 0;
                        }
                        if (j == k) {
                            b++;
                            j = 0;
                        }
                    }
                    if (b == m) {
                        return elem;
                    }
                }
            }

            return elem;
        } else {
            priority_queue<vector<int>> pq;
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq2;

            for(int i = 0; i < n; i++) {
                pq.push({arr[i], i});
            }

            int elem, pos, c = n;

            while(!pq.empty() && total < c) {
                elem = pq.top()[0];
                pos = pq.top()[1];
                pq.pop();
                arr[pos] = -elem;
                pq2.push({elem, pos});
                c--;
            }

            elem = pq.top()[0];

            while(1) {
                int b = 0;
                for(int i = 0, j = 0; i < n; i++) {
                    if (arr[i] > 0) {
                        j++;
                    } else {
                        j = 0;
                    }
                    if (j == k) {
                        b++;
                        j = 0;
                    }
                }
                if (b == m) {
                    return elem;
                }

                if (!pq2.empty()) {
                    elem = pq2.top()[0];
                    pos = pq2.top()[1];
                    pq2.pop();
                    arr[pos] = elem;
                } else {
                    break;
                }
            }

            return elem;
        }
    }
};
