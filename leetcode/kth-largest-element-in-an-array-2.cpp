// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        return find(nums, 0, n - 1, k);
    }

    int find(vector<int>& nums, int low, int high, int k) {
        // print(nums, low, high, k);

        if (low == high) {
            return nums[low];
        }
        if (low + 1 == high) {
            return k == 0 ? min(nums[low], nums[high]) : max(nums[low], nums[high]);
        }

        int pivot = low + (rand() % (high - low + 1));
        swap(nums, pivot, high);
        pivot = high;

        int i = low;
        int j = high - 1;

        while(i <= j) {
            if (nums[i] <= nums[pivot]) {
                i++;
            } else if (nums[pivot] <= nums[j]) {
                j--;
            } else {
                swap(nums, i, j);
                i++;
                j--;
            }
        }
        // cout << "___ ";
        // print(nums, low, high, k);

        swap(nums, pivot, i);
        pivot = i;

        // cout << "--- ";
        // print(nums, low, high, k);

        if (k < pivot - low) {
            return find(nums, low, pivot - 1, k);
        } else if (k == pivot - low) {
            return nums[pivot];
        } else {
            // cout << pivot << " " << high << " " << k << endl;
            return find(nums, pivot + 1, high, k - (pivot - low + 1));
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void print(vector<int>& nums, int low, int high, int k) {
        cout << k << " : ";
        while(low <= high) {
            cout << nums[low] << " ";
            low++;
        }
        cout << endl;
    }
};
