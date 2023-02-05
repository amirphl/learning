// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if ((uint64_t) n < (uint64_t) m * (uint64_t) k) {
            return -1;
        }
        int max_found = *max_element(arr.begin(), arr.end());
        if ((uint64_t) n == (uint64_t) m * (uint64_t) k) {
            return max_found;
        }
        int low = 1, high = max_found;
        int b;
        while(low <= high) {
            if (low == high) {
                b = find_b(arr, low, m, k);
                return m <= b ? low : -1;
            }
            if (low + 1 == high) {
                b = find_b(arr, low, m, k);
                if (m <= b) {
                    return low;
                }
                b = find_b(arr, high, m, k);
                if (m <= b) {
                    return high;
                }
                return -1;
            }

            int mid = (low + high) / 2;
            b = find_b(arr, mid, m, k);

            if (b < m) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return -1;
    }

    int find_b(vector<int>& arr, int& mid, int& m, int& k) {
        int n = arr.size();
        int b = 0;
        for(int i = 0, j = 0; i < n; i++) {
            if (arr[i] <= mid) {
                j++;
            } else {
                j = 0;
            }
            if (j == k) {
                b++;
                j = 0;
                if (b == m) {
                    break;
                }
            }
        }
        return b;
    }
};
