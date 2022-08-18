// https://www.geeksforgeeks.org/alternative-sorting/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(n)
    vector<int> alternateSort(int arr[], int N)
    {
        sort(arr, arr + N);
        vector<int> v(arr, arr + N);
        int i = 0, j = N - 1, k = 0;
        while(i <= j) {
            v[k] = arr[j];
            k++;
            if (i == j) {
                break;
            }
            v[k] = arr[i];
            k++;
            i++;
            j--;
        }
        return v;
    }

};


//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin>>n;
        int a[n];
        for(int i=0; i<n; ++i)
            cin>>a[i];


        Solution ob;
        vector<int> ans = ob.alternateSort(a, n);
        for(auto i:ans)
            cout << i << " ";
        cout << "\n";

    }
    return 0;
}


// } Driver Code Ends
