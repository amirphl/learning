// https://www.geeksforgeeks.org/find-elements-array-least-two-greater-elements/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(1)
    vector<int> findElements(int arr[], int n)
    {
        if (n == 1) {
            return {arr[0]};
        }
        if (n == 2) {
            return {arr[0], arr[1]};
        }
        int a = arr[0], b = arr[1], i_a = 0, i_b = 1;
        if (arr[0] < arr[1]) {
            a = arr[1];
            i_a = 1;
            b = arr[0];
            i_b = 0;
        }
        int i = 2, j = 0;
        while(i < n) {
            if (a <= arr[i]) {
                b = a;
                i_b = i_a;
                a = arr[i];
                i_a = i;
            } else if (b <= arr[i]) {
                b = arr[i];
                i_b = i;
            }
            i++;
        }
        vector<int> res(n - 2);
        i = 0, j = 0;
        while(i < n) {
            if (i != i_a && i != i_b) {
                res[j] = arr[i];
                j++;
            }
            i++;
        }
        sort(res.begin(), res.end());
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
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        vector <int> res = ob.findElements(a,n);

        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
}
// } Driver Code Ends
