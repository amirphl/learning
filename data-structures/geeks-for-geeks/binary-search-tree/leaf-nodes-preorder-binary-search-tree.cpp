// https://www.geeksforgeeks.org/leaf-nodes-preorder-binary-search-tree/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // time: O(n), memory: O(n)
    vector<int> leafNodes(int arr[],int N) {
        vector<int> v;
        stack<vector<int>> bounds;
        int i = 0, low, high;
        bounds.push({INT_MIN, INT_MAX});
        while(i < N - 1) {
            low = bounds.top()[0];
            high = bounds.top()[1];
            bounds.pop();
            // cout << arr[i] << " " << low << " " << high << endl;
            // This step is very important!
            while(low > arr[i] || arr[i] > high) {
                low = bounds.top()[0];
                high = bounds.top()[1];
                bounds.pop();
            }
            if (low > arr[i + 1] || arr[i + 1] > high) {
                v.push_back(arr[i]);
            } else if (arr[i] < arr[i + 1]) {
                // cout << arr[i] << " _ " <<  high << endl;
                bounds.push({arr[i], high});
            } else {
                // cout << arr[i] << " _ " <<  high << endl;
                // cout << low << " _ " <<  arr[i] << endl;
                bounds.push({arr[i], high});
                bounds.push({low, arr[i]});
            }
            i++;
        }
        // cout << endl;
        v.push_back(arr[N - 1]);
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0; i<N; i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0; i<ans.size(); i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
