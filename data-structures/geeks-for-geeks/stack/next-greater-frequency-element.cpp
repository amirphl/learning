// https://www.geeksforgeeks.org/next-greater-frequency-element/

// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(n)
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        unordered_map<int, int> m;
        int i = 0;
        while(i < n) {
            m[arr[i]]++;
            i++;
        }
        int freq[n];
        i = 0;
        while(i < n) {
            freq[i] = m[arr[i]];
            i++;
        }
        vector<int> v(n);
        stack<vector<int>> s;
        s.push({freq[n - 1], arr[n - 1]});
        v[n - 1] = -1;
        i = n - 2;
        while(i >= 0) {
            if (freq[i] < freq[i + 1]) {
                v[i] = arr[i + 1];
            } else {
                while(!s.empty() && s.top()[0] <= freq[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    v[i] = -1;
                } else {
                    v[i] = s.top()[1];
                }
            }
            s.push({freq[i], arr[i]});
            i--;
        }
        return v;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans) {
            cout<<x<<" ";
        }
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends
