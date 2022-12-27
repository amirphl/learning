// https://leetcode.com/problems/repeated-string-match/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = INT_MAX;
        int n = a.length(), m = b.length();

        if (n > m) {
            if (a.find(b) != std::string::npos) {
                return 1;
            }
            if ((a + a).find(b) != std::string::npos) {
                return 2;
            }

            return -1;
        }

        for(int i = 0; i < m; i++) {
            if (a[0] == b[i]) {
                int partial_res = 0;

                int j = i, k = 0;

                for(; j < m; j++, k++) {
                    // cout << j << " " << k << " " << k % n << endl;

                    if (a[k % n] != b[j]) {
                        break;
                    }
                }

                // cout << "_______\n";

                if (j == m) {
                    partial_res = ceil(k * 1.0 / n);
                    // cout << partial_res << endl;

                    j = i - 1, k = 0;

                    for(; j > -1; j--, k++) {
                        // cout << j << " " << k << " " << n - 1 - (k % n) << endl;

                        if (a[n - 1 - (k % n)] != b[j]) {
                            break;
                        }
                    }

                    if (j == -1) {
                        partial_res += ceil(k * 1.0 / n);
                        // cout << partial_res << endl;
                        count = min(count, partial_res);
                    }
                }

                // cout << "-------\n";
            }
        }

        if (count == INT_MAX) {
            return -1;
        }

        return count;
    }
};
