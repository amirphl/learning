// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string s, string t) {
        int n = s.length();
        int arr[10];
        memset(arr, 0, sizeof(arr));

        int bulls = 0, cows = 0;
        for(int i = 0; i < n; i++) {
            if (s[i] == t[i]) {
                bulls++;
            } else {
                if (arr[s[i] - '0'] < 0) {
                    cows++;
                }
                arr[s[i] - '0']++;
                if (arr[t[i] - '0'] > 0) {
                    cows++;
                }
                arr[t[i] - '0']--;
            }
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
