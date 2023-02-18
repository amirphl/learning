// https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int arr[n];
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int repr = 0;
            for(int j = 0; j < words[i].length(); j++) {
                int pos = words[i][j] - 'a';
                repr |= (1 << pos);
            }
            arr[i] = repr;
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if (!(arr[i] & arr[j])) {
                    int cand = words[i].length() * words[j].length();
                    ans = max(ans, cand);
                }
            }
        }

        return ans;
    }
};
