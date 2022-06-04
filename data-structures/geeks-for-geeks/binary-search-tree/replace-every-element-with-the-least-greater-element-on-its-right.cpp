// https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/

// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
struct greater1 {
    bool operator()(const int& a,const int& b) const {
        return a <= b;
    }
};

class Solution {
public:
    // This solution doesn't work: Time Limit Exceeded
    // time: O(nlogn), memory: O(n)
    vector<int> findLeastGreater2(vector<int>& arr, int n) {
        vector<int> res;
        res.push_back(-1);
        int i = n - 2, temp;
        vector<int>::iterator idx;
        while(i > -1) {
            idx = lower_bound(arr.begin() + i + 1, arr.end(), arr[i], greater1());
            temp = *idx;
            if (idx == arr.end()) {
                temp = -1;
            }
            arr.insert(idx, arr[i]);
            arr.erase(arr.begin() + i);
            res.push_back(temp);
            // int j = i;
            // while(j < n) {
            //     cout << arr[j] << " ";
            //     j++;
            // }
            // cout << endl;
            i--;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // time: O(nlogn), memory: O(n)
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> res(n);
        res[n - 1] = -1;
        set<int, less_equal<int>> s;
        s.insert(arr[n - 1]);
        int i = n - 2;
        while(i > -1) {
            auto it = s.lower_bound(arr[i]);
            res[i] = (it == s.end()) ? -1 : *it;
            s.insert(arr[i]);
            i--;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i = 0 ; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findLeastGreater(arr, n);
        for(auto it : ans) {
            cout << it << " ";
        }
        cout <<endl;
    }
    return 0;
}
// } Driver Code Ends
