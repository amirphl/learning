// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    // This doesn't work!
    int findUnsortedSubarray(vector<int>& arr) {
        const int n = arr.size();

        if (n == 1) {
            return 0;
        }

        int i = 0;
        while(i < n - 1) {
            if (arr[i] > arr[i + 1]) {
                break;
            }
            i++;
        }

        int j = n - 1;
        while(j) {
            if (arr[j - 1] > arr[j]) {
                break;
            }
            j--;
        }

        if (i > j) {
            return 0;
        }

        int min = *min_element(arr.begin() + i, arr.begin() + j + 1);
        int max = *max_element(arr.begin() + i, arr.begin() + j + 1);

        const int lower = i, upper = j;
        // cout << lower << " " << upper << " " << min << " " << max << endl;

        i = 0;
        while(i < upper) {
            if (arr[i] > min) {
                break;
            }
            i++;
        }

        j = n - 1;
        while(lower < j) {
            if (arr[j] < max) {
                break;
            }
            j--;
        }

        // cout << i << " " << j << endl;

        return j - i + 1;
    }
};
