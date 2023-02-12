// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int c = 0, n = num.size(), i = n;

        while((k || c) && i) {
            int b = c + (k % 10) + num[i - 1];
            k /= 10;
            c = 0;

            if (b > 9) {
                b -= 10;
                c = 1;
            }

            num[i - 1] = b;
            i--;
        }

        k += c;

        while(k) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }

        return num;
    }
};
