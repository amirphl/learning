// https://www.geeksforgeeks.org/rearrange-given-list-consists-alternating-minimum-maximum-elements/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // time: O(nlogn), memory: O(1)
    void Rearrange(int arr[], int n, int answer[])
    {
        sort(arr, arr + n);
        int i = 0, j = 0, k = n - 1;
        while(i < n) {
            answer[i] = arr[j];
            j++;
            i++;
            answer[i] = arr[k];
            k--;
            i++;
        }
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
        int i, a[n+5], answer[n+5]= {0};
        for(i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        ob.Rearrange(a, n, answer);

        for(i=0; i<n; i++)
            cout<<answer[i]<<" ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
