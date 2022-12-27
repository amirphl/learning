// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for(string& x: words) {
            freq[x]++;
        }

        sort(words.begin(), words.end(), [&, freq](const string& x, const string& y) {
            if (freq.at(x) == freq.at(y)) {
                return x < y;
            }

            return freq.at(x) > freq.at(y);
        });

        string prev = "";
        vector<string> res(k);
        int i = 0;

        for(string& x: words) {
            if (prev != x) {
                res[i] = x;
                i++;
                prev = x;
                k--;
            }
            if (k == 0) {
                break;
            }
        }

        return res;
    }

    vector<string> topKFrequent2(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for(string& x: words) {
            freq[x]++;
        }

        map<int, vector<string>> m;

        for(auto it = freq.begin(); it != freq.end(); it++) {
            m[it -> second].push_back(it -> first);
        }

        vector<string> res;

        for(auto it = m.rbegin(); it != m.rend(); it++) {
            int size = (it -> second).size();
            sort((it -> second).begin(), (it -> second).end());

            if (size <= k) {
                res.insert(res.end(), (it -> second).begin(), (it -> second).end());
                k -= size;
            } else {
                res.insert(res.end(), (it -> second).begin(), (it -> second).begin() + k);
                break;
            }
        }

        return res;
    }
};
