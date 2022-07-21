// https://www.geeksforgeeks.org/ugly-numbers/

// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // long long noOfNumbers(long long N) {
    //     int fact[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    //     int m = sizeof(fact) / sizeof(fact[0]);
    //     vector<int> res;
    //     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    //     unordered_set<int> s;
    //     res.push_back(1);
    //     s.insert(1);
    //     int i = 0;
    //     while(i < m) {
    //         pq.push({fact[i] * res[0], i, 0});
    //         i++;
    //     }
    //     int curr = 1;
    //     while(curr <= N) {
    //         curr = pq.top()[0];
    //         int p = pq.top()[1];
    //         int q = pq.top()[2];
    //         pq.pop();
    //         if (s.find(curr) == s.end() && curr <= N) {
    //             cout << curr << " ";
    //             res.push_back(curr);
    //             s.insert(curr);
    //         }
    //         pq.push({fact[p] * res[q + 1], p, q + 1});
    //         // cout << curr << " " << p << " " << q << " " << fact[p] << " " << res[q + 1] << endl;
    //     }
    //     return N - s.size() + 1;
    // }

    // time: O(n), memory: O(1)
    long long noOfNumbers(long long N) {
        int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
        int m = sizeof(arr) / sizeof(arr[0]);
        int i = 1;
        long long count = 0;
        while(i <= N) {
            bool f = true;
            int j = 0;
            while(j < m) {
                if (i % arr[j] == 0) {
                    f = false;
                    break;
                }
                j++;
            }
            if (f) {
                count++;
            }
            i++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;

        cin>>N;

        Solution ob;
        cout << ob.noOfNumbers(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
