// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return findKthLargestRec(nums, 0, nums.size() - 1, k);
    }
    // time: O(n), memory: O(n)
    int findKthLargestRec(vector<int>& nums, int low, int high, int k) {
        if (low == high) {
            return nums[low];
        }
        if (low + 1 == high) {
            sort(nums.begin() + low, nums.begin() + high + 1);
            return k == 0 ? nums[low] : nums[high];
        }

        int pivot = low + (rand() % (high - low + 1));

        int t = nums[pivot];
        nums[pivot] = nums[high];
        nums[high] = t;
        pivot = high;

        int i = low;
        int j = high - 1;
        while(i < j) {
            if (nums[i] <= nums[pivot]) {
                i++;
            } else if (nums[j] >= nums[pivot]) {
                j--;
            } else {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }

        int idx;
        if (nums[i] <= nums[pivot]) {
            idx = i + 1;
        } else {
            idx = i;
        }

        int temp = nums[pivot];
        nums[pivot] = nums[idx];
        nums[idx] = temp;

        if (idx - low == k) {
            return nums[idx];
        } else if (idx - low < k) {
            return findKthLargestRec(nums, idx + 1, high, k - (idx - low) - 1);
        } else {
            return findKthLargestRec(nums, low, idx - 1, k);
        }
    }
};

int main() {
    vector<int> v({3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6});
    Solution sol;
    cout << sol.findKthLargest(v, 2) << endl;
    return 0;
}
