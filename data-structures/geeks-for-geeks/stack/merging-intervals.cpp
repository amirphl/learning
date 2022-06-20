// https://www.geeksforgeeks.org/merging-intervals/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(n)
    vector<vector<int>> overlappedInterval2(vector<vector<int>>& intervals) {
        // check for corner cases
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int mask[n] = {0};
        //  for(int i = 0; i < intervals.size(); i++) {
        //      cout << intervals[i][0] << " " << intervals[i][1] << endl;
        //  }
        overlappedIntervalRec(intervals, mask, 0, n - 1);
        for(int i = n - 1; i >= 0; i--) {
            // cout << mask[i] << " " << intervals[i][0] << " " << intervals[i][1] << endl;
            if (mask[i] == 1) {
                // assume that erase in O(1)
                intervals.erase(intervals.begin() + i);
            }
        }
        return intervals;
    }
    void overlappedIntervalRec(vector<vector<int>>& v, int mask[], int low, int high) {
        if (low == high) {
            return;
        }
        if (low + 1 == high) {
            if (mask[low] || mask[high]) {
                return;
            }
            if (v[high][0] <= v[low][1]) {
                mask[high] = 1;
                v[low][1] = max(v[low][1], v[high][1]);
            }
            return;
        }
        int mid = (low + high) / 2;
        overlappedIntervalRec(v, mask, low, mid);
        overlappedIntervalRec(v, mask, mid + 1, high);
        int j = mid;
        for(; j >= 0; j--) {
            if (mask[j] == 0) {
                break;
            }
        }
        for(int k = mid + 1; k <= high; k++) {
            if (mask[k] == 0) {
                if (v[k][0] > v[j][1]) {
                    break;
                } else {
                    mask[k] = 1;
                    v[j][1] = max(v[j][1], v[k][1]);
                }
            }
        }
    }

    // time: O(nlogn), memory: O(n)
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), greater<vector<int>>());
        stack<vector<int>> s;
        for(auto& it: intervals) {
            s.push(it);
        }
        intervals.clear();
        vector<int> curr = s.top();
        s.pop();
        while(!s.empty()) {
            vector<int> next = s.top();
            s.pop();
            // cout << next[0] << " " << next[1] << endl;
            if (curr[1] >= next[0]) {
                curr[1] = max(curr[1], next[1]);
            } else {
                intervals.push_back(curr);
                curr = next;
            }
        }
        intervals.push_back(curr);
        return intervals;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<vector<int>>Intervals(n);
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            Intervals[i].push_back(x);
            Intervals[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.overlappedInterval(Intervals);
        for(auto i: ans) {
            for(auto j: i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
