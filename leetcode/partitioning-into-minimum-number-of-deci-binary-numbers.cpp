// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/submissions/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n), memory: O(1)
    int minPartitions(string in) {
        int i = 0, n = in.length();
        int res = 48;
        while(i < n) {
            res = max(res, (int) in[i]);
            i++;
        }
        return res - 48;
    }
};

int main() {
    string in = "27346209830709182346";
    Solution sol;
    cout << sol.minPartitions(in);
    cout << endl;
    return 0;
}
