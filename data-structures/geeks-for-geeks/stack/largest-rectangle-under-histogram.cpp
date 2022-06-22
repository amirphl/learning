// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    // time: O(n), memory: O(n)
    long long getMaxArea(long long arr[], int n)
    {
        long long* LS = new long long[n];
        long long* RS = new long long[n];
        stack<vector<long long>> s;
        s.push({arr[n - 1], n - 1});
        RS[n - 1] = n;
        long long i = n - 2;
        while(-1 < i) {
            if (arr[i] > arr[i + 1]) {
                RS[i] = i + 1;
            } else {
                while(!s.empty() && arr[i] <= s.top()[0]) {
                    s.pop();
                }
                if (s.empty()) {
                    RS[i] = n;
                } else {
                    RS[i] = s.top()[1];
                }
            }
            s.push({arr[i], i});
            i--;
        }
        s = stack<vector<long long>>();
        s.push({arr[0], 0});
        LS[0] = -1;
        i = 1;
        while(i < n) {
            if (arr[i - 1] < arr[i]) {
                LS[i] = i - 1;
            } else {
                while(!s.empty() && arr[i] <= s.top()[0]) {
                    s.pop();
                }
                if (s.empty()) {
                    LS[i] = -1;
                } else {
                    LS[i] = s.top()[1];
                }
            }
            s.push({arr[i], i});
            i++;
        }
        i = 0;
        long long res = 0;
        while(i < n) {
            // cout << LS[i] << ":" << RS[i] << " ";
            res = max(res, arr[i] * (RS[i] - 1 - LS[i] - 1 + 1));
            i++;
        }
        // cout << endl;
        delete(LS);
        delete(RS);
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        long long arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;

    }
    return 0;
}
// } Driver Code Ends
