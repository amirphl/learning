// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string src, string dst, vector<string>& wordList) {
        if (src == dst) {
            return 0;
        }

        wordList.push_back(src);
        int n = wordList.size();

        unordered_map<string, int> words;
        for(int i = 0; i < wordList.size(); i++) {
            words[wordList[i]] = i;
        }

        queue<int> q;
        q.push(n - 1);
        q.push(-1);
        words[wordList[n - 1]] = -1;

        int lvl = 1;

        while(q.size() > 1) {
            int i = q.front();
            q.pop();

            if (i == -1) {
                lvl++;
                q.push(i);
            } else {
                for(int j = 0; j < wordList[i].size(); j++) {
                    string neighbor = wordList[i];

                    for(int k = 'a'; k <= 'z'; k++) {
                        neighbor[j] = k;

                        if (neighbor == wordList[i]) {
                            continue;
                        }
                        if (words.find(neighbor) != words.end()) {
                            if (neighbor == dst) {
                                return lvl + 1;
                            }

                            if (words[neighbor] != -1) {
                                q.push(words[neighbor]);
                                words[neighbor] = -1;
                            }
                        }
                    }
                }
            }
        }

        return 0;
    }
};
