// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    int n, m;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        this -> n = nums1.size();
        this -> m = nums2.size();

        if (n == 1 && m == 0) {
            return nums1[0];
        }
        if (n == 0 && m == 1) {
            return nums2[0];
        }

        if ((n + m) % 2 == 0) {
            int k = (n + m) / 2;
            return (kth(nums1, nums2, 0, n - 1, 0, m - 1, k - 1) + kth(nums1, nums2, 0, n - 1, 0, m - 1, k)) * 1.0 / 2;
        } else {
            return kth(nums1, nums2, 0, n - 1, 0, m - 1, (n + m) / 2);
        }
    }

    int kth(vector<int>& nums1, vector<int>& nums2, int p, int q, int u, int v, int k) {
        if (p > q && u > v) {
            cout << "panic\n";
            return INT_MAX;
        }
        if (p == q) {
            int pos = lower_bound(nums2.begin() + u, nums2.begin() + v + 1, nums1[p]) - nums2.begin();
            if (k < pos - u) {
                return nums2[u + k];
            } else if (k == pos - u) {
                return nums1[p];
            } else {
                return nums2[u + k - 1];
            }
        }
        if (p > q) {
            return nums2[u + k];
        }
        if (u == v) {
            int pos = lower_bound(nums1.begin() + p, nums1.begin() + q + 1, nums2[u]) - nums1.begin();
            if (k < pos - p) {
                return nums1[p + k];
            } else if (k == pos - p) {
                return nums2[u];
            } else {
                return nums1[p + k - 1];
            }
        }
        if (u > v) {
            return nums1[p + k];
        }

        int mid = (p + q) / 2;
        int pos = lower_bound(nums2.begin() + u, nums2.begin() + v + 1, nums1[mid]) - nums2.begin();
        int a = mid - p;
        int b = q - mid;
        int c = pos - u;
        int d = v - pos + 1;

        if (k < a + c) {
            return kth(nums1, nums2, p, mid - 1, u, pos - 1, k);
        } else if (k == a + c) {
            return nums1[mid];
        } else {
            return kth(nums1, nums2, mid + 1, q, pos, v, k - (a + c + 1));
        }
    }
};
