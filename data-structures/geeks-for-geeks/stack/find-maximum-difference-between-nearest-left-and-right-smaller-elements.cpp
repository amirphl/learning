// https://www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    /*You are required to complete this method */
    // time: O(n)
    // memory: O(n)
    int findMaxDiff(int arr[], int n)
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
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends
