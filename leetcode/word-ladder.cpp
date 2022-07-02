// https://leetcode.com/problems/word-ladder/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Just a simple BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        if (beginWord == endWord) {
            return 0;
        }
        q.push({beginWord, 1});
        visited.insert(beginWord);
        while(!q.empty()) {
            string u = q.front().first;
            int lvl = q.front().second;
            q.pop();
            vector<string> ne;
            neighbors(u, wordList, ne);
            for (auto it: ne) {
                if (visited.find(it) == visited.end()) {
                    if (it == endWord) {
                        return lvl + 1;
                    }
                    visited.insert(it);
                    q.push({it, lvl + 1});
                }
            }
        }
        return 0;
    }

    void neighbors(string& u, vector<string>& wordList,vector<string>& ne) {
        ne = vector<string>();
        int n = u.length();
        for(auto& w: wordList) {
            if (u.length() == w.length()) {
                int i = 0, diff = 0;
                while(i < n && diff < 2) {
                    diff += u[i] == w[i] ? 0 : 1;
                    i++;
                }
                if (diff == 1) {
                    ne.push_back(w);
                }
            }
        }
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution sol;
    cout << sol.ladderLength(beginWord, endWord, wordList);
    cout << endl;
    return 0;
}
