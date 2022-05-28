// https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    // time: O(n), memory: O(1)
    int minJumps(int arr[], int n){
        int max_offset = arr[0];
        int max_i = max_offset;
        if (n == 1 && arr[0] == 0) {
            return 0;
        }
        if (n - 1 <= max_offset) {
            return 1;
        }
        int jumps = 1;
        int i = 1;
        while(i < min(max_i + 1, n)) {
            max_offset = max(max_offset, i + arr[i]);
            i++;
            if (i == min(max_i + 1, n)) {
                // cout << "__\n";
                jumps++;
                if (n - 1 <= max_offset || max_offset == max_i) {
                    break;
                }
                max_i = max_offset;
            }
            // cout << i - 1 << " " << max_i << " " << max_offset << " " << jumps << endl;
        }
        return (n - 1 <= max_offset) ? jumps : -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
