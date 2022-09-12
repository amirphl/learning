// https://www.geeksforgeeks.org/third-largest-element-array-distinct-elements/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(1)
    int thirdLargest(int arr[], int n)
    {
        if (n < 3) {
            return -1;
        }
        int a, b, c;
        if (arr[0] >= arr[1] && arr[0] >= arr[2]) {
            a = arr[0];
            b = max(arr[1], arr[2]);
            c = min(arr[1], arr[2]);
        } else if (arr[1] >= arr[0] && arr[1] >= arr[2]) {
            a = arr[1];
            b = max(arr[0], arr[2]);
            c = min(arr[0], arr[2]);
        } else if (arr[2] >= arr[0] && arr[2] >= arr[1]) {
            a = arr[2];
            b = max(arr[1], arr[0]);
            c = min(arr[1], arr[0]);
        }
        int i = 3;
        while(i < n) {
            if (arr[i] >= a) {
                c = b;
                b = a;
                a = arr[i];
            } else if (arr[i] >= b) {
                c = b;
                b = arr[i];
            } else if (arr[i] >= c) {
                c = arr[i];
            }
            i++;
        }
        return c;
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
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution obj;
        cout<<obj.thirdLargest(a,n)<<endl;
    }
}
// } Driver Code Ends
