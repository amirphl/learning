// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int k = (n1 + n2) / 2;
        double frst = find_kth_element(nums1, nums2, 0, n1 - 1, 0, n2 - 1, k);
        if ((n1 + n2) % 2 == 1) {
            return frst;
        }
        double scnd = find_kth_element(nums1, nums2, 0, n1 - 1, 0, n2 - 1, k - 1);
        // cout << endl;
        return (frst + scnd) / 2.0;
    }

    int find_kth_element(vector<int>& nums1, vector<int>& nums2, int i1, int j1, int i2, int j2, int k) {
        // cout << i1 << " " << j1 << " " << i2 << " " << j2 << " " << k << endl;
        if (i1 > j1) {
            return nums2[i2 + k];
        }
        if (i2 > j2) {
            return nums1[i1 + k];
        }
        int mid = (j1 + i1) / 2;
        int idx = lower_bound(nums2.begin() + i2, nums2.begin() + j2 + 1, nums1[mid]) - nums2.begin();
        int n1 = mid - i1;
        int n2 = idx - i2;

        if (k == n1 + n2) {
            return nums1[mid];
        } else if (k < n1 + n2) {
            return find_kth_element(nums1, nums2, i1, mid - 1, i2, idx - 1, k);
        } else {
            return find_kth_element(nums1, nums2, mid + 1, j1, idx, j2, k - (n1 + n2 + 1));
        }
    }
};

int main() {
    vector<int> v1({3, 6, 7, 9, 12, 13, 14, 17, 19, 20});
    vector<int> v2({1, 2, 3, 5, 6, 7, 11, 12, 16, 19});
    Solution sol;
    cout << sol.findMedianSortedArrays(v1, v2);
    cout << endl;

    return 0;
}
