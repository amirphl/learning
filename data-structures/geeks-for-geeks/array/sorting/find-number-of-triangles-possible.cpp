// https://www.geeksforgeeks.org/find-number-of-triangles-possible/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    // Function to count the number of possible triangles.
    // time: O(n*n*logn), memory: O(1)
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr + n);
        int count = 0;
        int i = 0;
        while(i < n) {
            int j = i + 1;
            while(j < n - 1) {
                int lower = max(arr[i] - arr[j], arr[j] - arr[i]);
                int upper = arr[i] + arr[j];
                // lower < c < upper
                int p = distance(arr, upper_bound(arr + j + 1, arr + n, lower));
                int q = distance(arr, lower_bound(arr + j + 1, arr + n, upper) - 1);
                // cout << arr[i] << " " << arr[j] << " _ " << lower << " " << upper << " _ " << p << " " << q << endl;
                count += q - p + 1;
                j++;
            }
            i++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends
