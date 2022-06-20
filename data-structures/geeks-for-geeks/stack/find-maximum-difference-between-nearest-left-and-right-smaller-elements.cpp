// https://www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    /*You are required to complete this method */
    // time: O(n)
    // memory: O(n)
    int findMaxDiff2(int arr[], int n)
    {
        int RS[n];
        RS[n - 1] = -1;
        for(int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                RS[i] = i + 1;
            } else {
                int j = RS[i + 1];
                while(j < n && j != -1) {
                    if (arr[j] < arr[i]) {
                        break;
                    }
                    j = RS[j];
                }
                RS[i] = j;
            }
        }
        int LS[n];
        LS[0] = -1;
        for(int i = 1; i < n; i++) {
            if (arr[i - 1] < arr[i]) {
                LS[i] = i - 1;
            } else {
                int j = LS[i - 1];
                while(j >= 0) {
                    if (arr[j] < arr[i]) {
                        break;
                    }
                    j = LS[j];
                }
                LS[i] = j;
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << LS[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < n; i++) {
        //     cout << RS[i] << " ";
        // }
        // cout << endl;
        int res = INT_MIN;
        int u, v;
        for(int i = 0; i < n; i++) {
            u = (LS[i] == -1) ? 0 : arr[LS[i]];
            v = (RS[i] == -1) ? 0 : arr[RS[i]];
            res = max(res, abs(u - v));
        }
        return res;
    }

    // simpler solution - more efficient
    // good testcase:
    // 1
    // 85
    // 4 52 55 100 33 61 77 69 40 13 27 87 95 40 96 71 35 79 68 2 98 3 18 93 53 57 2 81 87 42 66 90 45 20 41 30 32 18 98 72 82 76 10 28 68 57 98 54 87 66 7 84 20 25 29 72 33 30 4 20 71 69 9 16 41 50 97 24 19 46 47 52 22 56 80 89 65 29 42 51 94 1 35 65 25
    // time: O(n), memory: O(n)
    int findMaxDiff(int arr[], int n)
    {
        int LS[n];
        LS[0] = 0;
        int i = 1;
        stack<int> s;
        s.push(arr[0]);
        while(i < n) {
            if (arr[i] > arr[i - 1]) {
                LS[i] = arr[i - 1];
            } else {
                while(!s.empty() && s.top() >= arr[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    LS[i] = 0;
                } else {
                    LS[i] = s.top();
                }
            }
            s.push(arr[i]);
            i++;
        }
        i = n - 2;
        s = stack<int>();
        s.push(arr[n - 1]);
        int res = LS[n - 1];
        while(i >= 0) {
            if (arr[i] > arr[i + 1]) {
                res = max(res, abs(LS[i] - arr[i + 1]));
            } else {
                while(!s.empty() && s.top() >= arr[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    res = max(res, LS[i]);
                } else {
                    res = max(res, abs(LS[i] - s.top()));
                }
            }
            s.push(arr[i]);
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
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.findMaxDiff(a,n)<<endl;
    }
    return 0;
}


// } Driver Code Ends
