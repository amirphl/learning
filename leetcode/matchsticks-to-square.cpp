// https://leetcode.com/problems/matchsticks-to-square/

class Solution {
public:
    int max_len;

    bool makesquare(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());

        int total = 0;
        for(int i = 0; i < arr.size(); i++) {
            total += arr[i];
        }
        if (total % 4 != 0) {
            return false;
        }

        int max_len = total / 4;
        this -> max_len = max_len;
        if (arr[0] > max_len) {
            return false;
        }

        int sides[4];
        memset(sides, 0, sizeof(sides));

        return func(arr, sides, 0);
    }

    bool func(vector<int>& arr, int sides[4], int pos) {
        if (pos == arr.size() - 1) {
            for(int i = 0; i < 4; i++) {
                if (sides[i] + arr[pos] == max_len) {
                    sides[i] += arr[pos];
                    for(int j = 0; j < 4; j++) {
                        if (sides[i] != max_len) {
                            sides[i] -= arr[pos];
                            return false;
                        }
                    }
                    sides[i] -= arr[pos];
                    return true;
                }
            }
            return false;
        }

        for(int i = 0; i < 4; i++) {
            int j = i + 1;

            while(j < 4) {
                if (sides[i] == sides[j]) {
                    break;
                }

                j++;
            }

            if (j != 4) {
                continue;
            }

            if (sides[i] + arr[pos] <= max_len) {
                sides[i] += arr[pos];
                bool ok = func(arr, sides, pos + 1);
                sides[i] -= arr[pos];
                if (ok) {
                    return true;
                }
            }
        }

        return false;
    }
};
