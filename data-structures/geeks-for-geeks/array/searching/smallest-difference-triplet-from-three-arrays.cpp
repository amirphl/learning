// https://www.geeksforgeeks.org/smallest-difference-triplet-from-three-arrays/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(nlogn), memory: O(1)
    vector<int> smallestDifferenceTriplet(int arr1[], int arr2[], int arr3[], int n)
    {
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        sort(arr3, arr3 + n);
        vector<int> res(3);
        int diff = INT_MAX;
        int sum = INT_MAX;
        int i = 0;
        while(i < n) {
            int j = distance(arr2, lower_bound(arr2, arr2 + n, arr1[i]));
            int k = distance(arr3, lower_bound(arr3, arr3 + n, arr1[i]));
            int p, q;
            if (j == 0) {
                p = arr2[0];
            } else if (j < n) {
                p = (arr2[j] - arr1[i] > arr1[i] - arr2[j - 1]) ? arr2[j - 1] : arr2[j];
            } else {
                p = arr2[n - 1];
            }
            if (k == 0) {
                q = arr3[0];
            } else if (k < n) {
                q = (arr3[k] - arr1[i] > arr1[i] - arr3[k - 1]) ? arr3[k - 1] : arr3[k];
            } else {
                q = arr3[n - 1];
            }
            int d = max({arr1[i], p, q}) - min({arr1[i], p, q});
            int s = arr1[i] + p + q;
            if (d < diff || (d == diff && s < sum)) {
                diff = d;
                sum = s;
                res[0] = arr1[i];
                res[1] = p;
                res[2] = q;
            }
            i++;
        }
        sort(res.begin(), res.end(), greater<int>());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n],c[n];
        for(int i=0; i<n; ++i)
            cin>>a[i];
        for(int i=0; i<n; ++i)
            cin>>b[i];
        for(int i=0; i<n; ++i)
            cin>>c[i];

        Solution ob;
        vector<int> ans=ob.smallestDifferenceTriplet(a,b,c,n);
        cout<< ans[0] <<" "<<ans[1]<<" "<<ans[2] << endl;
    }
    return 0;
}

// } Driver Code Ends
