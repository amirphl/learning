// https://practice.geeksforgeeks.org/problems/card-rotation5834/1/

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // time: O(n*n), memory: O(n)
    vector<int> rotation(int n)
    {
        vector<int> v(n, -1);
        queue<int> q;
        int i = 0;
        int j = 1;
        int k = j;
        while(i < n) {
            while(0 < k && i < n) {
                q.push(i);
                i++;
                k--;
            }
            if (i < n) {
                v[i] = j;
            } else {
                break;
            }
            j++;
            i++;
            k = j;
        }
        while(q.size() > 1) {
            while(0 < k) {
                q.push(q.front());
                q.pop();
                k--;
            }
            v[q.front()] = j;
            q.pop();
            j++;
            k = j;
        }
        v[q.front()] = j;
        q.pop();
        return v;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int > ans;
        ans = obj.rotation(n);
        for(int i:ans)
            cout<< i << " ";
        cout << endl;

    }
    return 0;
}
// } Driver Code Ends
