// https://www.geeksforgeeks.org/find-subarray-with-given-sum/

// ***** There is a great idea to solve the problem in the link. Be sure to visit it! It's fantastic!

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    // time: O(n), memory: O(1)
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        vector<int> v;
        if (arr[0] == s) {
            v.push_back(1);
            v.push_back(1);
            return v;
        }
        for(int i = 1; i < n; i++) {
            // if (arr[i] == s) {
            //     v.push_back(i + 1);
            //     v.push_back(i + 1);
            //     return v;
            // }
            arr[i] += arr[i - 1];
            if (arr[i] == s) {
                v.push_back(1);
                v.push_back(i + 1);
                return v;
            }
            // cout << arr[i] << endl;
        }

        int i = 0;
        int j = 1;

        while (i < n && j < n) {
            if (i != j && (arr[j] - arr[i] == s || arr[i] - arr[j] == s) )
            {
                if (i < j) {
                    v.push_back(i + 2);
                    v.push_back(j + 1);
                } else {
                    v.push_back(j + 2);
                    v.push_back(i + 1);
                }
                return v;
            }
            else if (arr[j] - arr[i] < s)
                j++;
            else
                i++;
        }
        if (v.empty()) {
            v.push_back(-1);
        }
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
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);

        for(int i = 0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;

    }
    return 0;
}  // } Driver Code Ends
