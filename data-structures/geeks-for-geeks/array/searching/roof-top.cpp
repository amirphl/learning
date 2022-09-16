// https://www.geeksforgeeks.org/roof-top/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    //Function to find maximum number of consecutive steps
    //to gain an increase in altitude with each step.
    // time: O(n), memory: O(1)
    int maxStep(int arr[], int n)
    {
        int res = 0;
        int count = 0;
        int i = 0;
        while(i < n - 1) {
            if (arr[i] < arr[i + 1]) {
                count++;
            } else {
                res = max(res, count);
                count = 0;
            }
            i++;
        }
        res = max(res, count);
        return res;
    }
};

//{ Driver Code Starts.


int main() {
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
        cout << ob.maxStep(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
