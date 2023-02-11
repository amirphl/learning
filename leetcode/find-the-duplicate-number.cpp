// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int ans;

        for(int i = 0; i < n; i++) {
            int j = arr[i];
            bool cont = 1;

            while(j > 0) {
                if (arr[j] < 0) {
                    ans = j;
                    cont = 0;
                    break;
                }
                int index = j;
                int k = arr[j];
                arr[j] = -arr[j];
                if (index == i) {
                    break;
                }
                j = k;
            }

            if (!cont) {
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                arr[i] = -arr[i];
            }
        }

        return ans;
    }
};
